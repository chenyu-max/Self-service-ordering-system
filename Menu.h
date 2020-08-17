#pragma once
#ifndef MENU
#define MENU
#include "Food.h"
class Menu
{
private:
	int num; // 菜总数
public:
	Food food[100];
	Menu();
	void setNum(int n);
	void addFood(string name,double price,double d);
	void addFood(Food f);
	void delFood();
	void changePrice();
	void changeDiscount();
	void showFood();
	string getNameById(int i);
	double getPriceByName(string n);
	int getIdByName(string s);//根据name 返回 id
	int getNum();
};
#endif // !MENU