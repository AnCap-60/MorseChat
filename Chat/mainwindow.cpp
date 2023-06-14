#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chatwindow = new ChatWindow();
    connect (chatwindow, &ChatWindow::mainWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterButton_clicked()
{
    chatwindow->show();
    this->close();
}

void MainWindow::on_creatorsButton_clicked()
{
    creatorswidget.show();
}

void MainWindow::on_roolsButton_clicked()
{
    aboutwindow.show();
}
