#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

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

	for (int i = 0; i < Account::GetAccNum(); i++) {
		if (account[i]->GetAccID() == accID) {
			account[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "���� �����Դϴ�." << endl;
}