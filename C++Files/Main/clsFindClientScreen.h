#pragma once
#include<iostream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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



public:

	static void FindClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		system("cls"); 

		cout << cCyan;
		clsScreen::ShowScreenHeader("Find Client Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cCyan << "\n===================================================\n";
		cout << cYellow << "\n    Enter Account Number to Find : " << cReset;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << cRed << "    [!] Account number '" << AccountNumber << "' is not found.\n" << cReset;
			cout << cYellow << "    Enter Account Number again : " << cReset;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		cout << cCyan << "\n===================================================\n";
		cout << cGreen << "\n    [-] Client Found Successfully!\n\n" << cReset;

		cout << cCyan << "----------------- Client Details ------------------\n" << cReset;
		_Print(Client);
		cout << cCyan << "---------------------------------------------------\n\n" << cReset;
	}

};

