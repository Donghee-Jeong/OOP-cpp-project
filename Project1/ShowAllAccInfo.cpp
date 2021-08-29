#include "Account.h"
#include <iostream>
using namespace std;

extern Account account[];
extern int accNum;

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "°èÁÂID: " << account[i].accountID << endl;
		cout << "ÀÌ ¸§: " << account[i].name << endl;
		cout << "ÀÜ ¾×: " << account[i].balance << endl;
	}
}