#ifndef FOOD
#define FOOD
#include <bits/stdc++.h>
using namespace std;
class Food
{
private:
	string name; // ʳ������
	double price,discount; // ʳ��۸�  ʳ���ۿ�
	int saleNum;//����ȥʳ�������
public:
	Food();
	Food(string name, double price, double discount = 1.0);
	void setName(string name);
	void setPrice(double price);
	void setDiscount(double discount);
	void addSaleNum(int);

	int getSaleNum();
	double getRightPrice();
	string getName();
	double getPrice();
	double getDiscount();
	void showInformation();
};
#endif // !FOOD