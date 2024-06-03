#include "server.h"

void Server::incomingConnection(qintptr handle)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotDeleteLater);

    qDebug() << "CONNECT. Client was connected" << handle;
}

void Server::slotDeleteLater()
{
    socket = (QTcpSocket*)sender();
    qDebug() << "DISCONNECT. Client was diconnected " << socket;
    sockets.erase(std::remove(sockets.begin(), sockets.end(), socket), sockets.end());
    socket->deleteLater();

}

void Server::slotReadyRead()
{
    // open socket for sender and create input stream
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    // if status == ok - read
    if (in.status() == QDataStream::Ok) {
        qDebug() << "\n\tINCOMING STREAM. START READ";
        while (true) {
            // check nextBlockSize - read if 0
            if (nextBlockSize == 0) {
                // if <2 - no size of data
                if (socket->bytesAvailable() < 2) {
                    qDebug() << "FEW DATA. CANT YET READ";
                    break;
                }
                // if >= 2 we have size of data - read it
                in >> nextBlockSize;
            }
            // read data if we have all size of data
            qDebug("DATA ENOUGH. READ DATA");
            if (socket->bytesAvailable() < nextBlockSize) break;
            QString str;
            in >> str;
            nextBlockSize = 0;

            AcceptJSONMess(str);
        }
    }
    else
        qDebug() << "READ ERROR! CANT OPEN DATA STREAM" ;
}

Server::Server()
{
    // OPEN DB
    qDebug() << "\tTRY TO OPEN DATABASE";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ryan/Documents/Messenger/Messenger/Messenger.db");
    if (db.open()) qDebug() << "DB was opened! " << db.databaseName();
    else qDebug() << "Error opening DB! " << db.lastError().databaseText();

    // START LISTENING SOCKETS
    if(this->listen(QHostAddress::Any, 27015))
        qDebug() << "\nOPEN SOCKET TO START LISTENING!";
    else
        qDebug() << "\nERROR OPEN SOCKET TO START LISTENING!";
    nextBlockSize = 0;
}

void Server::GetAuthUserInfo(QJsonObject jUserInfo)
{
    // READ USER INFO AND ADD TO DB
    QJsonObject jResObj;
    jResObj.insert("type", "auth_response");

    QJsonValue value = jUserInfo.value("user");

    if (value["type"] == "signup") {
        if (ValidateLogin(jUserInfo)) {
            qDebug() << "SUCCESS VALIDATE LOGIN. REGISTRATE USER";
            RegistrateAccount(jUserInfo["user"]);
            jResObj.insert("value", true);
        }
        else {
            qDebug() << "ERROR VALIDATE LOGIN";
            jResObj.insert("value", false);
        }
    }
    else {
        QSqlQuery query;
        query.prepare("SELECT username, passwordhash FROM user WHERE username == :username");
        query.bindValue(":username", value["login"].toString());
        query.exec();
        QSqlRecord rec = query.record();
        query.next();
        if (query.value(rec.indexOf("passwordhash")).toString() == value["pass"].toString()) {
            qDebug() << "SUCCESS LOGIN " << value["login"].toString();
            jResObj.insert("value", true);
        }
        else {
            qDebug() << "ERROR LOGIN " << value["login"].toString();
            jResObj.insert("value", false);
        }
    }
    if (jResObj["value"].toBool()) {
        if (sockets.find(value["login"].toString()) == sockets.end()) {
            sockets.insert(value["login"].toString(), socket);
        }
    }
    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

bool Server::ValidateLogin(QJsonValue user)
{
    QSqlQuery query;
    query.prepare("SELECT username, passwordhash FROM user WHERE username == :username");
    query.bindValue(":username", user["login"].toString());
    query.exec();
    if (query.next()) return false;
    else return true;
}

void Server::RegistrateAccount(QJsonValue user)
{
    QSqlQuery query;
    query.prepare("INSERT INTO User (username, passwordhash) VALUES (:login, :pass)");
    query.bindValue(":login", user["login"].toString());
    query.bindValue(":pass", user["pass"].toString());
    if (query.exec()) qDebug() << "Sign up is successful!";
    else qDebug() << "Sign up error!";
}

void Server::AcceptReqForChats(QString senderUsername)
{
    QJsonObject jResObj;
    jResObj.insert("type", "chats_response");

    // GET CHATS WHERE senderUser CONSISTS
    QSqlQuery getChats;
    getChats.prepare("SELECT chat.pk_chat, chatname, isPersonal FROM chat, ChatParticipant JOIN User ON ChatParticipant.pk_user == user.pk_user WHERE ChatParticipant.pk_chat == chat.pk_chat AND user.username == :username");
    getChats.bindValue(":username", senderUsername);
    getChats.exec();

    QJsonArray jArray;
    QSqlRecord rec = getChats.record();
    while (getChats.next()){
        QJsonObject temp;
        temp.insert("chat_type", getChats.value(rec.indexOf("isPersonal")).toBool());
        temp.insert("chatname", getChats.value(rec.indexOf("chatname")).toString());
        temp.insert("pk_chat", getChats.value(rec.indexOf("pk_chat")).toInt());
        jArray.push_back(temp);
    }

    jResObj.insert("value", jArray);
    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

void Server::AcceptReqForDialogs(int chatID)
{
    QSqlQuery query;
    query.prepare("SELECT DISTINCT messtext, timeotpr, username FROM user, messages JOIN chat ON messages.pk_chat = :chatId WHERE messages.pk_user == user.pk_user ORDER BY timeotpr ASC");
    query.bindValue(":chatId", chatID);
    if (query.exec()) qDebug() << "Successful get messages from DB!";
    else {
        qDebug() << "Error get messages from DB";
        return;
    }

    QSqlRecord rec = query.record();
    QJsonArray jArray;
    while(query.next()) {
        jArray.push_back(query.value(rec.indexOf("timeotpr")).toString() + " " + query.value(rec.indexOf("username")).toString() + ": " + query.value(rec.indexOf("messtext")).toString());
    }
    QJsonObject jResObj;
    jResObj.insert("type", "dialog_response");
    jResObj.insert("value", jArray);

    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

void Server::AcceptReqForFinduser(QJsonValue searchUser)
{
    QSqlQuery query;
    query.prepare("SELECT pk_user, username FROM user WHERE user.username LIKE :name AND user.username <> :sender");
    query.bindValue(":name", "%" + searchUser["username"].toString() + "%");
    query.bindValue(":sender", searchUser["sender"].toString());
    query.exec();
    QSqlRecord rec = query.record();
    QJsonArray jArray;
    while (query.next()){
        QSqlQuery inchat;
        inchat.prepare("SELECT * FROM ChatParticipant WHERE ChatParticipant.pk_user == :userID AND ChatParticipant.pk_chat == :chatID");
        inchat.bindValue(":userID", query.value(rec.indexOf("pk_user")).toInt());
        inchat.bindValue(":chatID", searchUser["pk_chat"].toInt());
        inchat.exec();
        qDebug() << query.value(rec.indexOf("pk_user")).toString() << " " << searchUser["pk_chat"];
        if (!inchat.next()) jArray.push_back(query.value(rec.indexOf("username")).toString());
    }
    QJsonObject jResObj;
    if (searchUser["action"] == "adduser") jResObj.insert("type", "findusertoadd_response");
    else jResObj.insert("type", "finduser_response");
    jResObj.insert("value", jArray);

    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

void Server::AcceptMessages(QJsonValue message)
{
    QSqlQuery query_chatp, query_mess;
    query_chatp.prepare("SELECT ChatParticipant.rowid, ChatParticipant.pk_chat, ChatParticipant.pk_user FROM User, ChatParticipant, chat WHERE user.username == :username AND ChatParticipant.pk_user == user.pk_user AND ChatParticipant.pk_chat == chat.pk_chat AND chat.pk_chat == :chatID");
    query_chatp.bindValue(":chatID", message["pk_chat"].toInt());
    query_chatp.bindValue(":username", message["sender"].toString());
    query_chatp.exec();

    query_mess.prepare("INSERT INTO messages (messtext, timeotpr, pk_chat, pk_user) VALUES (:message, CURRENT_TIMESTAMP, :chat, :user)");
    query_mess.bindValue(":message", message["text"].toString());
    QSqlRecord rec = query_chatp.record();

    query_chatp.next();
    query_mess.bindValue(":chat", query_chatp.value(rec.indexOf("pk_chat")).toInt());
    query_mess.bindValue(":user", query_chatp.value(rec.indexOf("pk_user")).toInt());

    if (query_mess.exec()) {
        int id = query_chatp.lastInsertId().toInt();
        QSqlQuery getmess;
        getmess.prepare("SELECT messtext, timeotpr, username FROM messages JOIN user ON messages.pk_user == user.pk_user WHERE messages.rowid == :id");
        getmess.bindValue(":id", id);
        getmess.exec();

        QSqlRecord mess = getmess.record();
        getmess.next();
        QJsonObject temp = message.toObject();
        temp["text"] = getmess.value(mess.indexOf("timeotpr")).toString() + " " + getmess.value(mess.indexOf("username")).toString() + ": " + getmess.value(mess.indexOf("messtext")).toString();
        qDebug() << "Message is saved in DB!";
        SendSignalToUpdateDialog(temp);
    }
    else qDebug() << "Error save message in DB! " << query_mess.lastError() << " " << query_mess.lastQuery();

    //AcceptReqForDialogs(message["pk_chat"].toInt());
}

void Server::AcceptReqForCreateChat(QJsonValue chatinfo)
{
    QSqlQuery create_chat;
    QJsonObject jResObj, temp;
    QSqlQuery same_chat;
    same_chat.prepare("SELECT pk_chat FROM chat WHERE chat.chatname == :chatname1 OR chat.chatname == :chatname2");
    same_chat.bindValue(":chatname1", chatinfo["sender"].toString() + " " + chatinfo["chatname"].toString());
    same_chat.bindValue(":chatname2", chatinfo["chatname"].toString() + " " + chatinfo["sender"].toString());
    same_chat.exec();
    if (chatinfo["pk_chat"] == -1) {
        if (same_chat.next()) {
            QSqlRecord rec =same_chat.record();
            temp = chatinfo.toObject();
            temp["pk_chat"] = same_chat.value(rec.indexOf("pk_chat")).toInt();
            jResObj.insert("type", "createchat_response");
            jResObj.insert("value", temp);
            QJsonDocument jReqDoc = QJsonDocument{jResObj};
            QString jReqStr = QString(jReqDoc.toJson());
            SendToClient(jReqStr);
            return;
        }
        create_chat.prepare("INSERT INTO chat (chatname, isPersonal) VALUES (:chatname, :isPersonal)");
        create_chat.bindValue(":chatname", chatinfo["sender"].toString() + " " + chatinfo["chatname"].toString());
        create_chat.bindValue(":isPersonal", true);
        if (create_chat.exec()) qDebug() << "Chat "<< chatinfo["chatname"].toString() <<" was created successful!";
        else qDebug() << "Error creating chat " << chatinfo["chatname"].toString() << "!";

        temp = chatinfo.toObject();
        qDebug() << "Chat id " << create_chat.lastInsertId().toInt();
        temp["pk_chat"] = create_chat.lastInsertId().toInt();
        jResObj.insert("type", "createchat_response");
        jResObj.insert("value", temp);
    }
    else {
        jResObj.insert("type", "createchat_response");
        jResObj.insert("value", chatinfo);

        QJsonDocument jReqDoc = QJsonDocument{jResObj};
        QString jReqStr = QString(jReqDoc.toJson());
        SendToClient(jReqStr);
        return;
    }

    // TODO: Bring part below to separate func
    QSqlQuery create_chatp, users, chats;
    users.prepare("SELECT pk_user FROM User WHERE user.username == :sender OR user.username == :reciver");
    users.bindValue(":sender", chatinfo["sender"].toString());
    users.bindValue(":reciver", chatinfo["chatname"].toString());
    users.exec();

    chats.prepare("SELECT pk_chat FROM chat WHERE chat.pk_chat == :chatID");
    chats.bindValue(":chatID", temp["pk_chat"].toInt());
    chats.exec();

    QSqlRecord rec = users.record(), rec2 = chats.record();
    chats.next();
    while (users.next()){
        create_chatp.prepare("INSERT INTO ChatParticipant (pk_user, pk_chat) VALUES (:user, :chat)");
        create_chatp.bindValue(":user", users.value(rec.indexOf("pk_user")).toInt());
        create_chatp.bindValue(":chat", chats.value(rec2.indexOf("pk_chat")).toInt());

        if (create_chatp.exec()) qDebug() << "Chat participant " << users.value(rec.indexOf("pk_user")).toInt() << "was created!";
        else qDebug() << "Error create CP " << users.value(rec.indexOf("pk_user")).toInt() << "!";
     qDebug() << create_chatp.lastError();
    }

    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

void Server::AcceptReqForCreateGroupChat(QJsonValue chatinfo)
{
    QJsonObject jResObj, temp;
    jResObj.insert("type", "creategroupchat_response");
    QSqlQuery same_chat;
    same_chat.prepare("SELECT pk_chat FROM chat WHERE chat.chatname == :chatname");
    same_chat.bindValue(":chatname", chatinfo["chatname"].toString() + " " + chatinfo["sender"].toString());
    same_chat.exec();
    if (same_chat.next()) {
        temp.insert("return", -1);
    }
    else {
    QSqlQuery create_chat;
    create_chat.prepare("INSERT INTO chat (chatname, isPersonal) VALUES (:chatname, :isPersonal)");
    create_chat.bindValue(":chatname", chatinfo["chatname"].toString());
    create_chat.bindValue(":isPersonal", false);
    create_chat.exec();

    int chatID = create_chat.lastInsertId().toInt();

    QSqlQuery create_chatp, users;
    users.prepare("SELECT pk_user FROM User WHERE user.username == :sender");
    users.bindValue(":sender", chatinfo["sender"].toString());
    users.exec();

    QSqlRecord rec = users.record();
    users.next();
    create_chatp.prepare("INSERT INTO ChatParticipant (pk_user, pk_chat) VALUES (:user, :chat)");
    create_chatp.bindValue(":user", users.value(rec.indexOf("pk_user")).toInt());
    create_chatp.bindValue(":chat", chatID);

    if (create_chatp.exec()) qDebug() << "Chat participant " << users.value(rec.indexOf("pk_user")).toInt() << "was created!";
    else qDebug() << "Error create CP " << users.value(rec.indexOf("pk_user")).toInt() << "!";
    qDebug() << create_chatp.lastError();

    temp.insert("return", 0);
    temp.insert("pk_chat", chatID);
    temp.insert("chatname", chatinfo["chatname"].toString());
    }
    qDebug() << temp    ;
    jResObj.insert("value", temp);
    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());
    SendToClient(jReqStr);
}

void Server::AcceptReqToAddUserInChat(QJsonValue users)
{
    QSqlQuery create_chatp, user, chats;
    for (auto it : users["users"].toArray()) {
        user.prepare("SELECT pk_user, username FROM User WHERE user.username == :username");
        user.bindValue(":username", it.toString());
        user.exec();

        chats.prepare("SELECT pk_chat FROM chat WHERE chat.pk_chat == :chatID");
        chats.bindValue(":chatID", users["pk_chat"].toInt());
        chats.exec();

        QSqlRecord rec = user.record(), rec2 = chats.record();
        chats.next();
        if (user.next()){
            create_chatp.prepare("INSERT INTO ChatParticipant (pk_user, pk_chat) VALUES (:user, :chat)");
            create_chatp.bindValue(":user", user.value(rec.indexOf("pk_user")).toInt());
            create_chatp.bindValue(":chat", chats.value(rec2.indexOf("pk_chat")).toInt());

            if (create_chatp.exec()) qDebug() << "Chat participant " << user.value(rec.indexOf("pk_user")).toInt() << "was created!";
            else qDebug() << "Error create CP " << user.value(rec.indexOf("pk_user")).toInt() << "!";

            auto it = sockets.value(user.value(rec.indexOf("username")).toString());
            QJsonObject jResObj;
            jResObj.insert("type", "update_chats");
            jResObj.insert("value", "");
            QJsonDocument jReqDoc = QJsonDocument{jResObj};
            QString jReqStr = QString(jReqDoc.toJson());
            SendToClient(jReqStr, it);
        }
    }
}

void Server::AcceptJSONMess(QString str)
{
    // DETERMINE TYPE OF MESSAGE AND DO ACTION
    QJsonDocument jDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jObj = jDoc.object();
    qDebug() << "Accept JSON: " << jObj;
    if (jObj["type"] == "auth") {
        GetAuthUserInfo(jObj["value"].toObject());
    }
    else if (jObj["type"] == "mess"){
        AcceptMessages(jObj["value"]);
    }
    else if (jObj["type"] == "chats_request"){
        AcceptReqForChats(jObj["value"].toString());
    }
    else if (jObj["type"] == "dialog_request") {
        AcceptReqForDialogs(jObj["value"].toInt());
    }
    else if (jObj["type"] == "finduser_request"){
        AcceptReqForFinduser(jObj["value"]);
    }
    else if (jObj["type"] == "createchat_request") {
        AcceptReqForCreateChat(jObj["value"]);
    }
    else if (jObj["type"] == "creategroupchat_request"){
        AcceptReqForCreateGroupChat(jObj["value"]);
    }
    else if (jObj["type"] == "adduserstochat_request") {
        AcceptReqToAddUserInChat(jObj["value"]);
    }
    else qDebug() << "Can't recognize JSON type!";
}

void Server::SendSignalToUpdateDialog(QJsonValue message)
{
    QJsonObject jResObj;
    jResObj.insert("type", "update_dialog");
    jResObj.insert("value", message);

    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString(jReqDoc.toJson());

    // SEND SIGNAL TO ALL CHAT PARTICIPANT
    QSqlQuery chatp;
    chatp.prepare("SELECT username, user.pk_user FROM user, ChatParticipant JOIN chat ON ChatParticipant.pk_chat == chat.pk_chat WHERE chat.pk_chat == :chatID AND user.pk_user == chatParticipant.pk_user");
    chatp.bindValue(":chatID", message["pk_chat"].toInt());
    chatp.exec();
    QSqlRecord rec = chatp.record();
    qDebug() << sockets;
    while (chatp.next()) {
        auto it = sockets.value(chatp.value(rec.indexOf("username")).toString());
        QJsonDocument jReqDoc = QJsonDocument{jResObj};
        QString jReqStr = QString(jReqDoc.toJson());
        SendToClient(jReqStr, it);
    }
}

template<typename T>
void Server::SendToClient(T arg, QTcpSocket* s)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << arg;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));

    if (s == nullptr) s = this->socket;
    s->write(data);
}

