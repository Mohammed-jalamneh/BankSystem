#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private:


    static string _NumberToText(int UserNumber)
    {

        if (UserNumber == 0)
            return "";


        string Arr1[] = { "" ,"One" ,"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Elaven","Twelve"
                ,"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

        if (UserNumber > 0 && UserNumber <= 19)
        {
            return Arr1[UserNumber] + " ";
        }

        if (UserNumber >= 20 && UserNumber <= 99)
        {
            string Arr2[] = { "" ,"" ,"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return Arr2[UserNumber / 10] + "-" + _NumberToText(UserNumber % 10);
        }

        if (UserNumber >= 100 && UserNumber <= 199)
        {
            return "One Hundred" + _NumberToText(UserNumber % 100);
        }

        if (UserNumber >= 200 && UserNumber <= 999)
        {
            return  _NumberToText(UserNumber / 100) + "Hundreds " + _NumberToText(UserNumber % 100);
        }

        if (UserNumber >= 1000 && UserNumber <= 1999)
        {
            return "One Thousand " + _NumberToText(UserNumber % 1000);
        }

        if (UserNumber >= 2000 && UserNumber <= 999999)
        {
            return  _NumberToText(UserNumber / 1000) + "Thousand " + _NumberToText(UserNumber % 1000);
        }

        if (UserNumber >= 1000000 && UserNumber <= 1999999)
        {
            return  "One Million " + _NumberToText(UserNumber % 1000000);
        }

        if (UserNumber >= 2000000 && UserNumber <= 999999999)
        {
            return  _NumberToText(UserNumber / 1000000) + "Billions " + _NumberToText(UserNumber % 1000000);
        }

        return "";


    }

	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

	static string _ReadAccountNumber()
	{
		cout << "\nEnter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}


public:

	static void TotalBalances()
	{
		system("cls");

		cout << cMagenta;
		ShowScreenHeader("Total Balances Screen");

		cout << cYellow;
		CurrentUserAndSystemDate();

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		cout << cMagenta << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client(s).\n";
		cout << "________________________________________________________________________________________________\n\n";

		cout << cMagenta << "| " << cYellow << left << setw(15) << "Account Number"
			<< cMagenta << "| " << cYellow << left << setw(20) << "Client Name"
			<< cMagenta << "| " << cYellow << left << setw(12) << "Balance\n";

		cout << cMagenta << "________________________________________________________________________________________________\n\n";

		if (vClients.size() == 0)
		{
			cout << cRed << "\t\t\t\tNo Clients Available In the System!\n";
		}
		else
		{
			cout << cWhite;
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}

		cout << cMagenta << "________________________________________________________________________________________________\n\n";

		int TotalBalance = clsBankClient::TotalBalances();

		cout << cGreen << "\t\t\t\tTotal Balances = " << TotalBalance << " JD.\n";
		cout << "\t\t\t\t( " << _NumberToText(TotalBalance) << " )\n\n" << cReset;
	}



};

