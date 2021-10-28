#ifndef __DONATIONACCOUNT_H__
#define __DONATIONACCOUNT_H__

#include "Account.h"
#include "String.h"
#include <iostream>
using namespace std;

class DonationAccount : public Account{
private:
	int donateRate;
	int donateSum;
public:
	DonationAccount(const int _accountID, const char* name, const int _balance);
	DonationAccount(const int _accountID, const String name, const int _balance);
	DonationAccount(const DonationAccount& account);
	DonationAccount& operator=(const DonationAccount& da);
	~DonationAccount();

	virtual void Deposit(const int money);
	virtual int GetBalance() const;
};

#endif