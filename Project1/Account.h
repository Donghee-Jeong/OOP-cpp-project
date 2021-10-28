#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accountID;
	//char* name;
	String name;
	int balance;
	//static int accNum;
public:
	Account(const int _accountID, const char* _name, const int _balance);
	Account(const int _accountID, const String _name, const int _balance);
	Account(const Account& account);
	Account& operator=(const Account& account);
	~Account() {}

	int GetAccID() const { return accountID; }
	virtual int GetBalance() const { return balance; }
	const String GetName() const { return name; }
	
	virtual void Deposit(const int money);
	void Withdraw(const int money);

	//static int GetAccNum() { return accNum; }
	//static void IncreaseAccNum(); // 생성자에 넣어도 될듯. 복사생성자는 어떻게 할지가 문제
	//static void SetAccNum0();
};

#endif // !__ACCOUNT_H__