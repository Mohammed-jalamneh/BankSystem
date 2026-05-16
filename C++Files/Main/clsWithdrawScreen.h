#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{

private:


	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\nClient Account Info :-\n";
		cout << "\nClient Name: " << Client.FullName();
		cout << "\nAccount Number: " << Client.AccountNumber();
		cout << "\nCurrent Balance: " << Client.AccountBalance;
	}

	static string _ReadAccountNumber()
	{
		cout << "\nEnter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}


public:

	static void WithdrawScreen()
	{
		system("cls");

		cout << cMagenta;
		ShowScreenHeader("Withdraw Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cMagenta << "\n===================================================\n";

		cout << cYellow << "\n    [?] Enter Account Number: " << cReset;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << cRed << "    [!] Account Number is not found.\n" << cReset;
			cout << cYellow << "    [?] Enter another Account Number: " << cReset;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		cout << cMagenta << "\n----------------- Client Details ------------------\n" << cWhite;
		_PrintClientInfo(Client1);
		cout << cMagenta << "\n---------------------------------------------------\n\n" << cReset;

		cout << cGreen << "    [-] Enter Amount to Withdraw: " << cReset;
		int Amount = clsInputValidate::ReadIntNumber();

		cout << cYellow << "\n    Are you sure you want to perform this transaction? (y/n): " << cReset;
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << cMagenta << "\n===================================================\n";
				cout << cGreen << "\n    [$] Amount Withdrawn Successfully.\n";
				cout << "    [$] New Balance: " << Client1.AccountBalance << "\n\n" << cReset;
			}
			else
			{
				cout << cMagenta << "\n===================================================\n";
				cout << cRed << "\n    [!] Failed to Withdraw Amount.\n";
				cout << "    [!] Amount exceeds current balance.\n";
				cout << "    [!] Current Balance: " << Client1.AccountBalance << "\n\n" << cReset;
			}
		}
		else
		{
			cout << cMagenta << "\n===================================================\n";
			cout << cYellow << "\n    [!] Transaction Cancelled.\n\n" << cReset;
		}
	}



};

