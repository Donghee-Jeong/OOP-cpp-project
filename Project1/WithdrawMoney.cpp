#include "Account.h"
using namespace std;
#include <iostream>

extern Account* account[];

int InputWithdrawID() {
	int accID;
	cout << "����ID: ";
	cin >> accID;
	
	return accID;
}

int InputWithdrawMoney() {
	int money;
	cout << "��ݾ�: ";
	cin >> money;
	return money;
}

void Withdraw() {
	cout << "[�� ��]" << endl;
	int accID = InputWithdrawID();
	int money = InputWithdrawMoney();

	for (int i = 0; i < Account::GetAccNum(); i++) {
		if (account[i]->GetAccID() == accID) {
			if (account[i]->GetBalance() >= money) {
				account[i]->Withdraw(money);
				cout << "��ݿϷ�" << endl;
				return;
			}
			cout << "�ܾ��� �����մϴ�." << endl;
		}
	}
	cout << "���� �����Դϴ�." << endl;
}