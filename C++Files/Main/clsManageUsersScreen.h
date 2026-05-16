#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "iomanip"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

    enum _enManageUsersMenueOptions
    {
        ListUsers = 1, AddNewUsers, DeleteUsers, UpdateUsers, FindUsers, MainMenue
    };

    static short _ReadManageUsersMenu()
    {
        short n;
        cout << "\n";
        cout << "\033[36m";
        cout << setw(38) << left << "" << "Choose the util you want [1-6]:- ";
        n = clsInputValidate::ReadIntNumberBetween(1, 6);

        return n;

    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ManageUsersScreen();
	}

    static void _PerformManageUsersMenue(_enManageUsersMenueOptions option)
    {
        switch (option)
        {
        case _enManageUsersMenueOptions::ListUsers:
        {
            system("cls");

			clsListUsersScreen::ShowUsersList();
			_GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::AddNewUsers:
        {
            system("cls");
			clsAddNewUserScreen::AddNewUser();
            _GoBackToManageUsersMenue();
            break;

        }

        case _enManageUsersMenueOptions::DeleteUsers:
        {
            system("cls");
			clsDeleteUserScreen::DeleteUser();
            _GoBackToManageUsersMenue();

            break;

        }

        case _enManageUsersMenueOptions::UpdateUsers:
        {

            system("cls");
			clsUpdateUserScreen::ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();

            break;

        }

        case _enManageUsersMenueOptions::FindUsers:
        {

            system("cls");
			clsFindUserScreen::FindUser();
            _GoBackToManageUsersMenue();

            break;
        }

        case _enManageUsersMenueOptions::MainMenue:
            break;

        }

    }


public:


    static void ManageUsersScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) return;

        system("cls");

        cout << cCyan;
        ShowScreenHeader("Manage Users Screen");

        cout << cYellow;
        CurrentUserAndSystemDate();

        cout << cCyan
            << setw(37) << left << "" << "===========================================\n"
            << setw(37) << left << "" << "|              Manage Users               |\n"
            << setw(37) << left << "" << "===========================================\n"
            << setw(37) << left << "" << "|" << cGreen << "    [1] List Users.                      " << cCyan << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [2] Add New User.                    " << cCyan << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [3] Delete User.                     " << cCyan << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [4] Update User.                     " << cCyan << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [5] Find User.                       " << cCyan << "|\n"
            << setw(37) << left << "" << "|" << cRed << "    [6] Main Menu.                       " << cCyan << "|\n"
            << setw(37) << left << "" << "===========================================\n\n"
            << cReset;

        _PerformManageUsersMenue((_enManageUsersMenueOptions)_ReadManageUsersMenu());
    }


};
