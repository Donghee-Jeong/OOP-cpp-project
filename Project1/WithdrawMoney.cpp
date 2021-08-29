#include "Account.h"
using namespace std;
#include <iostream>

extern Account account[];
extern int accNum;

int InputWithdrawID() {
	int accID;
	cout << "계좌ID: ";
	cin >> accID;
	
	return accID;
}

int InputWithdrawMoney() {
	int money;
	cout << "출금액: ";
	cin >> money;
	return money;
}

void Withdraw() {
	cout << "[출 금]" << endl;
	int accID = InputWithdrawID();
	int money = InputWithdrawMoney();

	for (int i = 0; i < accNum; i++) {
		if (account[i].accountID = accID) {
			account[i].balance -= money;
			cout << "출금완료" << endl;
			return;
		}
	}
}