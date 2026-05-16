#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << cYellow;
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}



public:

    static void UpdateCurrencyRate()
    {
        system("cls");

        cout << cCyan;
        ShowScreenHeader("Update Currency Rate Screen");

        cout << cCyan << "\n===================================================\n";

        string Code = "";
        cout << cYellow << "\n    Please Enter Currency Code: " << cReset;
        Code = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());

        clsCurrency Currency1 = clsCurrency::FindByCode(Code);

        if (!Currency1.IsEmpty())
        {
            cout << cCyan << "\n===================================================\n";
            cout << cGreen << "\n    [-] Currency Found Successfully!\n\n" << cReset;
            cout << cCyan << "----------------- Currency Details ----------------\n" << cWhite;
            _PrintCurrency(Currency1);
            cout << cCyan << "---------------------------------------------------\n\n" << cReset;

            char Answer = 'n';
            cout << cYellow << "    Are you sure you want to update the rate of this Currency? (y/n): " << cReset;
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                cout << cCyan << "\n===================================================\n";
                cout << cYellow << "    Update Currency Rate:\n";
                cout << cCyan << "---------------------------------------------------\n" << cReset;

                float NewRate = 0;
                cout << cYellow << "    Enter New Rate: " << cReset;
                cin >> NewRate;

                Currency1.UpdateRate(NewRate);

                cout << cCyan << "\n===================================================\n";
                cout << cGreen << "\n    [-] Currency Rate Updated Successfully!\n\n" << cReset;

                cout << cCyan << "-------------- Currency After Update --------------\n" << cWhite;
                _PrintCurrency(Currency1);
                cout << cCyan << "---------------------------------------------------\n\n" << cReset;
            }
            else
            {
                cout << cCyan << "\n===================================================\n";
                cout << cYellow << "\n    [!] Update Cancelled.\n\n" << cReset;
            }
        }
        else
        {
            cout << cCyan << "\n===================================================\n";
            cout << cRed << "\n    [!] Currency not found!\n\n" << cReset;
        }
    }


};

