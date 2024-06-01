/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *slidebarMenu;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QWidget *userInfo;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QWidget *buttons;
    QVBoxLayout *verticalLayout_7;
    QWidget *about;
    QPushButton *pushButton;
    QSplitter *splitter;
    QWidget *leftContainer;
    QVBoxLayout *verticalLayout;
    QFrame *chatsContainerFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *searchFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *menuButton;
    QLineEdit *searchLine;
    QFrame *chatsFrame;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *chatsHLayout;
    QSpacerItem *verticalSpacer;
    QWidget *rightContainer;
    QVBoxLayout *verticalLayout_3;
    QFrame *infoAbout_hframe;
    QHBoxLayout *horizontalLayout_3;
    QLabel *userinfo_lable;
    QFrame *dialog_hframe;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *chat_browser;
    QFrame *input_hframe;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *mess_edit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMaximumSize(QSize(16777215, 1000));
        MainWindow->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 25, 33);"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        slidebarMenu = new QWidget(centralwidget);
        slidebarMenu->setObjectName(QString::fromUtf8("slidebarMenu"));
        slidebarMenu->setMinimumSize(QSize(0, 0));
        slidebarMenu->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_7 = new QHBoxLayout(slidebarMenu);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(slidebarMenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(250, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        userInfo = new QWidget(widget);
        userInfo->setObjectName(QString::fromUtf8("userInfo"));
        userInfo->setMinimumSize(QSize(0, 100));
        userInfo->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(userInfo);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 402, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        buttons = new QWidget(widget);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        verticalLayout_7 = new QVBoxLayout(buttons);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        verticalLayout_4->addWidget(buttons);

        about = new QWidget(widget);
        about->setObjectName(QString::fromUtf8("about"));
        about->setMinimumSize(QSize(0, 50));
        about->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(about);


        horizontalLayout_7->addWidget(widget);

        pushButton = new QPushButton(slidebarMenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 17, 22)"));
        pushButton->setFlat(false);

        horizontalLayout_7->addWidget(pushButton);


        horizontalLayout_5->addWidget(slidebarMenu);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setLineWidth(1);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(1);
        leftContainer = new QWidget(splitter);
        leftContainer->setObjectName(QString::fromUtf8("leftContainer"));
        leftContainer->setMaximumSize(QSize(300, 16777215));
        leftContainer->setMouseTracking(false);
        leftContainer->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 33, 43)"));
        verticalLayout = new QVBoxLayout(leftContainer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chatsContainerFrame = new QFrame(leftContainer);
        chatsContainerFrame->setObjectName(QString::fromUtf8("chatsContainerFrame"));
        chatsContainerFrame->setMaximumSize(QSize(16777215, 16777215));
        chatsContainerFrame->setFrameShape(QFrame::StyledPanel);
        chatsContainerFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(chatsContainerFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchFrame = new QFrame(chatsContainerFrame);
        searchFrame->setObjectName(QString::fromUtf8("searchFrame"));
        searchFrame->setMinimumSize(QSize(0, 0));
        searchFrame->setMaximumSize(QSize(16777215, 50));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(searchFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 0, 9, 0);
        menuButton = new QPushButton(searchFrame);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menuButton->sizePolicy().hasHeightForWidth());
        menuButton->setSizePolicy(sizePolicy1);
        menuButton->setMinimumSize(QSize(40, 40));
        menuButton->setStyleSheet(QString::fromUtf8("QPushButton#menuButton {\n"
"	background-color: rgba(0,0,0,0);\n"
"    background-image: url(\":/icons/img/menu_icon16_1.png\");\n"
"    background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}\n"
"QPushButton#menuButton:hover {\n"
"	background-image: url(\":/icons/img/menu_icon_16_2.png\");\n"
"    background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}\n"
""));
        menuButton->setIconSize(QSize(16, 16));
        menuButton->setFlat(true);

        horizontalLayout_2->addWidget(menuButton);

        searchLine = new QLineEdit(searchFrame);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchLine->sizePolicy().hasHeightForWidth());
        searchLine->setSizePolicy(sizePolicy2);
        searchLine->setMinimumSize(QSize(0, 20));
        searchLine->setMaximumSize(QSize(1000, 40));
        searchLine->setStyleSheet(QString::fromUtf8("QLineEdit#searchLine{\n"
"	background-color: rgb(36, 47, 61);\n"
"	color: rgb(127, 145, 164);\n"
"	padding-left: 15;\n"
"	border-radius: 20px;\n"
"	font: 1.2rem \"Open Sans\", sans-serif;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(searchLine);


        verticalLayout_2->addWidget(searchFrame);

        chatsFrame = new QFrame(chatsContainerFrame);
        chatsFrame->setObjectName(QString::fromUtf8("chatsFrame"));
        chatsFrame->setStyleSheet(QString::fromUtf8(""));
        chatsFrame->setFrameShape(QFrame::StyledPanel);
        chatsFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(chatsFrame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(chatsFrame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 548));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        chatsHLayout = new QVBoxLayout();
        chatsHLayout->setObjectName(QString::fromUtf8("chatsHLayout"));

        verticalLayout_5->addLayout(chatsHLayout);

        verticalSpacer = new QSpacerItem(17, 537, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);


        verticalLayout_2->addWidget(chatsFrame);


        verticalLayout->addWidget(chatsContainerFrame);

        splitter->addWidget(leftContainer);
        rightContainer = new QWidget(splitter);
        rightContainer->setObjectName(QString::fromUtf8("rightContainer"));
        verticalLayout_3 = new QVBoxLayout(rightContainer);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        infoAbout_hframe = new QFrame(rightContainer);
        infoAbout_hframe->setObjectName(QString::fromUtf8("infoAbout_hframe"));
        infoAbout_hframe->setMinimumSize(QSize(0, 50));
        infoAbout_hframe->setMaximumSize(QSize(16777215, 50));
        infoAbout_hframe->setBaseSize(QSize(0, 0));
        infoAbout_hframe->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 33, 43);"));
        infoAbout_hframe->setFrameShape(QFrame::StyledPanel);
        infoAbout_hframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(infoAbout_hframe);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        userinfo_lable = new QLabel(infoAbout_hframe);
        userinfo_lable->setObjectName(QString::fromUtf8("userinfo_lable"));
        userinfo_lable->setStyleSheet(QString::fromUtf8("color: rgb(127, 145, 164);\n"
"font: 1.2rem \"Open Sans\", sans-serif;"));

        horizontalLayout_3->addWidget(userinfo_lable);


        verticalLayout_3->addWidget(infoAbout_hframe);

        dialog_hframe = new QFrame(rightContainer);
        dialog_hframe->setObjectName(QString::fromUtf8("dialog_hframe"));
        dialog_hframe->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 25, 33);"));
        dialog_hframe->setFrameShape(QFrame::StyledPanel);
        dialog_hframe->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(dialog_hframe);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chat_browser = new QTextBrowser(dialog_hframe);
        chat_browser->setObjectName(QString::fromUtf8("chat_browser"));
        chat_browser->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"border: 0;\n"
"font: 1.2rem \\\"Open Sans\\\", sans-serif;"));

        horizontalLayout->addWidget(chat_browser);


        verticalLayout_3->addWidget(dialog_hframe);

        input_hframe = new QFrame(rightContainer);
        input_hframe->setObjectName(QString::fromUtf8("input_hframe"));
        input_hframe->setMaximumSize(QSize(16777215, 50));
        input_hframe->setStyleSheet(QString::fromUtf8("background-color: rgb(23 ,33, 43);"));
        input_hframe->setFrameShape(QFrame::StyledPanel);
        input_hframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(input_hframe);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mess_edit = new QLineEdit(input_hframe);
        mess_edit->setObjectName(QString::fromUtf8("mess_edit"));
        mess_edit->setMinimumSize(QSize(0, 30));
        mess_edit->setStyleSheet(QString::fromUtf8("color: rgb(127 ,145 ,164);\n"
"font: 1.2rem \"Open Sans\", sans-serif;\n"
"border: 0;"));

        horizontalLayout_4->addWidget(mess_edit);


        verticalLayout_3->addWidget(input_hframe);

        splitter->addWidget(rightContainer);

        horizontalLayout_5->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Messanger", nullptr));
        pushButton->setText(QString());
        menuButton->setText(QString());
        searchLine->setInputMask(QString());
        searchLine->setText(QString());
        searchLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        userinfo_lable->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        mess_edit->setInputMask(QString());
        mess_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Write a message...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
