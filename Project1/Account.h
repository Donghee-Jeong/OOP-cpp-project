#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>

class Account {
private:
	int accountID;
	char* name;
	int balance;
	static int accNum;
public:
	Account(const int _accountID, const char* name, const int _balance) :accountID(_accountID), balance(_balance) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Account(const Account& account) :accountID(account.accountID),balance(account.balance){
		this->name = new char[strlen(account.name) + 1];
		strcpy(this->name, account.name);
	}
	~Account() {
		delete[] name;
	}
	int GetAccID() const { return accountID; }
	int GetBalance() const { return balance; }
	const char* GetName() const { return name; }
	
	void Deposit(const int money);
	void Withdraw(const int money);

	static int GetAccNum() { return accNum; }
	static void IncreaseAccNum(); // �����ڿ� �־ �ɵ�. ��������ڴ� ��� ������ ����
	static void SetAccNum0();
};

#endif // !__ACCOUNT_H__