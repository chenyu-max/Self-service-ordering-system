#include "AdminManager.h"

AdminManager::AdminManager() {
	adminNum = 0;
}

void AdminManager::addAdmin(string ID,string p) {
	admin[adminNum].setId(ID);
	admin[adminNum].setPassword(p);
	admin[adminNum].setNum(adminNum + 1);
	adminNum++;
}

int AdminManager::checkPassword(string id,string p) {
	int i;
	for (i = 0; i < adminNum; i++) {
		if (admin[i].getID() == id) {
			if (admin[i].getPassword() == p) {
				cout << "������ȷ\n\n";
				return 1;
			}
			else {
				cout << "�������\n\n";
				return 2;
			}
		}
	}
	if (i >= adminNum) {
		cout << "û�д��˺ŵĹ���Ա������ע��\n\n";
		return 3;
	}
}

int AdminManager::getAdminNum() {
	return adminNum;
}