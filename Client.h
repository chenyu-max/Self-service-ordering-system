#pragma once
#ifndef CLIENT
#define CLIENT
#include<bits/stdc++.h>
#include "Menu.h"
using namespace std;
class Client
{
private:
	int id, type, desk, arriveTime;// id ָ���� �˿ͱ��    type   ָ�Ͳ�����
	double coust; // ����
	string name, phone, address; //����  �绰  ��ַ
public:
	Client();
	Client(string n, string p,int d);
	Client(string n, string p,string a);
	int judge = 1;//�ж��Ƿ��������
	int num[100];
	Menu Client_Menu;
	string getName();
	string getPhone();
	string getAddress();
	int getDesk();
	double getCoust();
	int getType();
	int getDeskCoust();
	void setCoust(double);
	void setId(int);
	void setDesk(int);
	void setAddress(string a);
	void setType(int n);
	void addCoust(double x);
	void showCientMessage();
	void changeNum();
	void delFood();
	void setArriveTime(int);

};
#endif // CLIENT