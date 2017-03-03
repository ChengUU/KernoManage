#ifndef RECORDDAO_H
#define RECORDDAO_H
#include<Record.h>
#include<QCoreApplication>
#include<QDebug>
#include<QtCore>
#include<QtSql>
#include<DatabaseConnection.h>
#include<list>
#include<Util.h>


class RecordDao
{
public:
    RecordDao();
    bool insert(Record record);//插入数据
    list<Record> findAll();//寻找所有
    Record findById(string id);//靠id寻找人

    bool deleteById(string id);//用ID删除。Id是记录的id。
    bool update(Record record);//管理员设置数据升级数据

    list<Record> queryByStuId(string id);//查找学生学号记录
    list<Record> queryByStuIdDesc(string id);
    Record findLastByStuId(string stuid);//靠id寻找人
    string queryCountByStuId(string stuid);
};

#endif // RECORDDAO_H
