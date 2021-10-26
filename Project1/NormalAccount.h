#include "Account.h"

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

class NormalAccount : public Account {
private:
	int interest;
public:
	NormalAccount(const int _accountID, const char* name, const int _balance, const int _interest);
	NormalAccount(const NormalAccount& account);
	~NormalAccount();

	int GetInterest() const { return interest; }

	virtual void Deposit(const int money);
};

#endif