#include "Account.h"
#include <iostream>
using namespace std;
//int Account::accNum = 0;

Account::Account(const int _accountID, const char* _name, const int _balance)
	:accountID(_accountID), name(_name), balance(_balance) {}
Account::Account(const int _accountID, const String _name, const int _balance)
	:accountID(_accountID), name(_name), balance(_balance) {}

Account::Account(const Account& account)
	: accountID(account.accountID), name(account.name), balance(account.balance) {}

Account& Account::operator=(const Account& account) {
	name = account.name;
	accountID = account.accountID;
	balance = account.balance;

	return *this;
}

void Account::Deposit(const int money) {
	if (money <= 0) throw money;
	balance += money;
}

void Account::Withdraw(const int money) {
	if (money <= 0 || money > balance) throw money;
	balance -= money;
}

//void Account::IncreaseAccNum() {
//	accNum++;
//}
//
//void Account::SetAccNum0() {
//	accNum = 0;
//}