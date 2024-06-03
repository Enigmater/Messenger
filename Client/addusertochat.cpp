#include "addusertochat.h"
#include "ui_addusertochat.h"

AddUserToChat::AddUserToChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUserToChat)
{
    setWindowFlags(Qt::CustomizeWindowHint);
    ui->setupUi(this); 
}

AddUserToChat::~AddUserToChat()
{
    delete ui;
}

void AddUserToChat::SetUsers(QJsonArray users)
{
    this->users = users;
    this->notChoosenUsers = this->users;
    for (int i = this->choosenUsers.size(); i >= 0 ; i--) {
        this->choosenUsers.removeAt(i);
    }
    CreateUsersFromArray(this->notChoosenUsers);
    CreateUsersFromArray(this->choosenUsers, ui->buttonsLayout);
}

void AddUserToChat::slotDialogButtonClicked()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    for (QJsonArray::iterator iter = this->notChoosenUsers.begin(); iter != this->notChoosenUsers.end(); iter++) {
        // button is not in choosen users
        if (button->text() == iter->toString()){
            this->choosenUsers.push_back(iter->toString());
            this->notChoosenUsers.erase(iter);
            CreateUsersFromArray(notChoosenUsers);
            CreateUsersFromArray(choosenUsers, ui->buttonsLayout);
            return;
        }
    }

    for (QJsonArray::iterator iter = this->choosenUsers.begin(); iter != this->choosenUsers.end(); iter++) {
        // button is in choosen users
        if (button->text() == iter->toString()){
            this->notChoosenUsers.push_back(iter->toString());
            this->choosenUsers.erase(iter);
            CreateUsersFromArray(notChoosenUsers);
            CreateUsersFromArray(choosenUsers, ui->buttonsLayout);
            return;
        }
    }



}

void AddUserToChat::on_cancelButton_clicked()
{
    emit signalCancel();
}

void AddUserToChat::on_okButton_clicked()
{
    QJsonObject jResObj;
    jResObj.insert("users", this->choosenUsers);
    emit signalAddUser(jResObj);
}

void AddUserToChat::CreateUsersFromArray(QJsonArray value, QVBoxLayout* layout)
{
    if (layout == nullptr) layout = ui->buttonsLayout2;
    // CLEAR BUTTONS (CHATS)
    for(int i = layout->count() - 1; i >= 0; i--){
        QDynamicButton *button = qobject_cast<QDynamicButton*>(layout->itemAt(i)->widget());
        button->hide();
        delete button;
    }
    if (!value.size()) return;
    foreach(const QJsonValue& value1, value) {
         QDynamicButton* dialog = new QDynamicButton(this);
         connect(dialog, SIGNAL(clicked()), this, SLOT(slotDialogButtonClicked()));

         dialog->setText(value1.toString());
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

         layout->addWidget(dialog);
    }
}

void AddUserToChat::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 == "") {
        CreateUsersFromArray(this->notChoosenUsers);
        return;
    }
    QJsonArray jArrRes;
    for (auto it : this->notChoosenUsers) {
        if (it.toString().contains(arg1)) jArrRes.push_back(it);
    }
    CreateUsersFromArray(jArrRes);
}
