#include "Student.h"
Student::Student(){}
Student::Student(const Student &stu) {
    new (this)Student(stu.Marjor,stu.Id,stu.Name,stu.uid);
}

Student::Student(const string major, const string id, const string name)
{
    new (this)Student(major,id,name,"");
}

Student::Student(const string major, const string id, const string name, const string uid)
{
    this->Marjor = major;
    this->Id = id;
    this->Name = name;
    this->uid=uid;
}

void Student::setMarjor(const string &major)
{
    this->Marjor = major;
}

void Student::setId(const string &id)
{
    this->Id = id;
}

void Student::setName(const string &name)
{
    this->Name = name;
}

void Student::setUId(const string uid)
{
    this->uid=uid;
}

string Student::getMarjor()
{
    return this->Marjor;
}

string Student::getId()
{
    return this->Id;
}

string Student::getName()
{
    return this->Name;
}

string Student::getUId()
{
    return this->uid;
}

void Student::pushRecord(Record record)
{
    this->records.push_back(record);
}

list<Record> Student::getRecords()
{
    return this->records;
}

void Student::setRecords(list<Record> records)
{
    this->records = records;
}

string Student::toString()
{
    string str;
    str.append("[Id=" + this->Id);
    str.append(",Name=" + this->Name);
    str.append(",Major=" + this->Marjor);
    str.append("]");
    return str;
}
