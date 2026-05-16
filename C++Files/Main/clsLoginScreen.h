#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsLoginRegister.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static string ReadUserName()
	{
		string UserName;

		cin >> UserName;

		return UserName;
	}

	static string ReadPassword()
	{
		string Password;

		cin >> Password;

		return Password;
	}



public:

	static bool ShowLoginScreen()
	{
		string UserName, Password;
		bool LoginStatus = false;
		short Counter = 3;

		do
		{
			system("cls");

			cout << cCyan
				<< "\n\n"
				<< setw(37) << left << "" << "===========================================\n"
				<< setw(37) << left << "" << "|          SYSTEM LOGIN REQUIRED          |\n"
				<< setw(37) << left << "" << "===========================================\n\n";

			if (LoginStatus)
			{
				Counter--;

				if (Counter == 0)
				{
					cout << cRed << setw(37) << left << "" << "[!] SYSTEM LOCKED: 3 Failed Attempts.\n\n" << cReset;
					return false; // Exit immediately
				}

				cout << cRed << setw(37) << left << "" << "[!] Invalid Username or Password!\n";
				cout << cRed << setw(37) << left << "" << "[!] You have " << Counter << " trial(s) remaining.\n\n";
			}

			cout << cYellow << setw(37) << left << "" << "Enter Username : " << cReset;
			UserName = ReadUserName();

			cout << cYellow << setw(37) << left << "" << "Enter Password : " << cReset;
			Password = ReadPassword();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginStatus = CurrentUser.IsEmpty();

		} while (LoginStatus);

		clsLoginRegister::AddRegisteredUserToFile();
		clsMainScreen::MainMenueScreen();

		return true;
	}

};

