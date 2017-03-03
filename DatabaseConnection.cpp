#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection()
{
    DatabaseConnection("QMYSQL","127.0.0.1",3306,"test","root","sa123456");
}

DatabaseConnection::DatabaseConnection(const string DATABASE_NAME, string hostName, int port, string databaseName, string userName, string pwd)
{
    this->DATABASE_NAME=QString::fromStdString(DATABASE_NAME);
    this->hostName=QString::fromStdString(hostName);
    this->port=port;
    this->databaseName=QString::fromStdString(databaseName);
    this->userName=QString::fromStdString(userName);
    this->pwd=QString::fromStdString(pwd);
}

QSqlDatabase DatabaseConnection::getConnection()
{
    QSqlDatabase dbSQL;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      dbSQL = QSqlDatabase::database("qt_sql_default_connection");
    else
      dbSQL = QSqlDatabase::addDatabase("QMYSQL");
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

bool DatabaseConnection::close(QSqlDatabase dbSQL)
{
    if(dbSQL.isOpen()) dbSQL.close();
    return dbSQL.isOpen();
}
