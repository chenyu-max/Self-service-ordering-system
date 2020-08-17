#pragma once
#ifndef ADMIN
#define ADMIN
#include <bits/stdc++.h>
using namespace std;
class Admin
{
private:
	int num;
	string ID, password;
public:
	Admin();
	void setId(string I);
	void setPassword(string p);
	void setNum(int i);
	string getID();
	string getPassword();
	int getNum();
};
#endif // !ADMIN