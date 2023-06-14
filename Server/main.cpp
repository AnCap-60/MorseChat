#include <QtCore/QCoreApplication>

#include "headers/Server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    return a.exec();
}
