/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authform
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title_lable;
    QHBoxLayout *login_hlayout;
    QLineEdit *login_edit;
    QHBoxLayout *pass_hlayout;
    QLineEdit *pass_edit;
    QHBoxLayout *button_hlayout;
    QPushButton *pushButton;
    QPushButton *auth_button;

    void setupUi(QWidget *authform)
    {
        if (authform->objectName().isEmpty())
            authform->setObjectName(QString::fromUtf8("authform"));
        authform->resize(400, 300);
        authform->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 33, 43)"));
        verticalLayout = new QVBoxLayout(authform);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        title_lable = new QLabel(authform);
        title_lable->setObjectName(QString::fromUtf8("title_lable"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title_lable->sizePolicy().hasHeightForWidth());
        title_lable->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Unispace")});
        font.setPointSize(24);
        font.setBold(true);
        title_lable->setFont(font);
        title_lable->setStyleSheet(QString::fromUtf8("color: white;"));
        title_lable->setTextFormat(Qt::AutoText);
        title_lable->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_lable);

        login_hlayout = new QHBoxLayout();
        login_hlayout->setObjectName(QString::fromUtf8("login_hlayout"));
        login_edit = new QLineEdit(authform);
        login_edit->setObjectName(QString::fromUtf8("login_edit"));
        login_edit->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: 0;\n"
"border-bottom: 2px solid rgb(127, 145, 164);\n"
"color: rgb(127, 145, 164);\n"
"padding-bottom: 7px"));

        login_hlayout->addWidget(login_edit);


        verticalLayout->addLayout(login_hlayout);

        pass_hlayout = new QHBoxLayout();
        pass_hlayout->setObjectName(QString::fromUtf8("pass_hlayout"));
        pass_edit = new QLineEdit(authform);
        pass_edit->setObjectName(QString::fromUtf8("pass_edit"));
        pass_edit->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: 0;\n"
"border-bottom: 2px solid rgb(127, 145, 164);\n"
"color: rgb(127, 145, 164);\n"
"padding-bottom: 7px"));

        pass_hlayout->addWidget(pass_edit);


        verticalLayout->addLayout(pass_hlayout);

        button_hlayout = new QHBoxLayout();
        button_hlayout->setObjectName(QString::fromUtf8("button_hlayout"));
        pushButton = new QPushButton(authform);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(127, 145, 164);"));
        pushButton->setFlat(true);

        button_hlayout->addWidget(pushButton);

        auth_button = new QPushButton(authform);
        auth_button->setObjectName(QString::fromUtf8("auth_button"));
        auth_button->setMinimumSize(QSize(0, 30));
        auth_button->setMaximumSize(QSize(150, 16777215));
        auth_button->setStyleSheet(QString::fromUtf8("color: rgb(127, 145, 164);"));
        auth_button->setFlat(true);

        button_hlayout->addWidget(auth_button);


        verticalLayout->addLayout(button_hlayout);


        retranslateUi(authform);

        QMetaObject::connectSlotsByName(authform);
    } // setupUi

    void retranslateUi(QWidget *authform)
    {
        authform->setWindowTitle(QCoreApplication::translate("authform", "Form", nullptr));
        title_lable->setText(QCoreApplication::translate("authform", "Authorization", nullptr));
        login_edit->setPlaceholderText(QCoreApplication::translate("authform", "Login", nullptr));
        pass_edit->setPlaceholderText(QCoreApplication::translate("authform", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("authform", "Sign up", nullptr));
        auth_button->setText(QCoreApplication::translate("authform", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authform: public Ui_authform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
