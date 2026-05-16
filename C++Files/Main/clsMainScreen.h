#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsManageClientsScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsCurrancyExchangeMainScreen.h"
#include "Global.h"    

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

    enum enMainMenueOptions {
        ManageClient = 1, Transactions, ManageUsers , LoginRegister , CurrancyExchange , Logout
    };

    enMainMenueOptions _MainMenueMode;



    static short _ReadMainMenueScreen()
    {
        short n;
        cout << "\n";
        cout << cYellow;
        cout << setw(38) << left << "" << "Choose the util you want [1-6]:-\n ";
        cout << setw(38) << left << "";  n = clsInputValidate::ReadIntNumberBetween(1, 6);
        
        return n;

    }
   
    static void _GoBackToMainMenue()
    {
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		MainMenueScreen();
    }
   
    static void _ReadClientInfo(clsBankClient& Client)
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

    static void _ManageClient()
    {
        clsManageClientsScreen::ManageClientsScreen();
        _GoBackToMainMenue();
    }

    static void _Transactinos()
    {
		clsTransactionScreen::TransactionsMenueScreen();
        _GoBackToMainMenue();
    }

    static void _ManageUsers()
    {
		clsManageUsersScreen::ManageUsersScreen();
        _GoBackToMainMenue();
    }

    static void _LoginRegister()
    {
        clsShowLoginRegisterScreen::ShowUsersRegisterList();
        _GoBackToMainMenue();
    }

    static void _CurrancyExchange()
    {
        clsCurrancyExchangeMainScreen::ShowCurrancyExchangeMainScreen();
        _GoBackToMainMenue();
    }

    static void _Logout()
    {
       
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenue(enMainMenueOptions MainMenueOption)
    {

        switch (MainMenueOption)
        {
        case enMainMenueOptions::ManageClient:
        {
            system("cls");
            _ManageClient();
            break;
        }
        
        case enMainMenueOptions::Transactions:
        {
            system("cls");
            _Transactinos();
            break;
        }
        case enMainMenueOptions::ManageUsers:
        {
            system("cls");
            _ManageUsers();
            break;
        }
        case enMainMenueOptions::LoginRegister:
        {
            system("cls");
            _LoginRegister();
            break;
        }

        case enMainMenueOptions::CurrancyExchange:
        {
            system("cls");
            _CurrancyExchange();
            break;
        }
        case enMainMenueOptions::Logout:
        {
            system("cls");
            _Logout();
            return;
            
        }


        }


    }


public:

    static void MainMenueScreen()
    {
        system("cls");

        cout << cYellow;
        ShowScreenHeader("Main Menue Screen");

        cout << cWhite;
        CurrentUserAndSystemDate();

        cout << cYellow
            << setw(37) << left << "" << "===========================================\n"
            << setw(37) << left << "" << "|                Main Menue               |\n"
            << setw(37) << left << "" << "===========================================\n"
            << setw(37) << left << "" << "|" << cGreen << "    [1] Manage Clients.                  " << cYellow << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [2] Transactions.                    " << cYellow << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [3] Manage Users.                    " << cYellow << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [4] Login Register List.             " << cYellow << "|\n"
            << setw(37) << left << "" << "|" << cGreen << "    [5] Currency Exchange.               " << cYellow << "|\n"
            << setw(37) << left << "" << "|" << cRed << "    [6] Logout.                          " << cYellow << "|\n"
            << setw(37) << left << "" << "===========================================\n\n"
            << cReset;

        _PerfromMainMenue((enMainMenueOptions)_ReadMainMenueScreen());
    }
    
    

};

