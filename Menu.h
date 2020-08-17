#pragma once
#ifndef MENU
#define MENU
#include "Food.h"
class Menu
{
private:
	int num; // ������
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
	int getIdByName(string s);//����name ���� id
	int getNum();
};
#endif // !MENU