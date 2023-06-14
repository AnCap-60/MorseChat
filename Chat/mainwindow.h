#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatwindow.h"
#include "creators.h"

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

private:
    Ui::MainWindow *ui;
    ChatWindow *chatwindow;
    creators creatorswidget;
};

#endif // MAINWINDOW_H
