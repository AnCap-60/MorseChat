#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <map>
#include <QTime>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void addingSymbols();
    void deleteSymbols();
    void addingSpacer();

    void on_translateToMorzeButton_clicked();
    void on_clearButton_clicked();
    void on_translateToRussianButton_clicked();
    void on_testButton_clicked();
    void on_sendButton_clicked();

    void newMessage(QTime time, QString message);

private:
    Ui::ChatWindow *ui;
    QString orderMorzeToRussian(QString now);
    QString orderRussianToMorze(QChar now);
    QString translateMessageToRussian(QString originalMessage);
    QString translateMessageToMorze(QString originalMessage);

    bool validateMorze(QString message);
    bool validateRussian(QString message);

    QString leadToMorze(QString message);
    QString leadToRussian(QString message);

protected:
    void keyPressEvent(QKeyEvent *e) override;
};

#endif // CHATWINDOW_H
