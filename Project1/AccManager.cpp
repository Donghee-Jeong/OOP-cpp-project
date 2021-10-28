#include "AccManager.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

AccManager::AccManager(int len): container(len)/*: index(0)*/ {}
AccManager::AccManager(const AccManager& am)/* : index(ah.index)*/ {
	/*for (int i = 0; i < index; i++) {
		account[i] = new Account(*ah.account[i]);
	}*/
	container = am.container;
}
AccManager& AccManager::operator=(const AccManager& am){
	/*index = am.index;
	for (int i = 0; i < index; i++) {
		delete account[i];
	}
	for (int i = 0; i < index; i++) {
		account[i] = new Account(*am.account[i]);
	}*/
	container = am.container;
	return *this;
}
AccManager::~AccManager() {
	/*for (int i = 0; i < index; i++) {
		delete account[i];
	}*/
}

void AccManager::Manager() {
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

void AccManager::ShowMenu() const{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccManager::MakeAccount() {
	int accID;
	String name;
	int balance;
	int accountType;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 신용 계좌 2. 기부 계좌" << endl;
	cout << "선택: ";
	cin >> accountType;

	switch (accountType) {
	case 1:
		cout << "[신용 계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> accID;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		//account[index++] = new CreditAccount(accID, name, balance);
		container.Insert(new CreditAccount(accID, name, balance));
		break;
	case 2:
		cout << "[기부 계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> accID;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		//account[index++] = new DonationAccount(accID, name, balance);
		container.Insert(new DonationAccount(accID, name, balance));
		break;
	}
		//new Account(accID, name, balance);
}

void AccManager::Deposit() {
	int accID;
	int money;

	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < /*index*/container.GetElemSum(); i++) {
		if (/*account[i]->GetAccID()*/container.GetItem(i)->GetAccID() == accID) {
			cout << "입금액: ";
			cin >> money;
			//account[i]->Deposit(money);
			container.GetItem(i)->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "없는 계좌입니다." << endl;
}

void AccManager::Withdraw() {
	int accID;
	int money;

	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < /*index*/container.GetElemSum(); i++) {
		if (/*account[i]->GetAccID()*/container.GetItem(i)->GetAccID() == accID) {
			cout << "출금액: ";
			cin >> money;
			if (/*account[i]->GetBalance()*/container.GetItem(i)->GetBalance() >= money) {
				//account[i]->Withdraw(money);
				container.GetItem(i)->Withdraw(money);
				cout << "출금완료" << endl;
				return;
			}
			cout << "잔액이 부족합니다." << endl;
			return;
		}
	}
	cout << "없는 계좌입니다." << endl;
}

void AccManager::ShowAllAccInfo() const{
	for (int i = 0; i < /*index*/container.GetElemSum(); i++) {
		cout << "계좌ID: " << /*account[i]*/container.GetItem(i)->GetAccID() << endl;
		cout << "이 름: " << /*account[i]*/container.GetItem(i)->GetName() << endl;
		cout << "잔 액: " << /*account[i]*/container.GetItem(i)->GetBalance() << endl;
	}
}