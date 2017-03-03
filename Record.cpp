#include "Record.h"

Record::Record(){}

Record::Record(const string startTime, const string endTime)
{
    this->startTime=startTime;
    this->endTime=endTime;
}

Record::Record(const Record &re)
{
    id = re.id;
    startTime = re.startTime;
    endTime = re.endTime;
    count = re.count;
    stuId = re.stuId;
}

void Record::setStartTime(string startTime)
{
    this->startTime=startTime;

}

void Record::setEndTime(string endTime)
{
    this->endTime=endTime;
}

string Record::getStartTime()
{
    return this->startTime;
}

string Record::getEndTime()
{
    return this->endTime;
}

void Record::setId(int id)
{
    this->id=id;
}

int Record::getId()
{
    return this->id;
}

void Record::setStuId(string stuId)
{
    this->stuId=stuId;
}

string Record::getStuId()
{
    return this->stuId;
}

void Record::setCount(float count)
{
    this->count=count;

}

float Record::getCount()
{
    return this->count;
}

string Record::toString()
{
    string str;
    stringstream ss;
    ss<<this->count;

    if(this->endTime.empty())
    str.append(this->startTime+"    "+"未签退"+"   "+"打卡失败");
    else str.append(this->startTime+"    "+this->endTime+"   "+ss.str());
    return str;
}
