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
				cout << "密码正确\n\n";
				return 1;
			}
			else {
				cout << "密码错误\n\n";
				return 2;
			}
		}
	}
	if (i >= adminNum) {
		cout << "没有此账号的管理员，请先注册\n\n";
		return 3;
	}
}

int AdminManager::getAdminNum() {
	return adminNum;
}