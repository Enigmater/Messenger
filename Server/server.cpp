#include "server.h"

void Server::incomingConnection(qintptr handle)
{
    socket =  new QTcpSocket;
    socket->setSocketDescriptor(handle);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotDeleteLater);

    sockets.push_back(socket);
    qDebug() << "client was connected" << handle;
}

void Server::slotDeleteLater()
{
    socket = (QTcpSocket*)sender();
    sockets.erase(std::remove(sockets.begin(), sockets.end(), socket), sockets.end());
    socket->deleteLater();
    qDebug() << "client was diconnected " << socket;
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok) {
        qDebug() << "reading...";
        while (true) {
            if (nextBlockSize == 0) {
                qDebug() << "nextBlockSize = 0";
                if (socket->bytesAvailable() < 2) {
                    qDebug() << "data < 2... Break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize = " << nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) break;
            QString str;
            in >> str;
            nextBlockSize = 0;
            qDebug() << str;
            SendToClient(str);
        }
    }
    else
        qDebug() << "read error!" ;

}

Server::Server()
{
    // OPEN DB

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Messenger.db");
    if (db.open()) qDebug() << "DB was opened! " << db.databaseName();
    else qDebug() << "Error opening DB! " << db.lastError().databaseText();

    // START LISTENING SOCKETS
    if(this->listen(QHostAddress::Any, 27015))
        qDebug() << "start";
    else
        qDebug() << "error";
    nextBlockSize = 0;
}

void Server::SendToClient(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));

    //socket->write(data);
    for (int i = 0; i < sockets.size(); i++) {
        sockets[i]->write(data);
    }
}
