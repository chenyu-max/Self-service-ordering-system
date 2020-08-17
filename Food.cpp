#include "Food.h"

Food::Food() {
	saleNum = 0;
}

Food::Food(string name, double price,double d) {
	this->name = name;
	this->price = price;
	discount = d;
	saleNum = 0;
}

void Food::setName(string name) {
	this->name = name;
}

void Food::setPrice(double price){
	this->price = price;
}

void Food::setDiscount(double discount) {
	this->discount = discount;
}

string Food::getName() {
	return name;
}

double Food::getDiscount() {
	return discount;
}

double Food::getPrice() {
	return price;
}

double Food::getRightPrice() {
	return price * discount;
}

void Food::showInformation() {
	cout << name << "\t" << price << "\t" << discount << endl;

}

void Food::addSaleNum(int n) {
	saleNum += n;
}

int Food::getSaleNum() {
	return saleNum;
}