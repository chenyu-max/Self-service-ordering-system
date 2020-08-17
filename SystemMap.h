#pragma once
#ifndef SYSTEMMAP
#define SYSTEMMAP

#include<bits/stdc++.h>
using namespace std;

class SystemMap
{
private:
	string frame;
public:
	SystemMap();
	void showOutsideSystemMap(); // 外卖就餐页面
	void showInsideSystemMap();  //  店内就餐页面
	int showSystemMap();  //顾客选择系统页面
	int showChoiceMap();  //系统的功能选择界面
	int showRegMap();
	int showClientChoiceMap();
	int showQueryMap();
	int showMenuChoice();
	int showChangeMenuMap();
	int showCilentOrderMessage();
	int adminSystemMap();
	int showOrderChangeMap();
	int showPastSales();
};

#endif // !SYSTEMMAP