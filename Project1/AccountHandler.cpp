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
		cout << "����: ";
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
	cout << "����Ǿ����ϴ�.";
}

void AccountHandler::ShowMenu() const{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount() {
	int accID;
	char name[NAME_LENGTH];
	int balance;
	int interest;
	int level;
	int accountType;

	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> accountType;

	switch (accountType) {
	case 1:
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: ";
		cin >> accID;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "������: ";
		cin >> interest;
		account[index++] = new NormalAccount(accID, name, balance, interest);
		break;
	case 2:
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID: ";
		cin >> accID;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "������: ";
		cin >> interest;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> level;
		account[index++] = new HighCreditAccount(accID, name, balance, interest, level);
		break;
	}
		//new Account(accID, name, balance);
}

void AccountHandler::Deposit() {
	int accID;
	int money;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> accID;

	for (int i = 0; i < index; i++) {
		if (account[i]->GetAccID() == accID) {
			cout << "�Աݾ�: ";
			cin >> money;
			account[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "���� �����Դϴ�." << endl;
}

void AccountHandler::Withdraw() {
	int accID;
	int money;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> accID;

	for (int i = 0; i < index; i++) {
		if (account[i]->GetAccID() == accID) {
			cout << "��ݾ�: ";
			cin >> money;
			if (account[i]->GetBalance() >= money) {
				account[i]->Withdraw(money);
				cout << "��ݿϷ�" << endl;
				return;
			}
			cout << "�ܾ��� �����մϴ�." << endl;
			return;
		}
	}
	cout << "���� �����Դϴ�." << endl;
}

void AccountHandler::ShowAllAccInfo() const{
	for (int i = 0; i < index; i++) {
		cout << "����ID: " << account[i]->GetAccID() << endl;
		cout << "�� ��: " << account[i]->GetName() << endl;
		cout << "�� ��: " << account[i]->GetBalance() << endl;
	}
}