#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

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

	for (int i = 0; i < Account::GetAccNum(); i++) {
		if (account[i]->GetAccID() == accID) {
			account[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "없는 계좌입니다." << endl;
}