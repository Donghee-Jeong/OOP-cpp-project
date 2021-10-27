#include "AccManager.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

AccManager::AccManager() : index(0) {}
AccManager::AccManager(const AccManager& ah) : index(ah.index) {
	for (int i = 0; i < index; i++) {
		account[i] = new Account(*ah.account[i]);
	}
}
AccManager::~AccManager() {
	for (int i = 0; i < index; i++) {
		delete account[i];
	}
}

void AccManager::Manager() {
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

void AccManager::ShowMenu() const{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccManager::MakeAccount() {
	int accID;
	char name[NAME_LENGTH];
	int balance;
	int accountType;

	cout << "[������������]" << endl;
	cout << "1. �ſ� ���� 2. ��� ����" << endl;
	cout << "����: ";
	cin >> accountType;

	switch (accountType) {
	case 1:
		cout << "[�ſ� ���� ����]" << endl;
		cout << "����ID: ";
		cin >> accID;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		account[index++] = new CreditAccount(accID, name, balance);
		break;
	case 2:
		cout << "[��� ���� ����]" << endl;
		cout << "����ID: ";
		cin >> accID;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		account[index++] = new DonationAccount(accID, name, balance);
		break;
	}
		//new Account(accID, name, balance);
}

void AccManager::Deposit() {
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

void AccManager::Withdraw() {
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

void AccManager::ShowAllAccInfo() const{
	for (int i = 0; i < index; i++) {
		cout << "����ID: " << account[i]->GetAccID() << endl;
		cout << "�� ��: " << account[i]->GetName() << endl;
		cout << "�� ��: " << account[i]->GetBalance() << endl;
	}
}