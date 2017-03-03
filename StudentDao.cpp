#include "StudentDao.h"

StudentDAO::StudentDAO(){}

bool StudentDAO::insert(Student student)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
     if(!dbSQL.isOpen()) return false;
    //construct the database query object
    QSqlQuery query;
    query.prepare("insert  into studentInfo(studentID,name,major,UID) values(?,?,?,?)");
    query.bindValue(0,Util::toQString(student.getId()));
    query.bindValue(1,Util::toQString(student.getName()));
    query.bindValue(2,Util::toQString(student.getMarjor()));
    query.bindValue(3,Util::toQString(student.getUId()));
    //get the result of execute the query string
    bool succ=query.exec();
    if(succ) qDebug()<<"插入成功";
    else qDebug()<<"插入失败"<<query.lastError();
    return succ;
}

list<Student> StudentDAO::findAll()
{
    list<Student> students;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("select * from studentInfo");
    //get the result of execute the query string
    bool succ=query.exec();
    int numRows=succ?0:-1;
    if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
        numRows=query.size();
    } else{
        query.last();
        numRows=query.at()+1;
    }
    Student stu;
    while(query.next()){
        stu.setId(query.value(0).toString().toStdString());
        stu.setName(query.value(1).toString().toStdString());
        stu.setMarjor(query.value(2).toString().toStdString());
        stu.setUId(query.value(3).toString().toStdString());
        students.push_back(stu);
    }
    DatabaseConnection::close(dbSQL);
    return students;
}

Student StudentDAO::findById(string id)
{
     Student stu;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
     if(!dbSQL.isOpen()) return stu;
    //construct the database query object
    QSqlQuery query;
    query.prepare("select  * from studentInfo where studentID=?");
    query.bindValue(0,QString::fromStdString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    if(!succ) return stu;
    if(query.next()){
        stu.setId(query.value(0).toString().toStdString());
        stu.setName(query.value(1).toString().toStdString());
        stu.setMarjor(query.value(2).toString().toStdString());
        stu.setUId(query.value(3).toString().toStdString());
    }
    DatabaseConnection::close(dbSQL);
    return stu;
}

bool StudentDAO::deleteById(string id)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("delete from studentInfo where studentID=?");
    query.bindValue(0,Util::toQString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    DatabaseConnection::close(dbSQL);
    return succ;

}

bool StudentDAO::update(Student student)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("update studentInfo set name=?,major=?,UID=? where studentID=?");
    query.bindValue(3,Util::toQString(student.getId()));
    query.bindValue(0,Util::toQString(student.getName()));
    query.bindValue(1,Util::toQString(student.getMarjor()));
    query.bindValue(2,Util::toQString(student.getUId()));
    //get the result of execute the query string
    bool succ=query.exec();
    DatabaseConnection::close(dbSQL);
    return succ;
}

bool StudentDAO::queryById(string id)
{
    bool flag=false;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
     if(!dbSQL.isOpen()) return flag;
    //construct the database query object
    QSqlQuery query;
    query.prepare("select  * from studentInfo where studentID=?");
    query.bindValue(0,QString::fromStdString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    if(!succ) return flag;
    if(query.next())flag=true;
    DatabaseConnection::close(dbSQL);
    return flag;
}

Student StudentDAO::findByUId(string uid)
{
    Student stu;
   //get database connection
    QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    if(!dbSQL.isOpen()) return stu;
   //construct the database query object
   QSqlQuery query;
   query.prepare("select  * from studentInfo where UID=?");
   query.bindValue(0,QString::fromStdString(uid));
   //get the result of execute the query string
   bool succ=query.exec();
   if(!succ) return stu;
   if(query.next()){
       stu.setId(query.value(0).toString().toStdString());
       stu.setName(query.value(1).toString().toStdString());
       stu.setMarjor(query.value(2).toString().toStdString());
       stu.setUId(query.value(3).toString().toStdString());
   }
   DatabaseConnection::close(dbSQL);
   return stu;
}
