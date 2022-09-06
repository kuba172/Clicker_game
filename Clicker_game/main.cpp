#include "mainwindow.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu *menu = new Menu(600,400);

    menu->show();
    return a.exec();
}


