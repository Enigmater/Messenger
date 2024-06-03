#include "newgroup.h"
#include "ui_newgroup.h"

NewGroup::NewGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewGroup)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
}

NewGroup::~NewGroup()
{
    delete ui;
}

void NewGroup::on_cancelButton_clicked()
{
    emit cancelPressed();
}

void NewGroup::on_nextButton_clicked()
{
    if (ui->lineEdit->text() != ""){
        emit nextPressed(ui->lineEdit->text());
    }
    else {
        ui->lineEdit->setStyleSheet("background: rgb(23, 33, 43); border: 0; color: rgb(239, 89, 89); border-bottom: 2px solid rgb(239, 89, 89);");
        ui->label->setStyleSheet("color: rgb(239, 89, 89)");
    }
}

void NewGroup::on_lineEdit_textEdited(const QString &arg1)
{
    ui->lineEdit->setStyleSheet("background: rgb(23, 33, 43); border: 0; color: rgb(99, 150, 203); border-bottom: 2px solid rgb(99, 150, 203);");
    ui->label->setStyleSheet("color: rgb(99, 150, 203)");
}
