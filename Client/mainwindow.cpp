#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nextBlockSize = 0;
    authF = new authform;
    authF->show();
    connect(authF, &authform::signalAuthComplete, this, &MainWindow::slotAuthComplete);
    connect(this, &MainWindow::signalAuthError, authF, &authform::slotAuthError);

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::deleteLater);
    socket->connectToHost("192.168.0.14", 27015);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SendReqForChats()
{
    QJsonObject jResObj;
    jResObj.insert("type", "chats_request");
    jResObj.insert("value", this->username);
    QJsonDocument jReqDoc = QJsonDocument(jResObj);
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
}

void MainWindow::SendReqForCreateChat(QJsonObject obj)
{
    QJsonObject jResObj;
    jResObj.insert("type", "createchat_request");
    jResObj.insert("value", obj);

    QJsonDocument jReqDoc = QJsonDocument(jResObj);
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
}

void MainWindow::AcceptJSONMess(QString str)
{
    // DETERMINE TYPE OF MESSAGE AND DO ACTION
    QJsonDocument jDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jObj = jDoc.object();

    if (jObj["type"] == "mess"){
        qDebug() << "message";
        ui->chat_browser->append(jObj["value"].toString());
    }
    else if (jObj["type"] == "auth_response") {
        AcceptAuthResponse(jObj["value"]);
    }
    else if (jObj["type"] == "chats_response") {
        CreateUsersFromArray(jObj["value"]);
    }
    else if (jObj["type"] == "dialog_response") {
        AcceptMessResponse(jObj["value"]);
    }
    else if (jObj["type"] == "finduser_response") {
        CreateUsersFromArray(jObj["value"]);
    }
    else if (jObj["type"] == "createchat_response") {
        AcceptCreateChatResponse(jObj["value"]);
    }
    else if (jObj["type"] == "update_dialog"){
        QJsonValue value = jObj["value"];
        ui->chat_browser->append(value["text"].toString());
        qDebug() << "GET UPDATE SIGNAL " << value["text"].toString();
    }
}

void MainWindow::AcceptAuthResponse(QJsonValue value)
{
    if (value.toBool()) {
        authF->close();
        this->show();
        ui->slidebarMenu->hide();
        SendReqForChats();
    }
    else {
        this->username = "";
        emit signalAuthError();
    }
}


void MainWindow::AcceptMessResponse(QJsonValue value)
{
    ui->chat_browser->clear();
    QJsonArray jArray = value.toArray();
    if (!jArray.size()) {
        ui->chat_browser->append("Start chatting!");
        return;
    }
    foreach (const QJsonValue& it, jArray) {
        ui->chat_browser->append(it.toString());
    }

}

void MainWindow::AcceptCreateChatResponse(QJsonValue value)
{
    currentChat = value["pk_chat"].toInt();
    qDebug() << "Current chat set to " << currentChat;
    QJsonObject jResObj;
    jResObj.insert("type", "dialog_request");
    jResObj.insert("value",  currentChat);

    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
}

void MainWindow::CreateUsersFromArray(QJsonValue value)
{
    // CLEAR BUTTONS (CHATS)
    for(int i = ui->chatsHLayout->count() - 1; i >= 0; i--){
        QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->chatsHLayout->itemAt(i)->widget());
        button->hide();
        delete button;
    }
    QJsonArray jArray = value.toArray();
    if (!jArray.size()) return;
    foreach(const QJsonValue& value1, jArray) {
         QDynamicButton* dialog = new QDynamicButton(this);
         connect(dialog, SIGNAL(clicked()), this, SLOT(slotDialogButtonClicked()));
         if (value1.isObject()) {
             QStringList list = value1["chatname"].toString().split(" ");
             QString cname;
             if (list[0] == this->username) cname = list[1];
             else cname = list[0];
             dialog->setText(cname);
             dialog->SetChatID(value1["pk_chat"].toInt());
         }
         else {
             dialog->setText(value1.toString());
             dialog->SetChatID(-1);
         }

         dialog->setIcon(QIcon(":/icons/img/user_icon.png"));
         dialog->setIconSize(QSize(50, 50));
         dialog->setFlat(true);
         dialog->setMinimumHeight(50);
         QString style;
         style ="QDynamicButton {"
                        " background-color: rgb(23, 33, 43);"
                        " color: rgb(245, 245, 245);"
                        " text-align: left;"
                        " padding-left: 9px;"
                        " font: 1.2rem \"Open Sans\", sans-serif;"
                        "}"
                        "QDynamicButton:hover {"
                        " background-color: rgb(32, 43, 54);"
                        " border: 0"
                        "}";
         dialog->setStyleSheet(style);
         ui->chatsHLayout->addWidget(dialog);
    }
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        while (true) {
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable() < 2) break;
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) break;
            QString str;
            in >> str;
            nextBlockSize = 0;

            AcceptJSONMess(str);
        }
    }
    else {
        qDebug("read error");
    }
}

void MainWindow::slotAuthComplete(QJsonObject userinfo)
{
    QJsonObject jResObj;
    jResObj.insert("type", "auth");
    jResObj.insert("value", userinfo);
    QJsonDocument jReqDoc = QJsonDocument(jResObj);
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
    QJsonValue user = userinfo["user"];
    this->username = user["login"].toString();
}

void MainWindow::slotDialogButtonClicked()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    ui->userinfo_lable->setText(button->text());

    this->currentChat = button->GetChatID();

    QJsonObject temp;
    temp.insert("sender", this->username);
    temp.insert("pk_chat", currentChat);
    temp.insert("chatname", button->text());

    SendReqForCreateChat(temp);
    if (ui->searchLine->text() != "") {
        ui->searchLine->clear();
        SendReqForChats();
    }
    // SET STYLE FOR BUTTON
    QString style;
    style ="QDynamicButton {"
                   " background-color: rgb(43, 82, 120);"
                   " color: rgb(245, 245, 245);"
                   " text-align: left;"
                   " padding-left: 9px;"
                   " font: 1.2rem \"Open Sans\", sans-serif;"
                   "}";
    button->setStyleSheet(style);
}

void MainWindow::on_mess_edit_returnPressed()
{
    // IF NO ONE CHAT IS SELECT -> RETURN;
    if (currentChat == -1) return;

    QJsonObject jResObj, mess;
    jResObj.insert("type", "mess");
    mess.insert("sender", this->username);
    mess.insert("pk_chat", this->currentChat);
    mess.insert("text", ui->mess_edit->text());
    jResObj.insert("value", mess);
    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
}

template<typename T>
void MainWindow::SendToServer(T arg)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << arg;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
    ui->mess_edit->clear();
}

void MainWindow::on_searchLine_textChanged(const QString &arg1)
{
    if (arg1 == "") {
        SendReqForChats();
        return;
    }
    QJsonObject jResObj, temp;
    jResObj.insert("type", "finduser_request");
    temp.insert("username", ui->searchLine->text());
    temp.insert("sender", this->username);
    jResObj.insert("value", temp);
    QJsonDocument jReqDoc = QJsonDocument{jResObj};
    QString jReqStr = QString::fromLatin1(jReqDoc.toJson());
    SendToServer(jReqStr);
}

void MainWindow::on_menuButton_clicked()
{
    ui->slidebarMenu->show();
    ui->splitter->hide();
    //QGraphicsBlurEffect* effect = new QGraphicsBlurEffect;
    //ui->splitter->setGraphicsEffect(effect);
}

void MainWindow::on_pushButton_clicked()
{
    ui->slidebarMenu->hide();
    ui->splitter->show();
}
