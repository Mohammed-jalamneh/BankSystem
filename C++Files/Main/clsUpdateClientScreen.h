#pragma once
#include<iostream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _Print(clsBankClient Client)
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName      : " << Client.FirstName;
        cout << "\nLastName       : " << Client.LastName;
        cout << "\nFull Name      : " << Client.FullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nPin Code       : " << Client.PinCode;
		cout << "\nAccount Balance: " << Client.AccountBalance;
        cout << "\n___________________\n";

    }


    static void _ReadUpdatedClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }



public :

    static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		system("cls"); 
		cout << cCyan;
		ShowScreenHeader("Update Client Screen"); 

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cCyan << "\n===================================================\n";
		cout << cYellow << "\n    Enter Account Number to Update : " << cReset;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << cRed << "    [!] Account number '" << AccountNumber << "' is not found.\n" << cReset;
			cout << cYellow << "    Enter Account Number again : " << cReset;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		cout << cCyan << "\n----------------- Current Details -----------------\n" << cReset;
		_Print(Client1);
		cout << cCyan << "---------------------------------------------------\n\n" << cReset;

		cout << cYellow << "    Are you sure you want to update this client? (y/n): " << cReset;
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << cCyan << "\n===================================================\n";
			cout << cYellow << "    Enter New Client Info:\n";
			cout << cCyan << "---------------------------------------------------\n" << cReset;

			_ReadUpdatedClientInfo(Client1);

			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client1.Save();

			cout << cCyan << "\n===================================================\n";

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << cGreen << "\n    [-] Account Updated Successfully :-)\n\n" << cReset;

				cout << cCyan << "----------------- Updated Details -----------------\n" << cReset;
				_Print(Client1);
				cout << cCyan << "---------------------------------------------------\n\n" << cReset;
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << cRed << "\n    [!] Error: Account was not saved because it's Empty.\n" << cReset;
				break;
			}
			}
		}
		else
		{
			cout << cCyan << "\n===================================================\n";
			cout << cYellow << "\n    [!] Update Cancelled.\n\n" << cReset;
		}
	}





};

