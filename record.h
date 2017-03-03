#ifndef RECORD_H
#define RECORD_H


#include<string>
#include<sstream>
#include<qdatetime.h>
using namespace std;
class Record
{
    int id;
    string startTime;
    string endTime;
    float count;
    string stuId;

public:
    Record();
    Record(const string startTime, const string endTime);
    Record(const Record &re);

    void setStartTime(string startTime);//设置开始时间
    void setEndTime(string endTime);//设置结束时间

    string getStartTime();//获取开始时间
    string getEndTime();//获取结束时间
    void setId(int id);//设置学号
    int getId();//获得学号

    void setStuId(string stuId);//设置卡号
    string getStuId();//获得卡号

    void setCount(float count);
    float getCount();
    string toString();
};
#endif // RECORD_H
