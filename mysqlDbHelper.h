#pragma once
#include<windows.h>
#include <QtSql>
#include<string>
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>
#include<Student.h>
using namespace std;
class mysqlDbHelper
{
public:
	mysqlDbHelper();
    QSqlDatabase connectMysql();
	void show();
	void clearSignrecord();
    Student showByUId(string UId);
};

