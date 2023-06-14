#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Server/headers/ServerAPI.h"
#include <QMainWindow>
#include "chatwindow.h"
#include "creators.h"
#include "about.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

    void on_creatorsButton_clicked();

    void on_roolsButton_clicked();

private:
    Ui::MainWindow *ui;
    ChatWindow *chatwindow;
    creators creatorswidget;
    about aboutwindow;
};

#endif // MAINWINDOW_H
