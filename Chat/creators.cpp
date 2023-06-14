#include "creators.h"
#include "ui_creators.h"

creators::creators(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creators)
{
    ui->setupUi(this);
}

creators::~creators()
{
    delete ui;
}

void creators::on_pushButton_clicked()
{
    this->close();
}
