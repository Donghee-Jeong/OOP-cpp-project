
#include <iostream>
using namespace std;
#include "ShowMenu.h"
#include "MakeAccount.h"
#include "DepositMoney.h"
#include "WithdrawMoney.h"
#include "ShowAllAccInfo.h"

void Manager() {
	int choice = 0;
	while (choice != 5) {
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			ShowAllAccInfo();
			break;
		default:
			break;
		}
	}
	cout << "����Ǿ����ϴ�.";
}