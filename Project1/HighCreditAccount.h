#include "NormalAccount.h"

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

enum { LEVEL_A = 1, LEVEL_B, LEVEL_C };

class HighCreditAccount : public NormalAccount {
private:
	int level;
	int specialInterest;
public:
	HighCreditAccount(const int _accountID, const char* name, const int _balance, const int _interest, const int _level);
	HighCreditAccount(const HighCreditAccount& account);
	~HighCreditAccount();

	virtual void Deposit(const int money);
};

#endif // !__HIGHCREDITACCOUNT_H__
