#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "iomanip"
#include "clsUser.h"
#include <vector>
using namespace std;

class clsListUsersScreen : protected clsScreen
{

private: 

    static void _PrintUsersRecordLine(clsUser User)
    {

        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(27) << left << User.Email;
        cout << "| " << setw(15) << left << User.Password;
        cout << "| " << setw(5) << left << User.Permissions;

    }


public :

	static void ShowUsersList()
	{
		system("cls");

		cout << cBlue;
		clsScreen::ShowScreenHeader("Users list screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		vector <clsUser> vUsers = clsUser::GetUsersList();

		cout << cBlue << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).\n";
		cout << "____________________________________________________________________________________________________________________\n\n";

		cout << cBlue << "| " << cYellow << left << setw(15) << "User Name"
			<< cBlue << "| " << cYellow << left << setw(20) << "Full Name"
			<< cBlue << "| " << cYellow << left << setw(12) << "Phone"
			<< cBlue << "| " << cYellow << left << setw(29) << "Email"
			<< cBlue << "| " << cYellow << left << setw(15) << "Password"
			<< cBlue << "| " << cYellow << left << setw(5) << "Permissions\n";

		cout << cBlue << "____________________________________________________________________________________________________________________\n\n";

		if (vUsers.size() == 0)
		{
			cout << cRed << "\t\t\t\tNo Users Available In the System!\n";
		}
		else
		{
			cout << cWhite;
			for (clsUser Users : vUsers)
			{
				_PrintUsersRecordLine(Users);
				cout << endl;
			}
		}

		cout << cBlue << "____________________________________________________________________________________________________________________\n\n" << cReset;
	}


};

