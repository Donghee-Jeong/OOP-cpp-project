#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

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

	account[accNum].accountID = accID;
	account[accNum].balance = balance;
	strcpy_s(account[accNum].name, name);
	accNum++;
}