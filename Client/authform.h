#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QJsonObject>

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class authform;
}

class authform : public QWidget
{
    Q_OBJECT

public:
    explicit authform(QWidget *parent = nullptr);
    ~authform();

private slots:
    void on_auth_button_clicked();

    void on_pushButton_clicked();

public slots:
    void slotAuthError();

signals:
    void signalAuthComplete(QJsonObject);

private:
    QJsonObject CreateUserJSON(QString type);
    Ui::authform *ui;
};

#endif // AUTHFORM_H
