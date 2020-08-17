#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include "Client.h"
#include "Clientmanager.h"
#include "CoustManager.h"
#include "Menu.h"
#include "Food.h"
#include"SystemMap.h"
#include "Admin.h"
#include "AdminManager.h"
using namespace std;

CoustManager coust;
SystemMap smap;
Clientmanager cm;
Menu menu;
fstream ioFile;
AdminManager ad;

int AdminChoice,adNum,ClientChoice,ClientService, EatChoice, curClient, QueryChoice, FoodChoice, ClientMapChoice, MenuChoice, orderChoice,StstemMapChoice;

int main()
{
	
	ioFile.open("./data/food.txt", ios::in);
	while (!ioFile.eof())
	{
		string s;
		double p;
		double d;
		ioFile >> s >> p >> d;
		menu.addFood(s, p,d);
	}
	ioFile.close();
	//��food�ļ��ж�ȡʳ�� 

	ioFile.open("./data/admin.txt", ios::in);
	while (!ioFile.eof())
	{
		string id, pas;
		ioFile >> id >> pas;
		ad.addAdmin(id, pas);
	}
	ioFile.close();

	
	while (true) {
		StstemMapChoice = smap.showChoiceMap();
		if (StstemMapChoice == 1) {//�˿ͷ���
			ClientMapChoice = smap.showRegMap();
			if (ClientMapChoice == 1) {  //�û�ע��
				
				ClientMapChoice = smap.showSystemMap();
				if (ClientMapChoice == 1) {  // ���ھͲ�
					string name, phone;
					cout << "����д���Ļ�����Ϣ:\n";
					cout << "���Ķ�����:" << cm.getClientNum() + 1 << endl;
					curClient = cm.getClientNum();
					cout << "��������������:"; cin >> name;
					cout << endl;
					cout << "���������ĵ绰����:"; cin >> phone;
					cout << endl;
					cout << "������1~50Ϊ��ͨ��,������51~80Ϊ����,�����Ϊ50Ԫ\n";
					cout << "���������Ĳ����ţ�";
					int q;
					cin >> q;
					cout << endl;
					Client a(name, phone,q);
					a.setId(cm.getClientNum());
					cm.addClient(a);
					
					a.setDesk(q);
					cm.client[curClient].setType(1);
					smap.showInsideSystemMap();
					while (true) {
						menu.showFood();
						int choice;
						choice = smap.showClientChoiceMap();

						if (choice == 1) { //���ھͲ͵��
							string n;
							int code, nums;
							double prices;
							cout << "������ʳ����:"; cin >> code;
							n = menu.food[code].getName();
							cout << endl << "��ѡ����ʳ��:" << n << endl;
							prices = menu.food[code].getRightPrice();
							cout << "����������:"; cin >> nums;
							cout << endl;
							menu.food[code].addSaleNum(nums);
							cm.client[curClient].Client_Menu.addFood(menu.food[code]);
							cm.client[curClient].addCoust(nums * prices);
							cm.client[curClient].num[cm.client[curClient].Client_Menu.getNum() - 1] = nums;
							cout << "��ǰ���ܷ�����" << cm.client[curClient].getCoust() << "Ԫ" << endl << endl;
						}

						else if (choice == 2) {//���ھͲ��޸Ķ���
							cout << "����ǰ�Ķ�����:" << endl;
							while (true)
							{
								cm.client[curClient].showCientMessage();
								orderChoice = smap.showCilentOrderMessage();
								if (orderChoice == 1)
									cm.client[curClient].changeNum();
								else if (orderChoice == 2)
									cm.client[curClient].delFood();
								else
									break;
							}
						}
						else if (choice == 3)  //���ھͲ��ύ����
							break;
					}
					coust.addInsideCoust(cm.client[curClient].getCoust() + cm.client[curClient].getDeskCoust());
					cout << "���Ķ�����:" << endl;
					cout << "�����ţ�" << cm.getClientNum()  << endl;
					cm.client[curClient].showCientMessage();//�����ǰ����
				}
				else if (ClientMapChoice == 2) {//����
					string name, phone,address;
					cout << "����д���Ļ�����Ϣ:\n";
					cout << "���Ķ�����:" << cm.getClientNum() + 1 << endl;
					curClient = cm.getClientNum();
					cout << "��������������:"; cin >> name;
					cout << endl;
					cout << "���������ĵ绰����:"; cin >> phone;
					cout << endl;
					cout << "���������ĵ�ַ:";
					cin >> address;
					cout << endl;
					Client a(name, phone, address);
					a.setId(cm.getClientNum());
					cm.addClient(a);
					srand((unsigned)time(NULL));
					int t = rand() % 59 + 1;
					cm.client[curClient].setArriveTime(t);
					cm.client[curClient].setType(2);
					smap.showOutsideSystemMap();
					while (true)
					{
						menu.showFood();
						int choice;
						choice = smap.showClientChoiceMap();
						if (choice == 1) { //�������
							string n;
							int code, nums;
							double prices;
							cout << "������ʳ����:"; cin >> code;
							n = menu.food[code].getName();
							cout << endl << "��ѡ����ʳ��:" << n << endl;
							prices = menu.food[code].getRightPrice();
							cout << "����������:"; cin >> nums;
							cout << endl;
							menu.food[code].addSaleNum(nums);
							cm.client[curClient].Client_Menu.addFood(menu.food[code]);
							cm.client[curClient].addCoust(nums * prices);
							cm.client[curClient].num[cm.client[curClient].Client_Menu.getNum() - 1] = nums;
							cout << "��ǰ���ܷ�����" << cm.client[curClient].getCoust() << "Ԫ" << endl << endl;
						}

						else if (choice == 2) {//�����޸Ķ���
							cout << "����ǰ�Ķ�����:" << endl;
							while (true)
							{
								cm.client[curClient].showCientMessage();
								orderChoice = smap.showCilentOrderMessage();
								if (orderChoice == 1)
									cm.client[curClient].changeNum();
								else if (orderChoice == 2)
									cm.client[curClient].delFood();
								else
									break;
							}
						}
						else if (choice == 3) {
							coust.addOutsideCoust(cm.client[curClient].getCoust() + 5);
							cout << "���Ķ�����:" << endl;
							cout << "�����ţ�" << cm.getClientNum() << endl;
							cm.client[curClient].showCientMessage();//���������ǰ����
							break;
						}
						//�ύ����
					}
				}
			}
			else if (ClientMapChoice == 2) {
				while (true)
				{
					QueryChoice = smap.showQueryMap();
					if (QueryChoice == 1) {//��ѯ�ͻ�����
						string name;
						cout << "��������������:" << endl;
						cin >> name;
						cm.showQuery(name);
					}
					else if (QueryChoice == 2)
						break;//�˳���ѯ
				}
			}
		}
		//�˿ͷ���
		else if (StstemMapChoice == 2) {
			while (true)
			{
				cout << "�������Ƿ��й���Ա�˺ţ�\n���������� 1 ���е�¼\n�����˺ţ������� 2 ����ע��\n";
				int oo;
				cin >> oo;
				if (oo == 1) {

					string id, pas;
					cout << "���������Ĺ���Ա�˺�:"; cin >> id;
					cout << endl;
					cout << "����������:"; cin >> pas;
					cout << endl;
					int op;
					op = ad.checkPassword(id, pas);
					if (op != 1)
						break;
					//��¼�ɹ�
					while (true)
					{
						AdminChoice = smap.adminSystemMap();//ѡ�����Ա����
						if (AdminChoice == 1) {//ʳ�����
							while (true) {
								menu.showFood();
								FoodChoice = smap.showChangeMenuMap();

								if (FoodChoice == 1) {
									string n;
									double p, d;
									cout << "������ʳ�������:"; cin >> n;
									cout << endl;
									cout << "������ʳ��ļ۸�:"; cin >> p;
									cout << endl;
									cout << "�������ۿۣ�0<�ۿ�  �ۿ�<=1��:"; cin >> d;
									cout << endl;
									menu.addFood(Food(n, p, d));
								}

								else if (FoodChoice == 2)
									menu.changePrice();

								else if (FoodChoice == 3)
									menu.changeDiscount();

								else if (FoodChoice == 4)
									menu.delFood();

								else
									break;
							}
						}
						//ʳ�����

						else if (AdminChoice == 2) {
							cout << "���칲��" << cm.getClientNum() << "���˿����ѣ������ܶ�Ϊ:" << coust.getInsideCoust() + coust.getOutsideCoust() << "Ԫ" << endl;
							cout << "����\n�ڵ�Ͳ�����Ϊ:" << coust.getInsideCoust() << "Ԫ\n";
							cout << "��������Ϊ:" << coust.getOutsideCoust() << "Ԫ\n";
							cout << "--------------------------------------" << endl;
							cm.showAll();
						}
						//���շ���

						else if (AdminChoice == 3) {
							int order = smap.showOrderChangeMap();
							while (true)
							{
								if (order == 1) {
									cout << "��ѡ����Ҫ���Ҷ����ķ�ʽ:\n(�����Ų�ѯ ����1\t�绰�����ѯ ����2)\n";
									int o;
									cin >> o;
									if (o == 1) {
										int op;
										cout << "�����붩����:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "�޴˶�����\n";
											break;
										}
										cm.client[op].showCientMessage();
										break;
									}
									//�����Ų�ѯ

									else if (o == 2) {
										string op;
										int i;
										cout << "������绰����:"; cin >> op;
										for (i = 0; i < cm.getClientNum(); i++) {
											if (cm.client[i].getPhone() == op) {
												cm.client[i].showCientMessage();
												break;
											}
												
										}
										if (i >= cm.getClientNum()) {
											cout << "�޴˵绰�����Ӧ�Ķ���\n";
											break;
									}
									break;

									}
									//�绰�����ѯ
								}
								//���Ҷ���

								else if (order == 2) {
									cout << "��ѡ����Ҫ�޸Ķ����ķ�ʽ:\n(�����Ų�ѯ ����1\t�绰�����ѯ ����2)\n";
									int o;
									cin >> o;

									if (o == 1) {
										int op;
										cout << "�����붩����:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "�޴˶�����\n";
											break;
										}
										cm.client[op].showCientMessage();
										orderChoice = smap.showCilentOrderMessage();
										if (orderChoice == 1)
											cm.client[op].changeNum();
										else if (orderChoice == 2)
											cm.client[op].delFood();
										else
											break;
									}

									else if (o == 2) {
										string op;
										int i;
										cout << "������绰����:"; cin >> op;
										for (i = 0; i < cm.getClientNum(); i++) {
											if (cm.client[i].getPhone() == op) {
												cm.client[i].showCientMessage();
												orderChoice = smap.showCilentOrderMessage();
												if (orderChoice == 1) {
													cm.client[i].changeNum();
													break;
												}
												else if (orderChoice == 2) {
													cm.client[i].delFood();
													break;
												}
													
												else
													break;
											}	
										}
										if(i >= cm.getClientNum())
											cout << "�޴˺����Ӧ�Ķ���\n";
										break;
									}
								}
								//�޸Ķ���

								else if (order == 3) {
									cout << "��ѡ����Ҫɾ�������ķ�ʽ:(�����Ų�ѯ ����1\t�绰�����ѯ ����2)\n";
									int o;
									cin >> o;

									if (o == 1) {
										int op;
										cout << "�����붩����:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "�޴˶�����\n";
											break;
										}
										cm.client[op].judge = 2;
										
										if (cm.client[op].getType() == 1)
											coust.addInsideCoust(-cm.client[op].getCoust());
										else
											coust.addOutsideCoust(-cm.client[op].getCoust());
										
										cout << "�ö�����ɾ��\n\n";
										cm.client[op].setCoust(0);
										break;
									}

									else if (o == 2) {
										string op;
										int i;
										cout << "������绰����:"; cin >> op;
										for (i = 0; i < cm.getClientNum(); i++) {
											if (cm.client[i].getPhone() == op) {
												cm.client[i].judge = 2;
												if (cm.client[i].getType() == 1) 
													coust.addInsideCoust(-cm.client[i].getCoust());
												else
													coust.addOutsideCoust(-cm.client[i].getCoust());
												cout << "�ö�����ɾ��\n\n";
												cm.client[i].setCoust(0);
												break;
											}
										}
										if (i >= cm.getClientNum()) 
											cout << "�޴˺����Ӧ�Ķ���\n";
										break;
									}
								}
								//ɾ������

								else
									break;
							}
							//��������
						}

						else if (AdminChoice == 4) {
							string date, s;
							char tem(0);
							cout << "��������Ҫ��ѯ������ (��-��-��)(��2020-5-20) ��";
							cin >> date;
							string a = "./data/" + date + ".txt";
							ioFile.open(a, ios::_Nocreate);//�ж����޸����ļ�����û�У��򲻴������ļ�
							if (!ioFile)
								cout << "\nû����һ��Ķ�����Ϣ\n\n";
							ioFile.close();

							ioFile.open(a, ios::in);
							
							while (!ioFile.eof()) {
								ioFile.get(tem);
								s += tem;
							}
							cout << s << endl;

						}
						//��ʷ������ѯ

						else
							break;
						//�˳�
					}
					break;
				}
				//��¼����
				else if (oo == 2) {
					string id, pas1, pas2;
					cout << "ע�����\n�����������˺�:";
					cin >> id; cout << endl;
					cout << "��������������:";
					cin >> pas1;
					cout << "\n���ٴ�ȷ������:";
					cin >> pas2;
					cout << endl;
					if (pas1 == pas2) {
						cout << "ע��ɹ���\n\n";
						ad.addAdmin(id, pas1);
						break;
					}
					else
					{
						cout << "�������벻һ��������������\n\n";
						break;
					}
				}
				//ע�����
			}
			
		}
		//����Աϵͳ
		else if (StstemMapChoice == 3) {//�˳�ϵͳ������
			cout << "��������յ����� (��-��-��)(��2020-5-20) ��";
			string a;
			cin >> a;
			string b = "./data/" + a + "order.txt";
			string c= "./data/" + a + ".txt";
			
			ioFile.open(b, ios::out, ios::_Noreplace);
			ioFile << a << endl << cm.getClientNum() << "���˿����ѣ������ܶ�Ϊ:" << coust.getInsideCoust() + coust.getOutsideCoust() << "Ԫ" << endl;
			ioFile << "�ڵ�Ͳ�����Ϊ:" << coust.getInsideCoust() << "Ԫ\n";
			ioFile << "��������Ϊ:" << coust.getOutsideCoust() << "Ԫ\n";
			ioFile << "--------------------------------------" << endl;
			for (int i = 0; i < cm.getClientNum(); i++) {
				ioFile << "��" << i + 1 << "����\n" << "����:\t" << cm.client[i].getName() << endl;
				ioFile << "�绰����:\t" << cm.client[i].getPhone() << endl;
				if (cm.client[i].getType() == 1){
					ioFile << "�Ͳͷ�ʽΪ:\t�ڵ�Ͳ�\n" << "������Ϊ:\t" << cm.client[i].getDesk() << endl;
					ioFile << "�ܹ�����Ϊ:\t" << cm.client[i].getCoust() + cm.client[i].getDeskCoust() << "Ԫ" << endl;
				}
					
				else{
					ioFile << "�Ͳͷ�ʽΪ:\t�����Ͳ�\n��ַΪ:\t" << cm.client[i].getAddress() << endl;
					ioFile << "�ܹ�����Ϊ:\t" << cm.client[i].getCoust() + 5 << "Ԫ" << endl;
				}

				ioFile << "--------------------------------------" << endl;
			}
			ioFile.close();


			ioFile.open("./data/food.txt", ios::out);
			for (int i = 0; i < menu.getNum(); i++) {
				ioFile << setw(10) << setiosflags(ios::left) << menu.food[i].getName() << "\t" << menu.food[i].getPrice() << "\t" << menu.food[i].getDiscount();
				if (i != menu.getNum() - 1)
					ioFile<< endl;
			}
			ioFile.close();


			ioFile.open("./data/admin.txt", ios::out);
			for (int i = 0; i < ad.getAdminNum(); i++) {
				ioFile << setw(10) << setiosflags(ios::left) << ad.admin[i].getID() << "\t" << setw(10) << setiosflags(ios::left) << ad.admin[i].getPassword();
				if (i != ad.getAdminNum())
					ioFile << endl;
			}
			ioFile.close();


			ioFile.open(c, ios::out, ios::_Noreplace);
			ioFile << a << "�������" << endl;
			int q = 0;
			for (int i = 0; i < cm.getClientNum(); i++) 
				if (cm.client[i].judge == 1) 
					q++;
				
			ioFile << "һ�����۳�������\t" << q << endl;
			ioFile << "���۶�Ϊ��\t" << coust.getInsideCoust() + coust.getOutsideCoust() << "Ԫ\n\n";
			ioFile << "�ڵ����۶\t" << coust.getInsideCoust() << "Ԫ\n";
			ioFile << "�������۶\t" << coust.getOutsideCoust() << "Ԫ\n\n";
			ioFile << "��Ʒ�������������\n\n";
			for (int i = 0; i < menu.getNum(); i++)
				ioFile << menu.food[i].getName() << "\t" << menu.food[i].getSaleNum() << "��\n";

			ioFile.close();

			cout << "�ɹ��˳�ϵͳ" << endl << endl << endl;
			system("pause");
			return 0;
		}
		//�˳�ϵͳ
	}
	return 0;
}