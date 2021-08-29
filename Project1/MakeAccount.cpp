#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

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

	account[accNum].accountID = accID;
	account[accNum].balance = balance;
	strcpy_s(account[accNum].name, name);
	accNum++;
}