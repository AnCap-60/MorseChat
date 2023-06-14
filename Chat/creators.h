#ifndef CREATORS_H
#define CREATORS_H

#include <QWidget>

namespace Ui {
class creators;
}

class creators : public QWidget
{
    Q_OBJECT

public:
    explicit creators(QWidget *parent = nullptr);
    ~creators();

private slots:
    void on_pushButton_clicked();

private:
    Ui::creators *ui;
};

#endif // CREATORS_H
