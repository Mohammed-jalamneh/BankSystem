#pragma once
#include <iostream>
#include <vector>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private:

    bool MarkToDelete = false;

    static void _PrintUser(clsUser User)
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nUser Name: " << User.UserName;
        cout << "\nFull Name: " << User.FullName();
        cout << "\nPhone    : " << User.Phone;
        cout << "\nEmail    : " << User.Email;
        cout << "\nPassword : " << User.Password;
        cout << "\nPermission    : " << User.Permissions;
        
        cout << "\n___________________\n";

    }

public:

	static void DeleteUser()
	{
		system("cls");

		cout << cBlue;
		clsScreen::ShowScreenHeader("Delete User");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cBlue << "\n===================================================\n";
		cout << cYellow << "\n    Enter User Name: " << cReset;
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << cRed << "    User with user name " << UserName << " does not exist.\n" << cReset;
			cout << cYellow << "    Please enter another one: " << cReset;
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		cout << cBlue << "\n------------------ User Details -------------------\n" << cWhite;
		User.Print();
		cout << cBlue << "---------------------------------------------------\n\n" << cReset;

		char answer = 'n';
		cout << cYellow << "    Are you sure you want to delete this User? (y/n): " << cReset;
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << cBlue << "\n===================================================\n";

			if (User.Delete())
			{
				cout << cWhite;
				_PrintUser(User);
				cout << cGreen << "\n    User Deleted successfully.\n\n" << cReset;
			}
			else
			{
				cout << cRed << "\n    Error 303: User was not deleted.\n\n" << cReset;
			}
		}
		else
		{
			cout << cBlue << "\n===================================================\n";
			cout << cYellow << "\n    Deletion Cancelled.\n\n" << cReset;
		}
	}



};

