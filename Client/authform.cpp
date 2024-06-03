#include "authform.h"
#include "ui_authform.h"

authform::authform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authform)
{
    ui->setupUi(this);
}

authform::~authform()
{
    delete ui;
}

void authform::on_auth_button_clicked()
{
    QString login = ui->login_edit->text();
    QString pass = ui->pass_edit->text();
    if (login != "" && pass != "") {
        emit signalAuthComplete(CreateUserJSON("login"));
    }
}

void authform::slotAuthError()
{
    ui->login_edit->setText("");
    ui->pass_edit->setText("");
    QMessageBox mb(this);
    mb.setText("Wrong pass at sign up!\nOr\nWrong login/pass at sign in!");
    mb.setWindowTitle("AUTH ERROR!");
    QPushButton* qbut = new QPushButton("Ok");
    qbut->setStyleSheet("color: rgb(127, 145, 164);");
    mb.addButton(qbut, QMessageBox::AcceptRole);
    mb.setStyleSheet("color: rgb(127, 145, 164);");
    mb.exec();
}

QJsonObject authform::CreateUserJSON(QString type)
{
    QJsonObject temp, userinfo;
    temp.insert("type", type);
    temp.insert("login", ui->login_edit->text());
    QString pass = QCryptographicHash::hash(ui->pass_edit->text().toUtf8(), QCryptographicHash::Sha256);
    temp.insert("pass", pass);
    userinfo.insert("user", temp);
    return userinfo;
}

void authform::on_pushButton_clicked()
{
    QString login = ui->login_edit->text();
    QString pass = ui->pass_edit->text();
    if (login != "" && pass != "") {
        emit signalAuthComplete(CreateUserJSON("signup"));
    }
}
