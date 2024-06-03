#ifndef ADDUSERTOCHAT_H
#define ADDUSERTOCHAT_H

#include <QWidget>
#include <QVBoxLayout>

#include <QJsonObject>
#include <QJsonArray>

#include <QVector>

#include "qdynamicbutton.h"

namespace Ui {
class AddUserToChat;
}

class AddUserToChat : public QWidget
{
    Q_OBJECT

public:
    explicit AddUserToChat(QWidget *parent = nullptr);
    ~AddUserToChat();

    void SetUsers(QJsonArray users);

private slots:
    void slotDialogButtonClicked();

    void on_cancelButton_clicked();

    void on_okButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::AddUserToChat *ui;

    QJsonArray users;
    QJsonArray choosenUsers;
    QJsonArray notChoosenUsers;

   void CreateUsersFromArray(QJsonArray value, QVBoxLayout* layout = nullptr);

signals:
    void signalCancel();
    void signalAddUser(QJsonObject);
};

#endif // ADDUSERTOCHAT_H
