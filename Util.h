#ifndef UTIL_H
#define UTIL_H
#include<string>
#include<QString>
#include<QTextBrowser>
#include<record.h>
#include<list>
using namespace std;


class Util
{
public:
    Util();
    static string toStdString(QString str);
    static QString toQString(string str);
    //UID相关操作
    static string convert(const unsigned char* bits,int len);//将uid转换成字符串
    static string stringValue(int number);//辅助covert进行uid的转换
    static string calStrUId(const unsigned char *u, const int len);
    static void setRecords(QTextBrowser* obj,list<Record> records,string strRecord);
};

#endif // UTIL_H
