#pragma once
#include <iostream>
#include "clsLoginRegister.h"
#include "clsScreen.h"
#include "iomanip"
#include "clsDate.h"
using namespace std;

class clsShowLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintUsersRegisterRecordLine(clsLoginRegister User)
	{
		cout << cBlue << "| " << cWhite << left << setw(30) << User.GetDate()
			<< cBlue << "| " << cWhite << left << setw(20) << User.GetUserName()
			<< cBlue << "| " << cWhite << left << setw(20) << User.GetPassword()
			<< cBlue << "| " << cWhite << left << setw(15) << User.GetPermission();
	}


public:

	

	static void ShowUsersRegisterList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		system("cls");

		cout << cBlue;
		clsScreen::ShowScreenHeader("Login Registers List Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		vector <clsLoginRegister> vUsers = clsLoginRegister::GetUsersRegisterList();

		cout << cBlue << "\n\t\t\t\t\tLogin Register List (" << vUsers.size() << ") Record(s).\n";
		cout << "________________________________________________________________________________________________\n\n";

		cout << cBlue << "| " << cYellow << left << setw(30) << "Date/Time"
			<< cBlue << "| " << cYellow << left << setw(20) << "User Name"
			<< cBlue << "| " << cYellow << left << setw(20) << "Password"
			<< cBlue << "| " << cYellow << left << setw(15) << "Permissions\n";

		cout << cBlue << "________________________________________________________________________________________________\n\n";

		if (vUsers.size() == 0)
		{
			cout << cRed << "\t\t\t\tNo Users Available In the System!\n";
		}
		else
		{
			for (clsLoginRegister Users : vUsers)
			{
				_PrintUsersRegisterRecordLine(Users);
				cout << endl;
			}
		}

		cout << cBlue << "________________________________________________________________________________________________\n\n" << cReset;
	}

};

