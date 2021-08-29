#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

typedef struct {
	int accountID;
	char name[20];
	int balance;
} Account;

#endif // !__ACCOUNT_H__