#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

void ShowAllAccInfo() {
	for (int i = 0; i < Account::GetAccNum(); i++) {
		cout << "����ID: " << account[i]->GetAccID() << endl;
		cout << "�� ��: " << account[i]->GetName() << endl;
		cout << "�� ��: " << account[i]->GetBalance() << endl;
	}
}