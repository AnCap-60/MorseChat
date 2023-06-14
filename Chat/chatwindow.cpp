#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <map>
#include <iostream>
#include <QTime>

ChatWindow::ChatWindow(QWidget *parent) : //конструктор окна
    QMainWindow(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    connect (ui->dashButton, SIGNAL(clicked()), this, SLOT(addingSymbols()));
    connect (ui->doteButton, SIGNAL(clicked()), this, SLOT(addingSymbols()));
    connect (ui->slashButton, SIGNAL(clicked()), this, SLOT(addingSymbols()));

    connect (ui->spaceButton, SIGNAL(clicked()), this, SLOT(addingSpacer()));

    connect (ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteSymbols()));

    connect (ui->deleteButton, SIGNAL(clicked), this, SLOT(newMessage()));

    connect(ServerAPI::GetInstance(), &ServerAPI::NewMessage, this, &ChatWindow::newMessage);
}

ChatWindow::~ChatWindow() //деструктор окна
{
    delete ui;
}

void ChatWindow::on_sendButton_clicked()
{
    QString message = ui->lineEdit->text();
    bool flag = false;

    message = leadToMorze(message);
    flag = validateMorze(message);

    if (flag == false)
    {
        leadToMorze(message);
        //ui->textEdit->append(message);
        ServerAPI::GetInstance()->SendToServer(ui->lineEdit->text());
    }
    else
    {
        QMessageBox::about(this, "Ошибка!", "Вы ввели не азбуку Морзе!");
    }

    ui->lineEdit->clear();


}

void ChatWindow::newMessage(QTime Time, QString message)
{
    QString time = Time.toString();
    time += ' ' + message;

    ui->textEdit->append(time);
}

void ChatWindow::addingSymbols() //обработчик нажатия на кнопки "-", ".", "/"
{
    QPushButton *button = (QPushButton *)sender();
    QString string;

    string = ui->lineEdit->text() + button->text();
    ui->lineEdit->setText(string);
}

void ChatWindow::deleteSymbols() //обработчик нажатия на кнопку "Удалить"
{
    ui->lineEdit->backspace();
}

void ChatWindow::addingSpacer() //обработчик нажатия на кнопку "Пробел"
{
    QString string;

    string = ui->lineEdit->text() + ' ';
    ui->lineEdit->setText(string);
}

void ChatWindow::keyPressEvent(QKeyEvent *e) //обработчик нажатия на клавиши клавиатуры для заполнения "морзянки"
{
    QString string;

    if (e->key() == Qt::Key_Slash)
    {
        string = ui->lineEdit->text() + '/';
        ui->lineEdit->setText(string);
    }
    if (e->key() == Qt::Key_Period)
    {
        string = ui->lineEdit->text() + '.';
        ui->lineEdit->setText(string);
    }
    if (e->key() == Qt::Key_Backspace)
    {
        deleteSymbols();
    }
    if (e->key() == Qt::Key_Minus)
    {
        string = ui->lineEdit->text() + ui->dashButton->text();
        ui->lineEdit->setText(string);
    }
    if (e->key() == Qt::Key_Space)
    {
        addingSpacer();
    }
}

QString ChatWindow::orderMorzeToRussian(QString now) //перевод "морзянки" на русский
{
    std::map <QString, QString> morzeDictionary;
    QString result;

    morzeDictionary[".-"] = "А";
    morzeDictionary["-..."] = "Б";
    morzeDictionary[".--"] = "В";
    morzeDictionary["--."] = "Г";
    morzeDictionary["-.."] = "Д";
    morzeDictionary["."] = "Е";
    morzeDictionary["...-"] = "Ж";
    morzeDictionary["--.."] = "З";
    morzeDictionary[".."] = "И";
    morzeDictionary[".---"] = "Й";
    morzeDictionary["-.-"] = "К";
    morzeDictionary[".-.."] = "Л";
    morzeDictionary["--"] = "М";
    morzeDictionary["-."] = "Н";
    morzeDictionary["---"] = "О";
    morzeDictionary[".--."] = "П";
    morzeDictionary[".-."] = "Р";
    morzeDictionary["..."] = "С";
    morzeDictionary["-"] = "Т";
    morzeDictionary["..-"] = "У";
    morzeDictionary["..-."] = "Ф";
    morzeDictionary["...."] = "Х";
    morzeDictionary["-.-."] = "Ц";
    morzeDictionary["---."] = "Ч";
    morzeDictionary["----"] = "Ш";
    morzeDictionary["--.-"] = "Щ";
    morzeDictionary[".--.-."] = "Ъ";
    morzeDictionary["-.--"] = "Ы";
    morzeDictionary["-..-"] = "Ь";
    morzeDictionary["...-..."] = "Э";
    morzeDictionary["..--"] = "Ю";
    morzeDictionary[".-.-"] = "Я";

    if (morzeDictionary[now] != "")
        result = morzeDictionary[now];
    else
        result = "not exist";

    return result;
}

QString ChatWindow::orderRussianToMorze(QChar now) //перевод русской буквы на Морзе
{
    std::map <QString, QString> morzeDictionary;
    QString result;

    morzeDictionary["А"] = ".-";
    morzeDictionary["Б"] = "-...";
    morzeDictionary["В"] = ".--";
    morzeDictionary["Г"] = "--.";
    morzeDictionary["Д"] = "-..";
    morzeDictionary["Е"] = ".";
    morzeDictionary["Ж"] = "...-";
    morzeDictionary["З"] = "--..";
    morzeDictionary["И"] = "..";
    morzeDictionary["Й"] = ".---";
    morzeDictionary["К"] = "-.-";
    morzeDictionary["Л"] = ".-..";
    morzeDictionary["М"] = "--";
    morzeDictionary["Н"] = "-.";
    morzeDictionary["О"] = "---";
    morzeDictionary["П"] = ".--.";
    morzeDictionary["Р"] = ".-.";
    morzeDictionary["С"] = "...";
    morzeDictionary["Т"] = "-";
    morzeDictionary["У"] = "..-";
    morzeDictionary["Ф"] = "..-.";
    morzeDictionary["Х"] = "....";
    morzeDictionary["Ц"] = "-.-.";
    morzeDictionary["Ч"] = "---.";
    morzeDictionary["Ш"] = "----";
    morzeDictionary["Щ"] = "--.-";
    morzeDictionary["Ъ"] = ".--.-.";
    morzeDictionary["Ы"] = "-.--";
    morzeDictionary["Ь"] = "-..-";
    morzeDictionary["Э"] = "...-...";
    morzeDictionary["Ю"] = "..--";
    morzeDictionary["Я"] = ".-.-";

    if (morzeDictionary[now] != "")
        result = morzeDictionary[now];
    else
        result = "not exist";

    return result;
}

QString ChatWindow::translateMessageToRussian(QString originalMessage) //перевести все сообщение на русский
{
    QString letterArray, letter, wordArray, messageArray;
    QChar symbol;

    messageArray = "";

    for (int i = 0; i < originalMessage.size(); i++)
    {
        symbol = originalMessage[i];

        if ((symbol == '.') || (symbol == '-'))
        {
            letterArray += symbol;
        }
        else
        {
            if (symbol == ' ')
            {
                letter = orderMorzeToRussian(letterArray);
                wordArray += letter;
                letterArray = "";
            }
            else
            {
                letter = orderMorzeToRussian(letterArray);
                wordArray += letter;
                messageArray = messageArray + wordArray + ' ';
                wordArray = "";
                letterArray = "";
            }
        }
    }

    if ((symbol != ' ') && (symbol != '/'))
    {
        letter = orderMorzeToRussian(letterArray);
        wordArray += letter;
        messageArray = messageArray + wordArray;
        wordArray = "";
        letterArray = "";
    }
    else
    {
        messageArray += wordArray;
    }

    return messageArray;
}

QString ChatWindow::translateMessageToMorze(QString originalMessage) //перевести все сообщение на Морзе
{
    QString message, letter;

    for (int i = 0; i+1 < originalMessage.size(); i++)
    {
        if (originalMessage[i] != ' ')
        {
            if (originalMessage[i+1] == ' ')
            {
                letter = orderRussianToMorze(originalMessage[i]);
                message += letter;
            }
            else
            {
                letter = orderRussianToMorze(originalMessage[i]);
                message += letter + ' ';
            }
        }
        else
        {
            message += '/';
        }
    }

    letter = orderRussianToMorze(originalMessage[originalMessage.size() - 1]);
    message += letter;

    return message;
}

bool ChatWindow::validateMorze(QString message) //проверка на соответствие сообщения правилам для этой программы
{
    QString order="";
    bool flag = false;

    if ((message.contains('.') == false) && (message.contains('-') == false)) //проверка на символы "." и "-", т.к. послед-ть Морзе без них не может быть задана
    {
        flag = true;
        return flag;
    }

    for (int i = 0; i < message.size(); i++) //проверка на существование каждой последовательности Морзе
    {
        if ((message[i] != ' ') && (message[i] != '/'))
        {
            order += message[i];
        }
        else
        {
            if(message[i] == ' ')
            {
                if (orderMorzeToRussian(order) == "not exist")
                {
                    flag = true;
                    break;
                }
                else
                    order = "";
            }
            if (message[i] == '/')
            {
                if (orderMorzeToRussian(order) == "not exist")
                {
                    flag = true;
                    break;
                }
                else
                    order = "";
            }
        }
    }

    if (flag == false) //проверка последней оставшейся последовательности
    {
        if (orderMorzeToRussian(order) == "not exist")
            flag = true;
    }

    return flag;
}

bool ChatWindow::validateRussian(QString message) //проверка на соответствие сообщения правилам для этой программы
{
    bool flag = false;

    if (message == "not a string")
    {
        flag = true;
        return flag;
    }

    for (int i = 0; i < message.size(); i++)
    {
        auto c = message.right(message.size() - i).left(1);
        
        if ((c != "А") && (c != "Б") && (c!= "В") && (c != "Г") && (c != "Д") && (c != "Е")
                && (c != "Ж") && (c != "З") && (c != "И") && (c != "Й") && (c != "К") && (c != "Л")
                && (c != "М") && (c != "Н") && (c != "О") && (c != "П") && (c != "Р") && (c != "С")
                && (c != "Т") && (c != "У") && (c != "Ф") && (c != "Х") && (c != "Ц") && (c != "Ч")
                && (c != "Ш") && (c != "Щ") && (c != "Ъ") && (c != "Ы") && (c != "Ь") && (c != "Э")
                && (c != "Ю") && (c != "Я") && (c != " "))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

QString ChatWindow::leadToMorze(QString message) //метод для приведения последовательности Морзе в оптимальный для программы вид
{
    if (message[0] == ' ') //убрать один/несколько первых пробелов
    {
        int index = 0, count = 0;

        for (int i = 1; message[i] == ' '; i++)
        {
            index = i;
        }

        ++index;

        for (int i = index; i < message.size(); i++)
        {
            message [i - index] = message[i];
            count++;
        }

        message.remove(count, index);
    }

    for (int i = 0; i < message.size(); i++) //убрать несколько пробелов в середине сообщения
    {
        if ((message[i] == ' ') && (message[i+1] == ' '))
        {
            int j = i;
            while (message[j+1] == ' ')
            {
                message.remove(j+1, 1);
            }
        }
    }

    for (int i = 0; i < message.size(); i++) //убрать несколько слешей в середине сообщения
    {
        if ((message[i] == '/') && (message[i+1] == '/'))
        {
            int j = i;
            while (message[j+1] == '/')
            {
                message.remove(j+1, 1);
            }
        }
    }

    for (int i = 0; i < message.size(); i++) //убрать пробелы рядом со слешем
    {
        if ((message[i] == ' ') && ((message[i+1] == '/') || (message[i-1] == '/')))
        {
            message.remove(i, 1);
        }
    }

    return message;
}

QString ChatWindow::leadToRussian(QString message) //метод для приведения последовательности на русском в оптимальный для программы вид
{
    if (message == "")
        return "not a string";

    if (message[0] == ' ') //убрать один/несколько первых пробелов
    {
        int index = 0, count = 0;

        for (int i = 1; message[i] == ' '; i++)
        {
            index = i;
        }

        ++index;

        for (int i = index; i < message.size(); i++)
        {
            message [i - index] = message[i];
            count++;
        }

        message.remove(count, index);
    }

    for (int i = 0; i < message.size(); i++) //убрать несколько пробелов в середине сообщения
    {
        if ((message[i] == ' ') && (message[i+1] == ' '))
        {
            int j = i;
            while (message[j+1] == ' ')
            {
                message.remove(j+1, 1);
            }
        }
    }

    if (message[message.size() - 1] == ' ')
    {
        message.remove(message.size() - 1, 1);
    }

    return message;
}

void ChatWindow::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.select(QTextCursor::LineUnderCursor);
    ui->textEdit->copy();
    ui->textEdit->setTextCursor(cursor);
}

void ChatWindow::on_translateButton_clicked()
{
    QString selected1, selected2, result;

    selected1 = ui->enterComboBox->currentText();
    selected2 = ui->resultComboBox->currentText();

    QString message = ui->enterTranslateTextEdit->text();

    if ((selected1 != selected2) && (message != ""))
    {
        if ((selected1 == "Морзе") && (selected2 == "Русский"))
        {
            message = leadToMorze(message);

            if (validateMorze(message) == false)
            {
                result = translateMessageToRussian(message);
                ui->resultTranslateTextEdit->setText(result);
            }
            else
            {
                QMessageBox::about(this,"Ошибка!","Введена не последовательность Морзе");
                ui->enterTranslateTextEdit->clear();
                ui->resultTranslateTextEdit->clear();
            }
        }
        if ((selected1 == "Русский") && (selected2 == "Морзе"))
        {
            QString message = ui->enterTranslateTextEdit->text();
            message = leadToRussian(message);

            if (validateRussian(message) == false)
            {
                result = translateMessageToMorze(message);
                ui->resultTranslateTextEdit->setText(result);
            }
            else
            {
                QMessageBox::about(this,"Ошибка!","Введенный текст не на русском языке");
                ui->enterTranslateTextEdit->clear();
                ui->resultTranslateTextEdit->clear();
            }
        }
    }
    else
    {
        if (selected1 == selected2)
        {
            QMessageBox::about(this,"Ошибка!","Выбраны одинаковые языки!");
        }
        else
            QMessageBox::about(this,"Ошибка!","Ничего не введено!");
    }
}

void ChatWindow::on_flipButton_clicked()
{
    QString enter, result;

    enter = ui->enterComboBox->currentText();
    result = ui->resultComboBox->currentText();

    ui->enterComboBox->setCurrentText(result);
    ui->resultComboBox->setCurrentText(enter);

    enter = ui->enterTranslateTextEdit->text();
    result = ui->resultTranslateTextEdit->text();

    ui->enterTranslateTextEdit->setText(result);
    ui->resultTranslateTextEdit->setText(enter);
}

void ChatWindow::on_enterTranslateTextEdit_textEdited()
{
    ui->resultTranslateTextEdit->clear();
}

void ChatWindow::on_pushButton_clicked()
{
    this->close();
    emit mainWindow();
}
