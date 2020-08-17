#include "Clientmanager.h"

Clientmanager::Clientmanager() {
	clientNum = 0;
}

void Clientmanager::addClient(Client t) {
	client[clientNum++] = t;
}

int Clientmanager::getClientNum() {
	return clientNum;
}

void Clientmanager::showQuery(string a) {
	int count = 0;
	int t;
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < clientNum; i++) {

		if (client[i].getType() == 1) {
			cout << "第" << ++count << "单：" << client[i].getName() << "\t总价是：" << client[i].getCoust() + client [i].getDeskCoust() << "元\t在店就餐" << endl << endl;
			if (a == client[i].getName())
				t = count;
		}
	}

	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType() == 2) {
			cout << "第" << ++count << "单：" << client[i].getName() << "\t总价是：" << client[i].getCoust() + 5 << "元\t外卖" << endl << endl;
			if (a == client[i].getName())
				t = count;
		}
	}
	cout << "您当前排在第" << t << "单" << endl;
	cout << "-----------------------------------" << endl;

}

void Clientmanager::showAll() {
	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType()== 1) {
			cout << "订单号：" << i + 1 << endl;
			client[i].showCientMessage();
			cout << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType() == 2) {
			cout << "订单号：" << i + 1 << endl;
			client[i].showCientMessage();
			cout << endl;
			cout << "--------------------------------------" << endl;
		}
	}
}