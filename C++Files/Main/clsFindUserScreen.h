 #pragma once
#include<iostream>
#include <vector>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

	static void _Print(clsUser User)
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nPhone          : " << User.Phone;
		cout << "\nEmail          : " << User.Email;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions;
		cout << "\n___________________\n";
	}



public:

	static void FindUser()
	{
		system("cls");

		cout << cBlue;
		clsScreen::ShowScreenHeader("Find User Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cBlue << "\n===================================================\n";
		cout << cYellow << "\n    Please Enter User Name: " << cReset;
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << cRed << "    User Name is not found.\n" << cReset;
			cout << cYellow << "    Choose another one: " << cReset;
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		cout << cBlue << "\n===================================================\n";
		cout << cGreen << "\n    User Name Found Successfully...\n\n" << cReset;

		cout << cBlue << "------------------ User Details -------------------\n" << cWhite;
		_Print(User);
		cout << cBlue << "---------------------------------------------------\n\n" << cReset;
	}



};

