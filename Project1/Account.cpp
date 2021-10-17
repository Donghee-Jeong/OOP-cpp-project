#include "Account.h"
#include <iostream>
//int Account::accNum = 0;

Account::Account(const int _accountID, const char* name, const int _balance) :accountID(_accountID), balance(_balance) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& account) : accountID(account.accountID), balance(account.balance) {
	this->name = new char[strlen(account.name) + 1];
	strcpy(this->name, account.name);
}

void Account::Deposit(const int money) {
	balance += money;
}

void Account::Withdraw(const int money) {
	balance -= money;
}

//void Account::IncreaseAccNum() {
//	accNum++;
//}
//
//void Account::SetAccNum0() {
//	accNum = 0;
//}