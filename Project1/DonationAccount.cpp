#include "DonationAccount.h"

DonationAccount::DonationAccount(const int _accountID, const char* name, const int _balance)
	:Account(_accountID, name, _balance), donateRate(1), donateSum(0) {
	donateSum += (_balance * (donateRate / 100.0));
};
DonationAccount::DonationAccount(const int _accountID, const String name, const int _balance)
	:Account(_accountID, name, _balance), donateRate(1), donateSum(0) {
	donateSum += (_balance * (donateRate / 100.0));
};
DonationAccount::DonationAccount(const DonationAccount& account)
	:Account(account.GetAccID(), account.GetName(), account.GetBalance()), donateRate(1), donateSum(account.donateSum) {};
DonationAccount::~DonationAccount() {};

DonationAccount& DonationAccount::operator=(const DonationAccount& da) {
	Account::operator=(da);
	donateRate = da.donateRate;
	return *this;
}

void DonationAccount::Deposit(const int money) {
	Account::Deposit(money);
	donateSum += (money * (donateRate / 100.0));
}

int DonationAccount::GetBalance() const {
	cout << "��ε� �Ѿ�: " << donateSum << endl;
	return Account::GetBalance();
}