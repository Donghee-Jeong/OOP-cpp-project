#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

int InputDepositID() {
	int accID;

	cout << "����ID: ";
	cin >> accID;

	return accID;
}

int InputDepositMoney() {
	int money;

	cout << "�Աݾ�: ";
	cin >> money;

	return money;
}

void Deposit() {
	cout << "[�� ��]" << endl;
	int accID = InputDepositID();
	int money = InputDepositMoney();

	for (int i = 0; i < accNum; i++) {
		if (account[i].accountID == accID) {
			account[i].balance += money;
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
}