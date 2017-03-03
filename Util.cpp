#include "Util.h"

Util::Util(){}

string Util::toStdString(QString str)
{
    return str.toStdString();
}

QString Util::toQString(string str)
{
    return QString::fromStdString(str);
}
string Util::convert(const unsigned char*  bits,int len) {
    string res = "";
    for (int i = 0; i < len; i++)
    {
        int bit = (int)bits[i] % 128;
        /*
        0 - 9;
        10 - 99;
        100 - 127;*/
        //目标字符串长度判断
        res+=Util::stringValue(bit);
    }
    return res;
}
string Util::stringValue(int number) {
    string res="";
    string temp = "";
    //将数字转换成字符串
    do{
        temp += number % 10 + '0';
        number /= 10;
    } while (0 != number);

    //cout << "temp:" << temp.c_str();
    //字符串反转,取得数字原始顺序
    int len=temp.length();
    //对齐长度
    switch (len) {
    case 1:res+="00"; break;
    case 2:res+="0"; break;
    }
    for (int i = len-1; i >= 0; i--) {
        res+=temp[i];
    }
    return res;
}

string Util::calStrUId(const unsigned char *u, const int len)
{
    return convert(u,len);
}

void Util::setRecords(QTextBrowser *obj, list<Record> records, string strRecord)
{
    list<Record>::iterator ite=records.begin();
    Record record;
    while(ite!=records.end()){
        record=*ite++;
        strRecord.append(record.toString());
        strRecord.append("\r\n");
    }

    obj->setText(Util::toQString(strRecord));
}
