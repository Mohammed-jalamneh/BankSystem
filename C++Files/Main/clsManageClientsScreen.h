#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;

class clsManageClientsScreen : protected clsScreen
{
private:

	enum enManageClientsOption {
		ShowClientsList = 1, AddNewClient, DeleteClient,
		UpdateClient, FindClient , ManageClients
	};

	enManageClientsOption _enManageClientsOption;

	static void _GoBackToManageClientsScreen()
	{
		cout << "\n\nPress any key to go back to Manage Clients Screen...";
		system("pause>0");
		ManageClientsScreen();
		
	}

	static void _ShowClientList()
	{
		clsClientsListScreen::ShowClientsList();
		_GoBackToManageClientsScreen();
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

	static void _AddNewClient()
	{
		clsAddNewClientScreen::AddNewClient();
		_GoBackToManageClientsScreen();
	}

	static void _DeleteClient()
	{

		clsDeleteClientScreen::DeleteClient();
		_GoBackToManageClientsScreen();

	}

	static void _UpdateClient()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
		_GoBackToManageClientsScreen();
	}

	static void _FindClient()
	{
		clsFindClientScreen::FindClient();
		_GoBackToManageClientsScreen();
	}

	static void _PerfromManageClientsScreen(enManageClientsOption ManageClientsOption)
	{

		switch (ManageClientsOption)
		{
		case enManageClientsOption::ShowClientsList:
		{
			system("cls");
			_ShowClientList();
			break;
		}
		case enManageClientsOption::AddNewClient:
		{
			system("cls");
			_AddNewClient();
			break;
		}
		case enManageClientsOption::DeleteClient:
		{
			system("cls");
			_DeleteClient();
			break;
		}
		case enManageClientsOption::UpdateClient:
		{
			system("cls");
			_UpdateClient();
			break;
		}
		case enManageClientsOption::FindClient:
		{
			system("cls");
			_FindClient();
			break;
		}
		case enManageClientsOption::ManageClients:
		{
			
			break;
		}

		}

	}

	static short _ReadManageClientsOption()
	{
		short n;
		cout << "\n";
		cout << "\033[36m";
		cout << setw(38) << left << "" << "Choose the util you want [1-6]:- ";
		n = clsInputValidate::ReadIntNumberBetween(1, 6);

		return n;
	}


public:


	static void ManageClientsScreen()
	{
		system("cls");

		cout << cCyan;
		ShowScreenHeader("Manage Clients Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cCyan
			<< setw(37) << left << "" << "===========================================\n"
			<< setw(37) << left << "" << "|             Manage Clients              |\n"
			<< setw(37) << left << "" << "===========================================\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [1] Show Client List.                " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [2] Add New Client.                  " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [3] Delete Client.                   " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [4] Update Client.                   " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [5] Find Client.                     " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cRed << "    [6] Main Menu.                       " << cCyan << "|\n"
			<< setw(37) << left << "" << "===========================================\n\n"
			<< cReset;

		_PerfromManageClientsScreen((enManageClientsOption)_ReadManageClientsOption());
	}



};

