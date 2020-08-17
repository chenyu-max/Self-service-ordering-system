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
	//从food文件中读取食物 

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
		if (StstemMapChoice == 1) {//顾客服务
			ClientMapChoice = smap.showRegMap();
			if (ClientMapChoice == 1) {  //用户注册
				
				ClientMapChoice = smap.showSystemMap();
				if (ClientMapChoice == 1) {  // 店内就餐
					string name, phone;
					cout << "请填写您的基本信息:\n";
					cout << "您的订单号:" << cm.getClientNum() + 1 << endl;
					curClient = cm.getClientNum();
					cout << "请输入您的姓名:"; cin >> name;
					cout << endl;
					cout << "请输入您的电话号码:"; cin >> phone;
					cout << endl;
					cout << "餐桌号1~50为普通桌,餐桌号51~80为包厢,包厢费为50元\n";
					cout << "请输入您的餐桌号：";
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

						if (choice == 1) { //店内就餐点菜
							string n;
							int code, nums;
							double prices;
							cout << "请输入食物编号:"; cin >> code;
							n = menu.food[code].getName();
							cout << endl << "您选择了食物:" << n << endl;
							prices = menu.food[code].getRightPrice();
							cout << "请输入数量:"; cin >> nums;
							cout << endl;
							menu.food[code].addSaleNum(nums);
							cm.client[curClient].Client_Menu.addFood(menu.food[code]);
							cm.client[curClient].addCoust(nums * prices);
							cm.client[curClient].num[cm.client[curClient].Client_Menu.getNum() - 1] = nums;
							cout << "当前的总费用是" << cm.client[curClient].getCoust() << "元" << endl << endl;
						}

						else if (choice == 2) {//店内就餐修改订单
							cout << "您当前的订单是:" << endl;
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
						else if (choice == 3)  //店内就餐提交订单
							break;
					}
					coust.addInsideCoust(cm.client[curClient].getCoust() + cm.client[curClient].getDeskCoust());
					cout << "您的订单是:" << endl;
					cout << "订单号：" << cm.getClientNum()  << endl;
					cm.client[curClient].showCientMessage();//输出当前订单
				}
				else if (ClientMapChoice == 2) {//外卖
					string name, phone,address;
					cout << "请填写您的基本信息:\n";
					cout << "您的订单号:" << cm.getClientNum() + 1 << endl;
					curClient = cm.getClientNum();
					cout << "请输入您的姓名:"; cin >> name;
					cout << endl;
					cout << "请输入您的电话号码:"; cin >> phone;
					cout << endl;
					cout << "请输入您的地址:";
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
						if (choice == 1) { //外卖点菜
							string n;
							int code, nums;
							double prices;
							cout << "请输入食物编号:"; cin >> code;
							n = menu.food[code].getName();
							cout << endl << "您选择了食物:" << n << endl;
							prices = menu.food[code].getRightPrice();
							cout << "请输入数量:"; cin >> nums;
							cout << endl;
							menu.food[code].addSaleNum(nums);
							cm.client[curClient].Client_Menu.addFood(menu.food[code]);
							cm.client[curClient].addCoust(nums * prices);
							cm.client[curClient].num[cm.client[curClient].Client_Menu.getNum() - 1] = nums;
							cout << "当前的总费用是" << cm.client[curClient].getCoust() << "元" << endl << endl;
						}

						else if (choice == 2) {//外卖修改订单
							cout << "您当前的订单是:" << endl;
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
							cout << "您的订单是:" << endl;
							cout << "订单号：" << cm.getClientNum() << endl;
							cm.client[curClient].showCientMessage();//外卖输出当前订单
							break;
						}
						//提交订单
					}
				}
			}
			else if (ClientMapChoice == 2) {
				while (true)
				{
					QueryChoice = smap.showQueryMap();
					if (QueryChoice == 1) {//查询客户订单
						string name;
						cout << "请输入您的姓名:" << endl;
						cin >> name;
						cm.showQuery(name);
					}
					else if (QueryChoice == 2)
						break;//退出查询
				}
			}
		}
		//顾客服务
		else if (StstemMapChoice == 2) {
			while (true)
			{
				cout << "请问您是否有管理员账号？\n若有请输入 1 进行登录\n若无账号，请输入 2 进行注册\n";
				int oo;
				cin >> oo;
				if (oo == 1) {

					string id, pas;
					cout << "请输入您的管理员账号:"; cin >> id;
					cout << endl;
					cout << "请输入密码:"; cin >> pas;
					cout << endl;
					int op;
					op = ad.checkPassword(id, pas);
					if (op != 1)
						break;
					//登录成功
					while (true)
					{
						AdminChoice = smap.adminSystemMap();//选择管理员操作
						if (AdminChoice == 1) {//食物管理
							while (true) {
								menu.showFood();
								FoodChoice = smap.showChangeMenuMap();

								if (FoodChoice == 1) {
									string n;
									double p, d;
									cout << "请输入食物的名称:"; cin >> n;
									cout << endl;
									cout << "请输入食物的价格:"; cin >> p;
									cout << endl;
									cout << "请输入折扣（0<折扣  折扣<=1）:"; cin >> d;
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
						//食物管理

						else if (AdminChoice == 2) {
							cout << "今天共有" << cm.getClientNum() << "名顾客消费，消费总额为:" << coust.getInsideCoust() + coust.getOutsideCoust() << "元" << endl;
							cout << "其中\n在店就餐消费为:" << coust.getInsideCoust() << "元\n";
							cout << "外卖消费为:" << coust.getOutsideCoust() << "元\n";
							cout << "--------------------------------------" << endl;
							cm.showAll();
						}
						//今日反馈

						else if (AdminChoice == 3) {
							int order = smap.showOrderChangeMap();
							while (true)
							{
								if (order == 1) {
									cout << "请选择您要查找订单的方式:\n(订单号查询 输入1\t电话号码查询 输入2)\n";
									int o;
									cin >> o;
									if (o == 1) {
										int op;
										cout << "请输入订单号:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "无此订单号\n";
											break;
										}
										cm.client[op].showCientMessage();
										break;
									}
									//订单号查询

									else if (o == 2) {
										string op;
										int i;
										cout << "请输入电话号码:"; cin >> op;
										for (i = 0; i < cm.getClientNum(); i++) {
											if (cm.client[i].getPhone() == op) {
												cm.client[i].showCientMessage();
												break;
											}
												
										}
										if (i >= cm.getClientNum()) {
											cout << "无此电话号码对应的订单\n";
											break;
									}
									break;

									}
									//电话号码查询
								}
								//查找订单

								else if (order == 2) {
									cout << "请选择您要修改订单的方式:\n(订单号查询 输入1\t电话号码查询 输入2)\n";
									int o;
									cin >> o;

									if (o == 1) {
										int op;
										cout << "请输入订单号:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "无此订单号\n";
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
										cout << "请输入电话号码:"; cin >> op;
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
											cout << "无此号码对应的订单\n";
										break;
									}
								}
								//修改订单

								else if (order == 3) {
									cout << "请选择您要删除订单的方式:(订单号查询 输入1\t电话号码查询 输入2)\n";
									int o;
									cin >> o;

									if (o == 1) {
										int op;
										cout << "请输入订单号:"; cin >> op;
										op--;
										if (op >= cm.getClientNum()) {
											cout << "无此订单号\n";
											break;
										}
										cm.client[op].judge = 2;
										
										if (cm.client[op].getType() == 1)
											coust.addInsideCoust(-cm.client[op].getCoust());
										else
											coust.addOutsideCoust(-cm.client[op].getCoust());
										
										cout << "该订单已删除\n\n";
										cm.client[op].setCoust(0);
										break;
									}

									else if (o == 2) {
										string op;
										int i;
										cout << "请输入电话号码:"; cin >> op;
										for (i = 0; i < cm.getClientNum(); i++) {
											if (cm.client[i].getPhone() == op) {
												cm.client[i].judge = 2;
												if (cm.client[i].getType() == 1) 
													coust.addInsideCoust(-cm.client[i].getCoust());
												else
													coust.addOutsideCoust(-cm.client[i].getCoust());
												cout << "该订单已删除\n\n";
												cm.client[i].setCoust(0);
												break;
											}
										}
										if (i >= cm.getClientNum()) 
											cout << "无此号码对应的订单\n";
										break;
									}
								}
								//删除订单

								else
									break;
							}
							//订单管理
						}

						else if (AdminChoice == 4) {
							string date, s;
							char tem(0);
							cout << "请输入您要查询的日期 (年-月-日)(如2020-5-20) ：";
							cin >> date;
							string a = "./data/" + date + ".txt";
							ioFile.open(a, ios::_Nocreate);//判断有无该天文件，若没有，则不创建新文件
							if (!ioFile)
								cout << "\n没有这一天的订单信息\n\n";
							ioFile.close();

							ioFile.open(a, ios::in);
							
							while (!ioFile.eof()) {
								ioFile.get(tem);
								s += tem;
							}
							cout << s << endl;

						}
						//历史订单查询

						else
							break;
						//退出
					}
					break;
				}
				//登录界面
				else if (oo == 2) {
					string id, pas1, pas2;
					cout << "注册界面\n请输入您的账号:";
					cin >> id; cout << endl;
					cout << "请输入您的密码:";
					cin >> pas1;
					cout << "\n请再次确认密码:";
					cin >> pas2;
					cout << endl;
					if (pas1 == pas2) {
						cout << "注册成功！\n\n";
						ad.addAdmin(id, pas1);
						break;
					}
					else
					{
						cout << "两次密码不一样，请重新输入\n\n";
						break;
					}
				}
				//注册界面
			}
			
		}
		//管理员系统
		else if (StstemMapChoice == 3) {//退出系统并保存
			cout << "请输入今日的日期 (年-月-日)(如2020-5-20) ：";
			string a;
			cin >> a;
			string b = "./data/" + a + "order.txt";
			string c= "./data/" + a + ".txt";
			
			ioFile.open(b, ios::out, ios::_Noreplace);
			ioFile << a << endl << cm.getClientNum() << "名顾客消费，消费总额为:" << coust.getInsideCoust() + coust.getOutsideCoust() << "元" << endl;
			ioFile << "在店就餐消费为:" << coust.getInsideCoust() << "元\n";
			ioFile << "外卖消费为:" << coust.getOutsideCoust() << "元\n";
			ioFile << "--------------------------------------" << endl;
			for (int i = 0; i < cm.getClientNum(); i++) {
				ioFile << "第" << i + 1 << "单：\n" << "姓名:\t" << cm.client[i].getName() << endl;
				ioFile << "电话号码:\t" << cm.client[i].getPhone() << endl;
				if (cm.client[i].getType() == 1){
					ioFile << "就餐方式为:\t在店就餐\n" << "餐桌号为:\t" << cm.client[i].getDesk() << endl;
					ioFile << "总共消费为:\t" << cm.client[i].getCoust() + cm.client[i].getDeskCoust() << "元" << endl;
				}
					
				else{
					ioFile << "就餐方式为:\t外卖就餐\n地址为:\t" << cm.client[i].getAddress() << endl;
					ioFile << "总共消费为:\t" << cm.client[i].getCoust() + 5 << "元" << endl;
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
			ioFile << a << "销售情况" << endl;
			int q = 0;
			for (int i = 0; i < cm.getClientNum(); i++) 
				if (cm.client[i].judge == 1) 
					q++;
				
			ioFile << "一共销售出单数：\t" << q << endl;
			ioFile << "销售额为：\t" << coust.getInsideCoust() + coust.getOutsideCoust() << "元\n\n";
			ioFile << "在店销售额：\t" << coust.getInsideCoust() << "元\n";
			ioFile << "外卖销售额：\t" << coust.getOutsideCoust() << "元\n\n";
			ioFile << "菜品销售数量情况：\n\n";
			for (int i = 0; i < menu.getNum(); i++)
				ioFile << menu.food[i].getName() << "\t" << menu.food[i].getSaleNum() << "份\n";

			ioFile.close();

			cout << "成功退出系统" << endl << endl << endl;
			system("pause");
			return 0;
		}
		//退出系统
	}
	return 0;
}