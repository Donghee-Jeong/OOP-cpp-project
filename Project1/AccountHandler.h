#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

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
	void ShowMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccInfo() const;
};
#endif // !__ACCOUNTHANDLER_H__
