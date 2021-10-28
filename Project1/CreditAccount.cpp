#include "CreditAccount.h"

CreditAccount::CreditAccount(const int _accountID, const char* name, const int _balance)
	:Account(_accountID, name, _balance), interest(1) {
	Account::Deposit(_balance * (interest / 100.0));
}
CreditAccount::CreditAccount(const int _accountID, const String name, const int _balance)
	:Account(_accountID, name, _balance), interest(1) {
	Account::Deposit(_balance * (interest / 100.0));
}

CreditAccount::CreditAccount(const CreditAccount& account)
	:Account(account.GetAccID(), account.GetName(), account.GetBalance()),
	interest(1) {}

CreditAccount& CreditAccount::operator=(const CreditAccount& ca) {
	Account::operator=(ca);
	interest = ca.interest;
	return *this;
}

CreditAccount::~CreditAccount() {}

void CreditAccount::Deposit(const int money) {
	Account::Deposit(money);
	Account::Deposit(money * (interest / 100.0));
}