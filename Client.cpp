#include "Client.h"
#include <iomanip>
Client::Client() {
	judge = 1;
}

Client::Client(string n, string p, int d) {
	name = n;
	phone = p;
	desk = d;
	coust = 0;
	for (int i = 0; i < 100; i++)
		num[i] = 0;
	cout << "顾客注册成功" << endl;
	judge = 1;
}

Client::Client(string n, string p, string a) {
	name = n;
	phone = p;
	address = a;
	coust = 0;
	for (int i = 0; i < 100; i++)
		num[i] = 0;
	cout << "顾客注册成功" << endl;
	judge = 1;
}

double Client::getCoust() {
	return coust;
}

string Client::getName() {
	return name;
}

string Client::getPhone() {
	return phone;
}

string Client::getAddress() {
	return address;
}

int Client::getType() {
	return type;
}

int Client::getDesk() {
	return desk;
}

int Client::getDeskCoust() {
	if (desk > 50)
		return 50;
	else
		return 0;
}

void Client::setAddress(string a) {
	address = a;
}


void Client::setDesk(int a) {
	desk = a;
	if (a >= 1 && a <= 50)
		cout << "\n您选择了" << a << "号餐桌" << endl;
	else {
		cout << "\n您选择了" << a << "号包厢" << endl;
		coust += 50;
	}
}


void Client::setType(int n) {
	type = n;
}

void Client::addCoust(double n) {
	coust += n;
}

void Client::setCoust(double a) {
	coust = 0;
}

void Client::showCientMessage() {

	if (judge == 1) {
		string a;
		if (type == 1)
		{
			a = "在店就餐";
			cout << "姓名:" << name << "\t\t" << a << endl;
			cout << "电话号码:" << phone << endl;
			cout << "餐桌号为:" << desk << endl << endl;
			cout << setw(10) << setiosflags(ios::left) << "食物序列" << setw(10) << "菜名" << "\t数量\t价格\t折扣" << endl;
			for (int i = 0; i < Client_Menu.getNum(); i++)
				cout << setw(10) << setiosflags(ios::left) << setw(10) << i + 1 << Client_Menu.food[i].getName() << "\t" << num[i] << "\t" << num[i] * Client_Menu.food[i].getRightPrice() << "\t" << Client_Menu.food[i].getDiscount() << endl;
			cout << "总价：\t" << coust + getDeskCoust() << "元\t\t含包厢费" << getDeskCoust() << "元" << endl << endl;
			cout << "--------------------------------------" << endl;
		}
		else {
			a = "外卖";
			cout << "姓名:" << name << "\t\t" << a << endl;
			cout << "电话号码:" << phone << endl;
			cout << "外卖送达地址:" << address << endl << endl;
			cout << setw(10) << setiosflags(ios::left) << "食物序列" << setw(10) << "菜名" << "\t数量\t价格\t折扣" << endl;
			for (int i = 0; i < Client_Menu.getNum(); i++)
				cout << setw(10) << setiosflags(ios::left) << setw(10) << i + 1 << Client_Menu.food[i].getName() << "\t" << num[i] << "\t" << num[i] * Client_Menu.food[i].getRightPrice() << "\t" << Client_Menu.food[i].getDiscount() << endl;
			int t = 5;
			//cout << "\n\n\n" << coust << "\n\n\n";
			cout << "总价：\t\t" << coust + 5 << "元\t" << "含外卖费" << 5 << "元" << endl << endl;
			cout << "预计到达时间：\t" << arriveTime << "分钟后\n";
			cout << "--------------------------------------" << endl;
		}
	}
	else {
		name = "";
		phone = "";
		address = "";
		desk = 0;
		coust = 0;
		arriveTime = 0;

		cout << "该订单已删除\n\n";
	}
	
}

void Client::setId(int i) {
	id = i;
}

void Client::changeNum() {
	int n,numss;
	cout << "请输入食物序列:";
	cin >> n;
	cout << "您选择了食物为:\t" << Client_Menu.food[n - 1].getName() << endl;
	cout << "请输入要改变该食物的数量:";
	cin >> numss;
	coust += (numss - num[n - 1]) * Client_Menu.getPriceByName(Client_Menu.getNameById(n - 1));
	num[n - 1] = numss;
}

void Client::delFood() {
	int n;
	cout << "请输入您的序列号:";
	cin >> n;
	cout << "您选择了食物:" << Client_Menu.food[n - 1].getName() << endl;
	coust -= num[n - 1] * Client_Menu.food[n - 1].getPrice();
	for (int i = n - 1; i < Client_Menu.getNum(); i++) {
		Client_Menu.food[i] = Client_Menu.food[i + 1];
		num[i] = num[i + 1];
	}
	Client_Menu.setNum(Client_Menu.getNum() - 1);
}

void Client::setArriveTime(int t) {
	
	arriveTime = t;
}