/********************************************************************************
** Form generated from reading UI file 'newgroup.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGROUP_H
#define UI_NEWGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGroup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *nextButton;

    void setupUi(QWidget *NewGroup)
    {
        if (NewGroup->objectName().isEmpty())
            NewGroup->setObjectName(QString::fromUtf8("NewGroup"));
        NewGroup->setWindowModality(Qt::NonModal);
        NewGroup->resize(233, 89);
        NewGroup->setFocusPolicy(Qt::NoFocus);
        NewGroup->setContextMenuPolicy(Qt::NoContextMenu);
        NewGroup->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 33, 43)"));
        verticalLayout = new QVBoxLayout(NewGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        label = new QLabel(NewGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        label->setStyleSheet(QString::fromUtf8("font: bold 1.2em \"Open Sans\", sans-serif;\n"
"color: rgb(99, 150, 203);"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(NewGroup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(23, 33, 43);\n"
"color: rgb(99, 150, 203);\n"
"border: 0;\n"
"border-bottom: 2px solid rgb(99, 150, 203);"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(NewGroup);
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
        cancelButton->setFlat(false);

        horizontalLayout->addWidget(cancelButton);

        nextButton = new QPushButton(NewGroup);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMinimumSize(QSize(50, 30));
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(23, 33, 43);\n"
"border: 0;\n"
"border-radius: 5px;\n"
"color: rgb(99, 150, 203);\n"
"font: bold 1.2rem \"Open Sans\", sans-serif;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(29, 42, 57);\n"
"}\n"
"\n"
""));
        nextButton->setFlat(false);

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(NewGroup);

        QMetaObject::connectSlotsByName(NewGroup);
    } // setupUi

    void retranslateUi(QWidget *NewGroup)
    {
        NewGroup->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("NewGroup", "Group name", nullptr));
        cancelButton->setText(QCoreApplication::translate("NewGroup", "Cancel", nullptr));
        nextButton->setText(QCoreApplication::translate("NewGroup", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewGroup: public Ui_NewGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGROUP_H
