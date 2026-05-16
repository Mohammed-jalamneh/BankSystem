#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{

private:


	static void _PrintClientInfo(clsBankClient& Client)
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

	static void DepositScreen()
	{
		system("cls"); 
		cout << cMagenta;
		ShowScreenHeader("Deposit Screen");

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

		cout << cGreen << "    [+] Enter Amount to Deposit: " << cReset;
		int AmountToDeposit = clsInputValidate::ReadIntNumber();

		cout << cYellow << "\n    Are you sure you want to perform this transaction? (y/n): " << cReset;
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			Client1.Deposit(AmountToDeposit);

			cout << cMagenta << "\n===================================================\n";
			cout << cGreen << "\n    [$] Deposit Performed Successfully!\n";

			cout << "    [$] New Balance is: " << Client1.AccountBalance << "\n\n" << cReset;
		}
		else
		{
			cout << cMagenta << "\n===================================================\n";
			cout << cYellow << "\n    [!] Transaction Cancelled.\n\n" << cReset;
		}
	}



};

