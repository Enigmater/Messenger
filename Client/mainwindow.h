#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

#include <QGraphicsBlurEffect>

#include "authform.h"

#include "qdynamicbutton.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray data;
    quint16 nextBlockSize;

    authform* authF;

    QString username;
    int currentChat = -1;

    template<typename T>
    void SendToServer(T arg);

    void SendReqForChats();
    void SendReqForCreateChat(QJsonObject obj);
    void AcceptJSONMess(QString str);
    void AcceptAuthResponse(QJsonValue value);
    void AcceptChatResponse(QJsonValue value);
    void AcceptMessResponse(QJsonValue value);
    void AcceptCreateChatResponse(QJsonValue value);
    void CreateUsersFromArray(QJsonValue value);

public slots:
    void slotReadyRead();
    void slotAuthComplete(QJsonObject userinfo);

private slots:
    void on_mess_edit_returnPressed();
    void slotDialogButtonClicked();

    void on_searchLine_textChanged(const QString &arg1);

    void on_menuButton_clicked();

    void on_pushButton_clicked();

signals:
    void signalAuthError();
};
#endif // MAINWINDOW_H
