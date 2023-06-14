#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <map>
#include <QTime>
#include <cstring>

#include "../Server/headers/ServerAPI.h"

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

    void newMessage(QTime time, QString message);

    void on_sendButton_clicked();
    void on_translateButton_clicked();
    void on_flipButton_clicked();

    void on_textEdit_cursorPositionChanged();
    void on_enterTranslateTextEdit_textEdited();

    void on_pushButton_clicked();

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

signals:
    void mainWindow();
};

#endif // CHATWINDOW_H
