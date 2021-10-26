#include "NormalAccount.h"

NormalAccount::NormalAccount(const int _accountID, const char* name, const int _balance, const int _interest)
	:Account(_accountID, name, _balance), interest(_interest) {};
NormalAccount::NormalAccount(const NormalAccount& account)
	:Account(account.GetAccID(), account.GetName(), account.GetBalance()), interest(account.GetInterest()) {};
NormalAccount::~NormalAccount() {};

void NormalAccount::Deposit(const int money) {
	Account::Deposit(money);
	Account::Deposit(money * (interest / 100.0));
}