#include "authForm1.h"
#include "ui_authForm.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setipUi(this);
}

AuthForm::~AuthForm()
{
    delete ui;
}
