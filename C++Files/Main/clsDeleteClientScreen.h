#pragma once
#include<iostream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

	bool MarkToDelete = false;

   static void _Print(clsBankClient Client)
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << Client.FirstName;
        cout << "\nLastName : " << Client.LastName;
        cout << "\nFull Name: " << Client.FullName();
        cout << "\nEmail    : " << Client.Email;
        cout << "\nPhone    : " << Client.Phone;
        cout << "\n___________________\n";

    }


public :



	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		system("cls"); 

		cout << cCyan;
		clsScreen::ShowScreenHeader("Delete Client Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cCyan << "\n===================================================\n";
		cout << cYellow << "\n    Enter Account Number to Delete : " << cReset;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << cRed << "    [!] Account number '" << AccountNumber << "' does not exist.\n" << cReset;
			cout << cYellow << "    Enter Account Number again : " << cReset;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		cout << cCyan << "\n----------------- Client Details ------------------\n" << cReset;
		Client.Print(); 
		cout << cCyan << "---------------------------------------------------\n\n" << cReset;

		char answer = 'n';
		cout << cYellow << "    Are you sure you want to delete this Client? (y/n): " << cReset;
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			Client.MarkClientForDelete();

			cout << cCyan << "\n===================================================\n";
			cout << cGreen << "\n    [-] Client Deleted Successfully!\n\n" << cReset;

		}
		else
		{
			cout << cCyan << "\n===================================================\n";
			cout << cYellow << "\n    [!] Deletion Cancelled.\n\n" << cReset;
		}
	}

};

