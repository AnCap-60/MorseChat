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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *dashButton;
    QPushButton *doteButton;
    QPushButton *spaceButton;
    QPushButton *slashButton;
    QPushButton *deleteButton;
    QTextEdit *textEdit;
    QPushButton *translateButton;
    QComboBox *enterComboBox;
    QPushButton *flipButton;
    QComboBox *resultComboBox;
    QLineEdit *enterTranslateTextEdit;
    QLineEdit *resultTranslateTextEdit;
    QPushButton *pushButton;
    QPushButton *copyButton;
    QPushButton *pasteButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(879, 586);
        ChatWindow->setMinimumSize(QSize(879, 586));
        ChatWindow->setMaximumSize(QSize(879, 586));
        ChatWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 3, 250);"));
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 470, 361, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(220,220,220)\n"
""));
        lineEdit->setInputMethodHints(Qt::ImhNone);
        lineEdit->setMaxLength(32767);
        lineEdit->setReadOnly(true);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(390, 470, 91, 31));
        QFont font1;
        font1.setPointSize(12);
        sendButton->setFont(font1);
        sendButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 510, 361, 43));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dashButton = new QPushButton(layoutWidget);
        dashButton->setObjectName("dashButton");
        dashButton->setMaximumSize(QSize(16777215, 60));
        QFont font2;
        font2.setPointSize(20);
        dashButton->setFont(font2);
        dashButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));

        horizontalLayout->addWidget(dashButton);

        doteButton = new QPushButton(layoutWidget);
        doteButton->setObjectName("doteButton");
        doteButton->setMaximumSize(QSize(16777215, 50));
        doteButton->setFont(font2);
        doteButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));

        horizontalLayout->addWidget(doteButton);

        spaceButton = new QPushButton(layoutWidget);
        spaceButton->setObjectName("spaceButton");
        spaceButton->setMaximumSize(QSize(16777215, 60));
        spaceButton->setFont(font1);
        spaceButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));

        horizontalLayout->addWidget(spaceButton);

        slashButton = new QPushButton(layoutWidget);
        slashButton->setObjectName("slashButton");
        slashButton->setMaximumSize(QSize(16777215, 50));
        slashButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));

        horizontalLayout->addWidget(slashButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(390, 510, 91, 41));
        deleteButton->setMaximumSize(QSize(16777215, 50));
        deleteButton->setFont(font1);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 10, 461, 421));
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(220,220,220); selection-color: black; background-color:rgb(220,220,220)\n"
""));
        textEdit->setReadOnly(true);
        translateButton = new QPushButton(centralwidget);
        translateButton->setObjectName("translateButton");
        translateButton->setGeometry(QRect(640, 250, 81, 23));
        QFont font3;
        font3.setPointSize(10);
        translateButton->setFont(font3);
        translateButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        enterComboBox = new QComboBox(centralwidget);
        enterComboBox->addItem(QString());
        enterComboBox->addItem(QString());
        enterComboBox->setObjectName("enterComboBox");
        enterComboBox->setGeometry(QRect(500, 209, 151, 31));
        enterComboBox->setFont(font1);
        enterComboBox->setStyleSheet(QString::fromUtf8("background-color:rgb(220,220,220); selection-background-color:rgb(220,220,220);\n"
"QComboBox::drop-down\n"
"{\n"
"	background-color:rgb(250,180,3);\n"
"	selected-background-color:rgb(250,180,3);\n"
"}\n"
""));
        flipButton = new QPushButton(centralwidget);
        flipButton->setObjectName("flipButton");
        flipButton->setGeometry(QRect(660, 220, 41, 21));
        flipButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        resultComboBox = new QComboBox(centralwidget);
        resultComboBox->addItem(QString());
        resultComboBox->addItem(QString());
        resultComboBox->setObjectName("resultComboBox");
        resultComboBox->setGeometry(QRect(710, 209, 151, 31));
        resultComboBox->setFont(font1);
        resultComboBox->setStyleSheet(QString::fromUtf8("background-color:rgb(220,220,220); selection-background-color:rgb(220,220,220)"));
        enterTranslateTextEdit = new QLineEdit(centralwidget);
        enterTranslateTextEdit->setObjectName("enterTranslateTextEdit");
        enterTranslateTextEdit->setGeometry(QRect(500, 280, 172, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(16);
        enterTranslateTextEdit->setFont(font4);
        enterTranslateTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(220,220,220)\n"
""));
        enterTranslateTextEdit->setReadOnly(false);
        resultTranslateTextEdit = new QLineEdit(centralwidget);
        resultTranslateTextEdit->setObjectName("resultTranslateTextEdit");
        resultTranslateTextEdit->setGeometry(QRect(690, 280, 171, 31));
        resultTranslateTextEdit->setFont(font4);
        resultTranslateTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(220,220,220); selection-background-color: rgb(220,220,220); selection-color: black;\n"
""));
        resultTranslateTextEdit->setReadOnly(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(760, 520, 101, 31));
        QFont font5;
        font5.setPointSize(13);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        copyButton = new QPushButton(centralwidget);
        copyButton->setObjectName("copyButton");
        copyButton->setGeometry(QRect(780, 330, 81, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Times New Roman")});
        font6.setPointSize(10);
        copyButton->setFont(font6);
        copyButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        pasteButton = new QPushButton(centralwidget);
        pasteButton->setObjectName("pasteButton");
        pasteButton->setGeometry(QRect(20, 440, 131, 21));
        pasteButton->setFont(font6);
        pasteButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));
        ChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 879, 21));
        ChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatWindow);
        statusbar->setObjectName("statusbar");
        ChatWindow->setStatusBar(statusbar);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "MorseChat", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        dashButton->setText(QCoreApplication::translate("ChatWindow", "-", nullptr));
        doteButton->setText(QCoreApplication::translate("ChatWindow", ".", nullptr));
        spaceButton->setText(QCoreApplication::translate("ChatWindow", "\320\237\321\200\320\276\320\261\320\265\320\273", nullptr));
        slashButton->setText(QCoreApplication::translate("ChatWindow", "/", nullptr));
        deleteButton->setText(QCoreApplication::translate("ChatWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        textEdit->setHtml(QCoreApplication::translate("ChatWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Eras Medium ITC'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        translateButton->setText(QCoreApplication::translate("ChatWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270", nullptr));
        enterComboBox->setItemText(0, QCoreApplication::translate("ChatWindow", "\320\234\320\276\321\200\320\267\320\265", nullptr));
        enterComboBox->setItemText(1, QCoreApplication::translate("ChatWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));

        flipButton->setText(QCoreApplication::translate("ChatWindow", "<->", nullptr));
        resultComboBox->setItemText(0, QCoreApplication::translate("ChatWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        resultComboBox->setItemText(1, QCoreApplication::translate("ChatWindow", "\320\234\320\276\321\200\320\267\320\265", nullptr));

        enterTranslateTextEdit->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265...", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatWindow", "\320\222 \320\274\320\265\320\275\321\216", nullptr));
        copyButton->setText(QCoreApplication::translate("ChatWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pasteButton->setText(QCoreApplication::translate("ChatWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\270\320\267 \320\261\321\203\321\204\320\265\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
