#ifndef __ACCMANAGER_H__
#define __ACCMANAGER_H__

#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include "Container.h"
#include "String.h"

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
const int NAME_LENGTH = 20;

class AccManager {
private:
	//Account* account[100];
	Container container;
	//int index;
public:
	AccManager(int len);
	AccManager(const AccManager& am);
	AccManager& operator=(const AccManager& am);
	~AccManager();

	void Manager();
	void ShowMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccInfo() const;
};
#endif // !__ACCOUNTHANDLER_H__
