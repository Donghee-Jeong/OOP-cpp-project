#include "Account.h"

int Account::accNum = 0;

void Account::Deposit(const int money) {
	balance += money;
}

void Account::Withdraw(const int money) {
	balance -= money;
}

void Account::IncreaseAccNum() {
	accNum++;
}

void Account::SetAccNum0() {
	accNum = 0;
}