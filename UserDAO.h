#ifndef DAO_H
#define DAO_H
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>

class UserDAO
{
public:
    DAO();
    virtual bool insert()=0;
    virtual list findAll()=0;
    virtual void findById(string id)=0;
    virtual bool deleteById(string id)=0;
    virtual bool update()=0;
};

#endif // DAO_H
