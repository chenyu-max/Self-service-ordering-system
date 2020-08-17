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
			cout << "��" << ++count << "����" << client[i].getName() << "\t�ܼ��ǣ�" << client[i].getCoust() + client [i].getDeskCoust() << "Ԫ\t�ڵ�Ͳ�" << endl << endl;
			if (a == client[i].getName())
				t = count;
		}
	}

	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType() == 2) {
			cout << "��" << ++count << "����" << client[i].getName() << "\t�ܼ��ǣ�" << client[i].getCoust() + 5 << "Ԫ\t����" << endl << endl;
			if (a == client[i].getName())
				t = count;
		}
	}
	cout << "����ǰ���ڵ�" << t << "��" << endl;
	cout << "-----------------------------------" << endl;

}

void Clientmanager::showAll() {
	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType()== 1) {
			cout << "�����ţ�" << i + 1 << endl;
			client[i].showCientMessage();
			cout << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < clientNum; i++) {
		if (client[i].getType() == 2) {
			cout << "�����ţ�" << i + 1 << endl;
			client[i].showCientMessage();
			cout << endl;
			cout << "--------------------------------------" << endl;
		}
	}
}