#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int _accountID, const char* name, const int _balance, const int _interest, const int _level)
	:NormalAccount(_accountID, name, _balance, _interest), level(_level) {
	switch (_level) {
	case LEVEL_A:
		specialInterest = 7;
		break;
	case LEVEL_B:
		specialInterest = 4;
		break;
	case LEVEL_C:
		specialInterest = 2;
		break;
	}
}

HighCreditAccount::HighCreditAccount(const HighCreditAccount& account)
	:NormalAccount(account.GetAccID(), account.GetName(), account.GetBalance(), account.GetInterest()),
	level(account.level), specialInterest(account.specialInterest) {}

HighCreditAccount::~HighCreditAccount() {}

void HighCreditAccount::Deposit(const int money) {
	NormalAccount::Deposit(money);
	Account::Deposit(money * (specialInterest / 100.0));
}