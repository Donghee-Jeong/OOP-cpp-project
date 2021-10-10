
#include <iostream>
using namespace std;
#include "Account.h"
#include "ShowMenu.h"
#include "MakeAccount.h"
#include "DepositMoney.h"
#include "WithdrawMoney.h"
#include "ShowAllAccInfo.h"

extern Account* account[];

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

void Manager() {
	int choice = 0;
	while (choice != EXIT) {
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < Account::GetAccNum(); i++) {
		delete account[i];
	}
	Account::SetAccNum0();
	cout << "종료되었습니다.";
}