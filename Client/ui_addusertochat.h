/********************************************************************************
** Form generated from reading UI file 'addusertochat.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERTOCHAT_H
#define UI_ADDUSERTOCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUserToChat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *buttonsLayout;
    QFrame *line_2;
    QVBoxLayout *buttonsLayout2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QWidget *AddUserToChat)
    {
        if (AddUserToChat->objectName().isEmpty())
            AddUserToChat->setObjectName(QString::fromUtf8("AddUserToChat"));
        AddUserToChat->resize(273, 443);
        AddUserToChat->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 33, 43);"));
        verticalLayout = new QVBoxLayout(AddUserToChat);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 9, 0, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, -1, -1, -1);
        label = new QLabel(AddUserToChat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/img/icons8-search-16.png")));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(AddUserToChat);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("border: 0;\n"
"color: rgb(105, 116, 128);"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(AddUserToChat);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        scrollArea = new QScrollArea(AddUserToChat);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"	border: none;\n"
"}\n"
"QScrollBar:vertical {\n"
"	background-color: rgb(145, 150, 155);\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	width: 5px;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"	border-radius: 5px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"	border-radius: 5px;\n"
"}\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical{\n"
"	background-color: rgb(63, 71, 80);\n"
"	border-radius: 5px;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{\n"
"	background-color: rgb(63, 71, 80);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 273, 354));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));

        verticalLayout_3->addLayout(buttonsLayout);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        buttonsLayout2 = new QVBoxLayout();
        buttonsLayout2->setObjectName(QString::fromUtf8("buttonsLayout2"));

        verticalLayout_3->addLayout(buttonsLayout2);

        verticalSpacer = new QSpacerItem(20, 349, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 9, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(AddUserToChat);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(50, 30));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(23, 33, 43);\n"
"border: 0;\n"
"border-radius: 5px;\n"
"color: rgb(99, 150, 203);\n"
"font: bold 1.2em \"Open Sans\", sans-serif;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(29, 42, 57);\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(cancelButton);

        okButton = new QPushButton(AddUserToChat);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setMinimumSize(QSize(50, 30));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(23, 33, 43);\n"
"border: 0;\n"
"border-radius: 5px;\n"
"color: rgb(99, 150, 203);\n"
"font: bold 1.2em \"Open Sans\", sans-serif;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(29, 42, 57);\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddUserToChat);

        QMetaObject::connectSlotsByName(AddUserToChat);
    } // setupUi

    void retranslateUi(QWidget *AddUserToChat)
    {
        AddUserToChat->setWindowTitle(QCoreApplication::translate("AddUserToChat", "Form", nullptr));
        label->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("AddUserToChat", "Search", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddUserToChat", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("AddUserToChat", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserToChat: public Ui_AddUserToChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERTOCHAT_H
