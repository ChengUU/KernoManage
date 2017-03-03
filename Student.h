#pragma once
#include<iostream>
#include<list>

#include"Record.h"
using namespace std;


class Student
{
    string Marjor;
    string Id;
    string Name;
    string uid;
    list<Record> records;

public:
    Student();
    Student(const string major, const string id, const string name, const string uid);
    Student(const Student &stu);
    Student(const string major, const string id, const string name);

    void setMarjor(const string &major);
    void setId(const string &id);
    void setName(const string &name);
    void setUId(const string uid);

    string getMarjor();
    string getId();
    string getName();
    string getUId();


    void pushRecord(Record record);//放入学生数据
    list<Record> getRecords();//获得学生数据
    void setRecords(list<Record> records);//设置学生数据
    string toString();//打印把学生数据整理成string
};
