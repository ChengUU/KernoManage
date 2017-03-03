#include "UID.h"
/*finish 2016 11 10 by abcABC123*/


UID::UID(const string strUid)
{
    this->strUid=strUid;
}

UID::UID(const unsigned char * u, const int & len)//����һ�����ţ��Ϳ��ų���
{
    for (int i = 0; i < len; i++)
	{
		Uid[i] = u[i];
	}
}

UID::UID(UID & u)
{
	Len = u.getLen();
	for (int i = 0; i < Len; i++)
	{
		Uid[i] = u.getUid()[i];												//����������
	}
}

UID::~UID()
{
}

void UID::setUid(const unsigned char * u, const int len)
{

	string uid = convert(u,len);
	int length = uid.length();
	strUid = uid;
	int i;
	for (i = 0; i < length; i++)
	{
		Uid[i] = uid[i];
	}
	Uid[i] = '\0';
}

const unsigned char *UID::getUid()
{
	return Uid;
}
string  UID::getStrUid() {
    return convert(this->Uid,this->getLen());
}
const int UID::getLen()
{
	return Len;
}
const string UID::convert(const unsigned char*  bits,int len) {
	string res = "";
	for (int i = 0; i < len; i++)
	{
		int bit = (int)bits[i] % 128;
		/*
		0 - 9;
		10 - 99;
		100 - 127;*/
		//Ŀ���ַ��������ж�
		res+=stringValue(bit);
	}
	return res;
}
const string UID::stringValue(int number) {
	string res="";
	string temp = "";
	//������ת�����ַ���
	do{
		temp += number % 10 + '0';
		number /= 10;
	} while (0 != number);

	//cout << "temp:" << temp.c_str();
	//�ַ�����ת,ȡ������ԭʼ˳��
	int len=temp.length();
	//���볤��
	switch (len) {
	case 1:res+="00"; break;
	case 2:res+="0"; break;
	}
	for (int i = len-1; i >= 0; i--) {
		res+=temp[i];
	}
    return res;
}

void UID::setStrUid(const string uid)
{
    this->strUid=uid;
}



bool operator==(UID & u1, UID & u2)
{
	for (int i = 0; i < u1.Len; i++)
	{
		if (u1.Uid[i] != u2.Uid[i])
		{
			return false;
		}
	}
	return true;
}

bool operator==(UID u, unsigned char * data)
{
	for (int i = 0; i < u.Len; i++)
	{
		if (u.Uid[i] != data[i])
			return false;
	}
	return true;
}
