#include "SystemMap.h"

SystemMap::SystemMap() {
	frame = "#";
}

int SystemMap::showSystemMap() {
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t\t欢迎光临本店";
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "#\n";
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t  请问您需要什么服务\t\t";
	for (int i = 0; i < 11; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t  1:在店就餐";
	for (int i = 0; i < 31; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t  2:外卖就餐";
	for (int i = 0; i < 31; i++)
		cout << " ";
	cout << "#\n";
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	cout << "\t\t  请问您选择的是:";
	int choice;
	cin >> choice;
	return choice;

}

void SystemMap::showInsideSystemMap() {
	cout << "欢迎您在本店就餐，以下是菜单\n\n";
}

void SystemMap::showOutsideSystemMap() {
	cout << "欢迎您点本店的外卖，以下是菜单\n\n";
}

int SystemMap::showChoiceMap() {

	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << "\n#\t\t      欢迎来到榆榆餐厅";
	for (int i = 0; i < 21; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t\t店长:   陈榆";
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "#\n";
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:顾客服务          |" << endl;
	cout << "\t\t|  2:管理员系统        |" << endl;
	cout << "\t\t|  3:退出系统          |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t您的选择是:";
	int choice;
	cin >> choice;
	return choice;
}

int SystemMap::adminSystemMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:食物管理          |" << endl;
	cout << "\t\t|  2:今日反馈          |" << endl;
	cout << "\t\t|  3:订单管理          |" << endl;
	cout << "\t\t|  4:历史销售情况      |" << endl;
	cout << "\t\t|  5:退出              |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cin >> choice;
	return choice;
}

int SystemMap::showRegMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:新顾客点餐        |" << endl;
	cout << "\t\t|  2:查询订单          |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showClientChoiceMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:点菜              |" << endl;
	cout << "\t\t|  2:修改订单          |" << endl;
	cout << "\t\t|  3:提交订单          |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showQueryMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:查询订单          |" << endl;
	cout << "\t\t|  2:退出              |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showChangeMenuMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:添加食物          |" << endl;
	cout << "\t\t|  2:修改食物价格      |" << endl;
	cout << "\t\t|  3:修改食物折扣      |" << endl;
	cout << "\t\t|  4:删除食物          |" << endl;
	cout << "\t\t|  5:退出食物管理系统  |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t您的选择是:";
	int choice;
	cin >> choice;
	return choice;
}

int SystemMap::showMenuChoice() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:原菜单            |" << endl;
	cout << "\t\t|  2:新菜单            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showCilentOrderMessage() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:修改数量            |" << endl;
	cout << "\t\t|  2:删除食物            |" << endl;
	cout << "\t\t|  3:退出修改            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showOrderChangeMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:查找订单            |" << endl;
	cout << "\t\t|  2:修改订单            |" << endl;
	cout << "\t\t|  3:删除订单            |" << endl;
	cout << "\t\t|  4:退出修改            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}

int SystemMap::showPastSales() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:查找订单            |" << endl;
	cout << "\t\t|  2:修改订单            |" << endl;
	cout << "\t\t|  3:删除订单            |" << endl;
	cout << "\t\t|  4:退出修改            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t您的选择是:";
	cin >> choice;
	return choice;
}