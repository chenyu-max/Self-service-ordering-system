#ifndef FOOD
#define FOOD
#include <bits/stdc++.h>
using namespace std;
class Food
{
private:
	string name; // 食物名称
	double price,discount; // 食物价格  食物折扣
	int saleNum;//卖出去食物的数量
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