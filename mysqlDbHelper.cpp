#include "mysqlDbHelper.h"
#include <windows.h>
#include<iostream>
#include<string>
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>

using namespace std;

 mysqlDbHelper::mysqlDbHelper()
{

};

 QSqlDatabase mysqlDbHelper::connectMysql() {
     QSqlDatabase dbSQL=QSqlDatabase::addDatabase("QMYSQL");
     dbSQL.setHostName("127.0.0.1");
     dbSQL.setPort(3306);
     dbSQL.setDatabaseName("test");
     dbSQL.setUserName("root");
     dbSQL.setPassword("sa123456");
     if(
     !dbSQL.open()
     )
     {
     qDebug()<<"this,warning,failure";
     }
     else
     {
     qDebug()<<"this,ok,success";
     }
     return dbSQL;
 }
