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
	void showOutsideSystemMap(); // �����Ͳ�ҳ��
	void showInsideSystemMap();  //  ���ھͲ�ҳ��
	int showSystemMap();  //�˿�ѡ��ϵͳҳ��
	int showChoiceMap();  //ϵͳ�Ĺ���ѡ�����
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