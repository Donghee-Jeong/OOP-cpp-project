#ifndef __CREDITACCOUNT_H__
#define __CREDITACCOUNT_H__

#include "Account.h"

class CreditAccount : public Account {
private:
	const int interest;
public:
	CreditAccount(const int _accountID, const char* name, const int _balance);
	CreditAccount(const CreditAccount& account);
	~CreditAccount();

	virtual void Deposit(const int money);
};

#endif // !__HIGHCREDITACCOUNT_H__
