#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
const int NAME_LENGTH = 20;

class AccountHandler {
private:
	Account* account[100];
	int index;
public:
	AccountHandler();
	AccountHandler(const AccountHandler& ah);
	~AccountHandler();

	void Manager();
	void ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccInfo();
};
#endif // !__ACCOUNTHANDLER_H__
