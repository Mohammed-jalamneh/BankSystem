#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:

	

	enum enTransactionsMenueOptions
	{
		Deposite = 1 , Withdraw , TotalBalances , Transfer , TransferLog ,MainMeneu
	};

	static int _ReadTransactionMenueOption()
	{
		int n;
		cout << "\n";
		cout << "\033[36m";
		cout << setw(37) << left << "" << "Choose the util you want [1-6] :- ";
		n = clsInputValidate::ReadIntNumberBetween(1, 6);
		return n;
	}



	static void _DepositeScreen()
	{
		clsDepositScreen::DepositScreen();
	}

	static void _WithdrawScreen()
	{
		clsWithdrawScreen::WithdrawScreen();
	}

	static void _TotalBalancesScreen()
	{
		clsTotalBalancesScreen::TotalBalances();
	}

	static void _TransferScreen()
	{
		clsTransferScreen::TransferScreen();
		_GoBackToTransactionsMenue();
	}

	static void _TransferLog()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
		_GoBackToTransactionsMenue();

	}

	static void _MainMenueSscreen()
	{
		return;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		TransactionsMenueScreen();

	}

	static void _PerfomTransactionsMenueOption(enTransactionsMenueOptions option)
	{
		switch (option)
		{
		case enTransactionsMenueOptions::Deposite:
		{
			system("cls");
			_DepositeScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::Withdraw:
		{
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		}

		case enTransactionsMenueOptions::TotalBalances:
		{
			system("cls");
			_TotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::Transfer:
		{
			system("cls");
			_TransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::TransferLog:
		{
			system("cls");
			_TransferLog();
			_GoBackToTransactionsMenue();
			break;
		}


		case enTransactionsMenueOptions::MainMeneu:
		{
			break;

		}
		}

	}

public :

	static void TransactionsMenueScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions)) return;

		system("cls");

		cout << cCyan;
		ShowScreenHeader("Transactions Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		cout << cCyan
			<< setw(37) << left << "" << "===========================================\n"
			<< setw(37) << left << "" << "|             Transactions Menu           |\n"
			<< setw(37) << left << "" << "===========================================\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [1] Deposite.                        " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [2] Withdraw.                        " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [3] Total Balances.                  " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [4] Transfer.                        " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cGreen << "    [5] Transfer Log.                    " << cCyan << "|\n"
			<< setw(37) << left << "" << "|" << cRed << "    [6] Main Menu.                       " << cCyan << "|\n"
			<< setw(37) << left << "" << "===========================================\n\n"
			<< cReset;

		_PerfomTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
	}

	


};

