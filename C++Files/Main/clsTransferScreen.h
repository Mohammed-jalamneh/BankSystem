#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

	static void TransferScreen()
	{
		system("cls");

		cout << cMagenta;
		ShowScreenHeader("Transfer Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cMagenta << "\n===================================================\n";

		cout << cYellow << "\n    [?] Enter Account Number to Transfer From: " << cReset;
		string SAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(SAccountNumber))
		{
			cout << cRed << "    [!] Account Number not found.\n" << cReset;
			cout << cYellow << "    [?] Enter another Account Number: " << cReset;
			SAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient SourceClient = clsBankClient::Find(SAccountNumber);

		cout << cMagenta << "\n----------------- Source Client -------------------\n" << cWhite;
		_PrintClient(SourceClient);
		cout << cMagenta << "---------------------------------------------------\n\n" << cReset;

		cout << cYellow << "    [?] Enter Account Number to Transfer To: " << cReset;
		string DAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(DAccountNumber))
		{
			cout << cRed << "    [!] Account Number not found.\n" << cReset;
			cout << cYellow << "    [?] Enter another Account Number: " << cReset;
			DAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient DestinationClient = clsBankClient::Find(DAccountNumber);

		cout << cMagenta << "\n--------------- Destination Client ----------------\n" << cWhite;
		_PrintClient(DestinationClient);
		cout << cMagenta << "---------------------------------------------------\n\n" << cReset;

		cout << cGreen;
		float Amount = ReadAmount(SourceClient);

		cout << cYellow << "\n    Are you sure you want to perform this operation? (y/n): " << cReset;
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << cMagenta << "\n===================================================\n";
				cout << cGreen << "\n    [$] Transfer Performed Successfully!\n\n" << cReset;
			}
			else
			{
				cout << cMagenta << "\n===================================================\n";
				cout << cRed << "\n    [!] Transfer Failed.\n\n" << cReset;
			}
		}
		else
		{
			cout << cMagenta << "\n===================================================\n";
			cout << cYellow << "\n    [!] Transaction Cancelled.\n\n" << cReset;
		}

		cout << cMagenta << "----------------- Source Client -------------------\n" << cWhite;
		_PrintClient(SourceClient);
		cout << cMagenta << "--------------- Destination Client ----------------\n" << cWhite;
		_PrintClient(DestinationClient);
		cout << cMagenta << "---------------------------------------------------\n\n" << cReset;
	}

};

