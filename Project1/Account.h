#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	const int accountID;
	char* name;
	int balance;
	//static int accNum;
public:
	Account(const int _accountID, const char* name, const int _balance);
	Account(const Account& account);
	~Account() { delete[] name; }

	int GetAccID() const { return accountID; }
	int GetBalance() const { return balance; }
	const char* GetName() const { return name; }
	
	void Deposit(const int money);
	void Withdraw(const int money);

	//static int GetAccNum() { return accNum; }
	//static void IncreaseAccNum(); // �����ڿ� �־ �ɵ�. ��������ڴ� ��� ������ ����
	//static void SetAccNum0();
};

#endif // !__ACCOUNT_H__