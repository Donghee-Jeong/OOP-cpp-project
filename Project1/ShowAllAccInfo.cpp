#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << account[i].accountID << endl;
		cout << "�� ��: " << account[i].name << endl;
		cout << "�� ��: " << account[i].balance << endl;
	}
}