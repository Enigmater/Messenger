#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>

#include <QVector>
#include <QMap>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#endif // SERVER_H

class Server : public QTcpServer {
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;

private:
    QSqlDatabase db;

    QMap <QString, QTcpSocket*> sockets;
    QByteArray data;
    quint16 nextBlockSize;

    template<typename T>
    void SendToClient(T arg, QTcpSocket* s = nullptr);

    void GetAuthUserInfo(QJsonObject jUserInfo);
    bool ValidateLogin(QJsonValue user);
    void RegistrateAccount(QJsonValue user);

    void AcceptReqForChats(QString senderUsername);
    void AcceptReqForDialogs(int chatID);
    void AcceptReqForFinduser(QJsonValue searchUser);
    void AcceptMessages(QJsonValue message);
    void AcceptReqForCreateChat(QJsonValue chatinfo);
    void AcceptJSONMess(QString str);

    void SendSignalToUpdateDialog(QJsonValue message);

public slots:
    void incomingConnection(qintptr handle);
    void slotDeleteLater();
    void slotReadyRead();
};
