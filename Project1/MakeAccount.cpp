#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

void MakeAccount() {
	int accID;
	char name[20];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accID;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;

	account[Account::GetAccNum()] = new Account(accID, name, balance);
	Account::IncreaseAccNum();
}