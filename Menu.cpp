#include "Menu.h"

Menu::Menu() {
	num = 0;
}

void Menu::addFood(Food f) {
	food[num++] = f;
	cout << "成功添加食物，当前共有：" << num << "种食物\n\n";
}

void Menu::setNum(int x) {
	num = x;
}

void Menu::showFood() {
	cout << "食物中共有" << num << "种" << endl;
	cout << "食物编号  名称\t\t单价\t\t折扣" << endl;
	for (int i = 0; i < num; i++)
		cout << setw(10) << setiosflags(ios::left) << i << setw(10) << food[i].getName() << "\t" << food[i].getPrice() << "\t\t" << food[i].getDiscount() << endl;
}

void Menu::changePrice() {
	string s;
	int c,i;
	double p;
	cout << "请输入食物的编号:";
	cin >> c;
	s = food[c].getName();
	cout << "您选择了食物：" << s << endl;
	cout << endl;
	cout << "请输入价格：";
	cin >> p;
	cout << endl;
	for (i = 0; i < num; i++) {
		if (s == food[i].getName()) {
			food[i].setPrice(p);
			cout << "修改成功\n";
			cout << endl;
			break;
		}	
	}
	if (i >= num)
		cout << "没有这种食物，修改失败\n";
}

void Menu::changeDiscount() {
	string s;
	int c,i;
	double p;
	cout << "请输入食物的编号:";
	cin >> c;
	s = food[c].getName();
	cout << "您选择了食物：" << s << endl;
	cout << endl;
	cout << "请输入折扣（0<折扣  折扣<=1）：";
	cin >> p;
	cout << endl;
	for (i = 0; i < num; i++) {
		if (s == food[i].getName()) {
			food[i].setDiscount(p);
			cout << "修改成功\n";
			cout << endl;
			break;
		}
	}
	if (i >= num)
		cout << "没有这种食物，修改失败\n";
}

void Menu::delFood() {
	string s;
	int i;
	cout << "请输入菜名：";
	cin >> s;
	for (i = 0; i < num; i++) {
		if (food[i].getName() == s) {
			cout << "成功删除" << s << endl << endl;
			num--;
			for (int j = i; j < num; j++) {
				food[j] = food[j + 1];
				return;
			}
		}
	}
	if (i >= num)
		cout << "没有这种食物\n\n";
}

void Menu::addFood(string s, double p,double d) {
	food[num++] = Food(s, p, d);
}

double Menu::getPriceByName(string n) {
	for (int i = 0; i < num; i++) {
		if (n == food[i].getName())
			return food[i].getRightPrice();
		return 0;
	}
}

int Menu::getIdByName(string n) {
	for (int i = 0; i < num; i++) {
		if (n == food[i].getName())
			return i;
		return 0;
	}
}

string Menu::getNameById(int i) {
	return food[i].getName();
}

int Menu::getNum() {
	return num;
}