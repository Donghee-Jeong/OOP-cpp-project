#include "Account.h"
#include <iostream>
using namespace std;

extern Account* account[];

void ShowAllAccInfo() {
	for (int i = 0; i < Account::GetAccNum(); i++) {
		cout << "°èÁÂID: " << account[i]->GetAccID() << endl;
		cout << "ÀÌ ¸§: " << account[i]->GetName() << endl;
		cout << "ÀÜ ¾×: " << account[i]->GetBalance() << endl;
	}
}