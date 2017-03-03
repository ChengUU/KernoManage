#include "maindialog.h"
#include <QApplication>
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainDialog w;
    w.show();
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    return a.exec();
}
