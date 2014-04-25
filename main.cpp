#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //QWidget *window = new QWidget;

    MainWindow window;
    QWidget *Inputwidget = new QWidget;
    window.InputWindowSetup(Inputwidget);

    Inputwidget->show();
    
    return a.exec();
}
