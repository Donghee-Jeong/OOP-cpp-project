#include "DonationAccount.h"

DonationAccount::DonationAccount(const int _accountID, const char* name, const int _balance)
	:Account(_accountID, name, _balance), donateRate(1), donateSum(0) {
	donateSum += (_balance * (donateRate / 100.0));
};
DonationAccount::DonationAccount(const DonationAccount& account)
	:Account(account.GetAccID(), account.GetName(), account.GetBalance()), donateRate(1), donateSum(account.donateSum) {};
DonationAccount::~DonationAccount() {};

void DonationAccount::Deposit(const int money) {
	Account::Deposit(money);
	donateSum += (money * (donateRate / 100.0));
}

int DonationAccount::GetBalance() const {
	cout << "±âºÎµÈ ÃÑ¾×: " << donateSum << endl;
	return Account::GetBalance();
}