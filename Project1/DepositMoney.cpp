#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

int InputDepositID() {
	int accID;

	cout << "계좌ID: ";
	cin >> accID;

	return accID;
}

int InputDepositMoney() {
	int money;

	cout << "입금액: ";
	cin >> money;

	return money;
}

void Deposit() {
	cout << "[입 금]" << endl;
	int accID = InputDepositID();
	int money = InputDepositMoney();

	for (int i = 0; i < accNum; i++) {
		if (account[i].accountID == accID) {
			account[i].balance += money;
			cout << "입금완료" << endl;
			return;
		}
	}
}