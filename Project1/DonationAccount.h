#ifndef __DONATIONACCOUNT_H__
#define __DONATIONACCOUNT_H__

#include "Account.h"
#include <iostream>
using namespace std;

class DonationAccount : public Account{
private:
	const int donateRate;
	int donateSum;
public:
	DonationAccount(const int _accountID, const char* name, const int _balance);
	DonationAccount(const DonationAccount& account);
	~DonationAccount();

	virtual void Deposit(const int money);
	virtual int GetBalance() const;
};

#endif