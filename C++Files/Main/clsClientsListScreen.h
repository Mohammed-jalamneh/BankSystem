#pragma once
#include<iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"
using namespace std;


class clsClientsListScreen:clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(25) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(25) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }



public:
    
	static void ShowClientsList()
	{
		// 1. Security Check
		if (!CheckAccessRights(clsUser::enPermissions::pListClients)) return;

		system("cls"); // Always good practice to clear before drawing a big table

		// 2. Main Headers
		cout << cCyan;
		clsScreen::ShowScreenHeader("Clients List Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		cout << cCyan << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
		cout << "____________________________________________________________________________________________________________\n" << endl;

		cout << cCyan << "| " << cYellow << left << setw(15) << "Account Number"
			<< cCyan << "| " << cYellow << left << setw(25) << "Client Name"
			<< cCyan << "| " << cYellow << left << setw(12) << "Phone"
			<< cCyan << "| " << cYellow << left << setw(25) << "Email"
			<< cCyan << "| " << cYellow << left << setw(10) << "Pin Code"
			<< cCyan << "| " << cYellow << left << setw(12) << "Balance\n";

		cout << cCyan << "_______________________________________________________________________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << cRed << "\t\t\t\tNo Clients Available In the System!\n";
		}
		else
		{
			cout << cGreen;
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << cCyan << "____________________________________________________________________________________________________________\n\n";
		cout << cReset;
	}


};

