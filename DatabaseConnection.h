#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>
#include<string>
using namespace std;

class DatabaseConnection
{
    QString DATABASE_NAME;
    QString hostName;
    int port;
    QString databaseName;
    QString userName;
    QString pwd;
public:
    DatabaseConnection();
    DatabaseConnection(const string DATABASE_NAME,string hostName,int port,string databaseName,string userName,string pwd);
    static QSqlDatabase getConnection();
    static bool close(QSqlDatabase dbSQL);
};

#endif // DATABASECONNECTION_H
