#include <QCoreApplication>
#include "server.h"
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);
    Server s;
    return a.exec();
}
