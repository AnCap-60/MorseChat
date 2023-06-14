/********************************************************************************
** Form generated from reading UI file 'creators.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATORS_H
#define UI_CREATORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creators
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *creators)
    {
        if (creators->objectName().isEmpty())
            creators->setObjectName("creators");
        creators->resize(500, 630);
        creators->setMinimumSize(QSize(500, 630));
        creators->setMaximumSize(QSize(500, 630));
        creators->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 3, 250);"));
        label = new QLabel(creators);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 160, 141, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(creators);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 250, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        label_3 = new QLabel(creators);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 250, 161, 71));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(creators);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 340, 141, 71));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(creators);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 590, 101, 31));
        QFont font2;
        font2.setPointSize(13);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 180, 80); color:white"));

        retranslateUi(creators);

        QMetaObject::connectSlotsByName(creators);
    } // setupUi

    void retranslateUi(QWidget *creators)
    {
        creators->setWindowTitle(QCoreApplication::translate("creators", "\320\241\320\276\320\267\320\264\320\260\321\202\320\265\320\273\320\270", nullptr));
        label->setText(QCoreApplication::translate("creators", "\320\241\320\276\320\267\320\264\320\260\321\202\320\265\320\273\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("creators", "\320\232\320\270\321\200\320\270\320\273\320\273\320\276\320\262 \320\237\320\260\320\262\320\265\320\273", nullptr));
        label_3->setText(QCoreApplication::translate("creators", "\320\245\320\276\321\205\320\273\320\276\320\262 \320\234\320\260\320\272\321\201\320\270\320\274", nullptr));
        label_4->setText(QCoreApplication::translate("creators", "\320\236716\320\221", nullptr));
        pushButton->setText(QCoreApplication::translate("creators", "\320\222 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creators: public Ui_creators {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATORS_H
