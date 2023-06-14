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
    ServerAPI::ConnectToServer("192.168.1.107");

    chatwindow->show();
    this->close();
}

void MainWindow::on_creatorsButton_clicked()
{
    creatorswidget.show();
}
