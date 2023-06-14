/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *enterButton;
    QPushButton *creatorsButton;
    QPushButton *roolsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 630);
        MainWindow->setMinimumSize(QSize(500, 630));
        MainWindow->setMaximumSize(QSize(500, 630));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 3, 250);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        enterButton = new QPushButton(centralWidget);
        enterButton->setObjectName("enterButton");
        enterButton->setGeometry(QRect(130, 130, 241, 81));
        QFont font;
        font.setPointSize(14);
        enterButton->setFont(font);
        enterButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255,180,80);\n"
"color:white;"));
        creatorsButton = new QPushButton(centralWidget);
        creatorsButton->setObjectName("creatorsButton");
        creatorsButton->setGeometry(QRect(130, 330, 241, 81));
        creatorsButton->setFont(font);
        creatorsButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255,180,80);\n"
"color:white;"));
        roolsButton = new QPushButton(centralWidget);
        roolsButton->setObjectName("roolsButton");
        roolsButton->setGeometry(QRect(130, 230, 241, 81));
        roolsButton->setFont(font);
        roolsButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255,180,80);\n"
"color:white;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MorseChat", nullptr));
        enterButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270 \320\262 \321\207\320\260\321\202", nullptr));
        creatorsButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\320\265\320\273\320\270", nullptr));
        roolsButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260 \320\260\320\267\320\261\321\203\320\272\320\270 \320\234\320\276\321\200\320\267\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
