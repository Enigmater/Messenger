#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>

#endif // SERVER_H

class Server : public QTcpServer {
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;

private:
    QSqlDatabase db;

    QVector <QTcpSocket*> sockets;
    QByteArray data;
    quint16 nextBlockSize;
    void SendToClient(QString str);

public slots:
    void incomingConnection(qintptr handle);
    void slotDeleteLater();
    void slotReadyRead();
};
