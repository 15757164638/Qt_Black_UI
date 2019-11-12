#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile styleFile(":/style/style.qss");
    if(styleFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open success";
        QString setStyleSheet(styleFile.readAll());
        a.setStyleSheet(setStyleSheet);
        styleFile.close();
    }
    else
    {
        qDebug()<<"open faild";
    }
    w.show();
    return a.exec();
}
