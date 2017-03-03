#ifndef DAO_H
#define DAO_H
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>
#include<Student.h>
#include<DatabaseConnection.h>
#include<list>
#include<Util.h>
using namespace std;

class StudentDAO
{
public:
    StudentDAO();
    bool insert(Student student);//写入学生
    list<Student> findAll();//取得所有学生列表
    Student findById(string id);//用学号寻找学生
    bool deleteById(string id);//用学号删除学生
    bool update(Student student);//跟新学生
    bool queryById(string id);//用学号查找学生
    Student findByUId(string uid);//用卡号查找学生
};

#endif // DAO_H
