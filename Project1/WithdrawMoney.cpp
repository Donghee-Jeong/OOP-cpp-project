#include "Account.h"
using namespace std;
#include <iostream>

extern Account* account[];

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

	for (int i = 0; i < Account::GetAccNum(); i++) {
		if (account[i]->GetAccID() == accID) {
			if (account[i]->GetBalance() >= money) {
				account[i]->Withdraw(money);
				cout << "출금완료" << endl;
				return;
			}
			cout << "잔액이 부족합니다." << endl;
		}
	}
	cout << "없는 계좌입니다." << endl;
}