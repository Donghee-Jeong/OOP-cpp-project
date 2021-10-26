#include "AccountHandler.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

AccountHandler::AccountHandler() : index(0) {}
AccountHandler::AccountHandler(const AccountHandler& ah) : index(ah.index) {
	for (int i = 0; i < index; i++) {
		account[i] = new Account(*ah.account[i]);
	}
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < index; i++) {
		delete account[i];
	}
}

void AccountHandler::Manager() {
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
	cout << "종료되었습니다.";
}

void AccountHandler::ShowMenu() const{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount() {
	int accID;
	char name[NAME_LENGTH];
	int balance;
	int interest;
	int level;
	int accountType;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> accountType;

	switch (accountType) {
	case 1:
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> accID;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "이자율: ";
		cin >> interest;
		account[index++] = new NormalAccount(accID, name, balance, interest);
		break;
	case 2:
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> accID;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "이자율: ";
		cin >> interest;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> level;
		account[index++] = new HighCreditAccount(accID, name, balance, interest, level);
		break;
	}
		//new Account(accID, name, balance);
}

void AccountHandler::Deposit() {
	int accID;
	int money;

	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < index; i++) {
		if (account[i]->GetAccID() == accID) {
			cout << "입금액: ";
			cin >> money;
			account[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "없는 계좌입니다." << endl;
}

void AccountHandler::Withdraw() {
	int accID;
	int money;

	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < index; i++) {
		if (account[i]->GetAccID() == accID) {
			cout << "출금액: ";
			cin >> money;
			if (account[i]->GetBalance() >= money) {
				account[i]->Withdraw(money);
				cout << "출금완료" << endl;
				return;
			}
			cout << "잔액이 부족합니다." << endl;
			return;
		}
	}
	cout << "없는 계좌입니다." << endl;
}

void AccountHandler::ShowAllAccInfo() const{
	for (int i = 0; i < index; i++) {
		cout << "계좌ID: " << account[i]->GetAccID() << endl;
		cout << "이 름: " << account[i]->GetName() << endl;
		cout << "잔 액: " << account[i]->GetBalance() << endl;
	}
}