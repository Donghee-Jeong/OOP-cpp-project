#include "Account.h"
using namespace std;
#include <iostream>

extern Account account[];
extern int accNum;

int InputWithdrawID() {
	int accID;
	cout << "����ID: ";
	cin >> accID;
	
	return accID;
}

int InputWithdrawMoney() {
	int money;
	cout << "��ݾ�: ";
	cin >> money;
	return money;
}

void Withdraw() {
	cout << "[�� ��]" << endl;
	int accID = InputWithdrawID();
	int money = InputWithdrawMoney();

	for (int i = 0; i < accNum; i++) {
		if (account[i].accountID = accID) {
			account[i].balance -= money;
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
}