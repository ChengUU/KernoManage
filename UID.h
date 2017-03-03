#pragma once
#include<iostream>
# include<string>
using namespace std;

const int UID_MAX_LEN = 54;
typedef   const unsigned char*  type_uid;

class UID
{
	unsigned char Uid[UID_MAX_LEN];
	int Len= 54;
	string strUid;
public:
	UID()
	{
		Uid[0] = 0;
    }
    UID(const string strUid);
    //默认为0
    UID(const unsigned char *u, const int &len=UID_MAX_LEN);
	UID(UID &u);
	~UID();

	void setUid(const unsigned char *u, const int len);//设置uid

	const unsigned char *getUid();//返回uid
	const int getLen();//获取uid的长度
	const string convert(const unsigned char* bits,int len);//将uid转换成字符串
	const string stringValue(int number);//辅助covert进行uid的转换

    void setStrUid(const string uid);

	string getStrUid();//获取字符串类型的uid用于存入数据库

	friend bool operator ==(UID &u1,UID &u2);
	friend bool operator ==(UID u, unsigned char *data);
};


