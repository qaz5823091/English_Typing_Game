#include "mainwindow.h"
#include "menu.h"

#include <QApplication>

#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu m;
    // fixed size window
    m.setFixedSize(m.width(), m.height());
    m.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
