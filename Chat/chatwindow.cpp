#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <map>
#include <iostream>

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
        ui->textBrowser->append(message);
    }
    else
    {
        QMessageBox::about(this, "Ошибка!", "Вы ввели не азбуку Морзе!");
    }

    ui->lineEdit->clear();
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

void ChatWindow::on_translateToMorzeButton_clicked() //обработчик нажатия на кнопку перевода
{
    if (ui->lineEdit->text() != "")
    {
        if (validateRussian(ui->lineEdit->text()) == false)
        {
            ui->translateToRussianButton->show();
            ui->translateToMorzeButton->hide();

            QString res = translateMessageToMorze(ui->lineEdit->text());
            ui->lineEdit->setText(res);
        }
        else
        {
            QMessageBox::about(this, "Ошибка!", "Введен текст не на русском языке");
            ui->lineEdit->clear();
        }
    }
    else
    {
        ui->translateToRussianButton->show();
        ui->translateToMorzeButton->hide();
    }
}

void ChatWindow::on_translateToRussianButton_clicked() //обработчик нажатия на кнопку перевода
{
    if (ui->lineEdit->text() != "")
    {
        if (validateMorze(ui->lineEdit->text()) == false)
        {
            ui->translateToMorzeButton->show();
            ui->translateToRussianButton->hide();

            QString res = translateMessageToRussian(ui->lineEdit->text());
            ui->lineEdit->setText(res);
        }
        else
        {
            QMessageBox::about(this, "Ошибка!", "Введена не последовательность Морзе");
            ui->lineEdit->clear();
        }
    }
    else
    {
        ui->translateToMorzeButton->show();
        ui->translateToRussianButton->hide();
    }

}

void ChatWindow::on_clearButton_clicked() //очищение строки ввода сообщения
{
    ui->lineEdit->clear();
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

    for (int i = 0; i < message.size(); i++)
    {
        if ((message[i] != "А") && (message[i] != "Б") && (message[i] != "В") && (message[i] != "Г") && (message[i] != "Д") && (message[i] != "Е")
                && (message[i] != "Ж") && (message[i] != "З") && (message[i] != "И") && (message[i] != "Й") && (message[i] != "К") && (message[i] != "Л")
                && (message[i] != "М") && (message[i] != "Н") && (message[i] != "О") && (message[i] != "П") && (message[i] != "Р") && (message[i] != "С")
                && (message[i] != "Т") && (message[i] != "У") && (message[i] != "Ф") && (message[i] != "Х") && (message[i] != "Ц") && (message[i] != "Ч")
                && (message[i] != "Ш") && (message[i] != "Щ") && (message[i] != "Ъ") && (message[i] != "Ы") && (message[i] != "Ь") && (message[i] != "Э")
                && (message[i] != "Ю") && (message[i] != "Я") && (message[i] != ' '))
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


    return message;
}

void ChatWindow::on_testButton_clicked()
{

}
