#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

void MakeAccount() {
	int accID;
	char name[20];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accID;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;

	account[Account::GetAccNum()] = new Account(accID, name, balance);
	Account::IncreaseAccNum();
}