#include "Admin.h"

Admin::Admin() {

}

void Admin::setId(string I) {
	ID = I;
}

void Admin::setNum(int n) {
	num = n;
}

void Admin::setPassword(string P) {
	password = P;
}

string Admin::getID() {
	return ID;
}

string Admin::getPassword() {
	return password;
}

int Admin::getNum() {
	return num;
}