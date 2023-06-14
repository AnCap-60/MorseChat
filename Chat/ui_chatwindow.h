/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QPushButton *translateToMorzeButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *dashButton;
    QPushButton *doteButton;
    QPushButton *spaceButton;
    QPushButton *slashButton;
    QPushButton *clearButton;
    QPushButton *translateToRussianButton;
    QPushButton *testButton;
    QPushButton *deleteButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(500, 630);
        ChatWindow->setMinimumSize(QSize(500, 630));
        ChatWindow->setMaximumSize(QSize(500, 630));
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 40, 461, 421));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 470, 361, 31));
        lineEdit->setInputMethodHints(Qt::ImhNone);
        lineEdit->setMaxLength(32767);
        lineEdit->setReadOnly(true);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(390, 470, 91, 31));
        translateToMorzeButton = new QPushButton(centralwidget);
        translateToMorzeButton->setObjectName("translateToMorzeButton");
        translateToMorzeButton->setGeometry(QRect(350, 10, 131, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 510, 361, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dashButton = new QPushButton(layoutWidget);
        dashButton->setObjectName("dashButton");
        dashButton->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(dashButton);

        doteButton = new QPushButton(layoutWidget);
        doteButton->setObjectName("doteButton");
        doteButton->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(doteButton);

        spaceButton = new QPushButton(layoutWidget);
        spaceButton->setObjectName("spaceButton");
        spaceButton->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(spaceButton);

        slashButton = new QPushButton(layoutWidget);
        slashButton->setObjectName("slashButton");
        slashButton->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(slashButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(390, 560, 91, 23));
        translateToRussianButton = new QPushButton(centralwidget);
        translateToRussianButton->setObjectName("translateToRussianButton");
        translateToRussianButton->setGeometry(QRect(350, 10, 131, 23));
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName("testButton");
        testButton->setGeometry(QRect(170, 10, 75, 23));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(390, 510, 91, 39));
        deleteButton->setMaximumSize(QSize(16777215, 50));
        ChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        ChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatWindow);
        statusbar->setObjectName("statusbar");
        ChatWindow->setStatusBar(statusbar);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "\320\247\320\260\321\202", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        translateToMorzeButton->setText(QCoreApplication::translate("ChatWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\275\320\260 \320\234\320\276\321\200\320\267\320\265", nullptr));
        dashButton->setText(QCoreApplication::translate("ChatWindow", "-", nullptr));
        doteButton->setText(QCoreApplication::translate("ChatWindow", ".", nullptr));
        spaceButton->setText(QCoreApplication::translate("ChatWindow", "\320\237\321\200\320\276\320\261\320\265\320\273", nullptr));
        slashButton->setText(QCoreApplication::translate("ChatWindow", "/", nullptr));
        clearButton->setText(QCoreApplication::translate("ChatWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        translateToRussianButton->setText(QCoreApplication::translate("ChatWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        testButton->setText(QCoreApplication::translate("ChatWindow", "PushButton", nullptr));
        deleteButton->setText(QCoreApplication::translate("ChatWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
