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
	cout << "�˿�ע��ɹ�" << endl;
	judge = 1;
}

Client::Client(string n, string p, string a) {
	name = n;
	phone = p;
	address = a;
	coust = 0;
	for (int i = 0; i < 100; i++)
		num[i] = 0;
	cout << "�˿�ע��ɹ�" << endl;
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
		cout << "\n��ѡ����" << a << "�Ų���" << endl;
	else {
		cout << "\n��ѡ����" << a << "�Ű���" << endl;
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
			a = "�ڵ�Ͳ�";
			cout << "����:" << name << "\t\t" << a << endl;
			cout << "�绰����:" << phone << endl;
			cout << "������Ϊ:" << desk << endl << endl;
			cout << setw(10) << setiosflags(ios::left) << "ʳ������" << setw(10) << "����" << "\t����\t�۸�\t�ۿ�" << endl;
			for (int i = 0; i < Client_Menu.getNum(); i++)
				cout << setw(10) << setiosflags(ios::left) << setw(10) << i + 1 << Client_Menu.food[i].getName() << "\t" << num[i] << "\t" << num[i] * Client_Menu.food[i].getRightPrice() << "\t" << Client_Menu.food[i].getDiscount() << endl;
			cout << "�ܼۣ�\t" << coust + getDeskCoust() << "Ԫ\t\t�������" << getDeskCoust() << "Ԫ" << endl << endl;
			cout << "--------------------------------------" << endl;
		}
		else {
			a = "����";
			cout << "����:" << name << "\t\t" << a << endl;
			cout << "�绰����:" << phone << endl;
			cout << "�����ʹ��ַ:" << address << endl << endl;
			cout << setw(10) << setiosflags(ios::left) << "ʳ������" << setw(10) << "����" << "\t����\t�۸�\t�ۿ�" << endl;
			for (int i = 0; i < Client_Menu.getNum(); i++)
				cout << setw(10) << setiosflags(ios::left) << setw(10) << i + 1 << Client_Menu.food[i].getName() << "\t" << num[i] << "\t" << num[i] * Client_Menu.food[i].getRightPrice() << "\t" << Client_Menu.food[i].getDiscount() << endl;
			int t = 5;
			//cout << "\n\n\n" << coust << "\n\n\n";
			cout << "�ܼۣ�\t\t" << coust + 5 << "Ԫ\t" << "��������" << 5 << "Ԫ" << endl << endl;
			cout << "Ԥ�Ƶ���ʱ�䣺\t" << arriveTime << "���Ӻ�\n";
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

		cout << "�ö�����ɾ��\n\n";
	}
	
}

void Client::setId(int i) {
	id = i;
}

void Client::changeNum() {
	int n,numss;
	cout << "������ʳ������:";
	cin >> n;
	cout << "��ѡ����ʳ��Ϊ:\t" << Client_Menu.food[n - 1].getName() << endl;
	cout << "������Ҫ�ı��ʳ�������:";
	cin >> numss;
	coust += (numss - num[n - 1]) * Client_Menu.getPriceByName(Client_Menu.getNameById(n - 1));
	num[n - 1] = numss;
}

void Client::delFood() {
	int n;
	cout << "�������������к�:";
	cin >> n;
	cout << "��ѡ����ʳ��:" << Client_Menu.food[n - 1].getName() << endl;
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