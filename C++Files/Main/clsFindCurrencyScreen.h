#pragma once
#include <iostream>
#include "clsString.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrancyExchangeMainScreen.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindBy
	{
		Code =1 , Country=2
	};

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

    static void FindCurrancy()
    {
        system("cls");

        cout << cCyan;
        ShowScreenHeader("Find Currency Screen");

        unsigned short FindBy = 0;

        cout << cCyan << "\n===================================================\n";
        cout << cYellow << "\n    Find By: [1] Code or [2] Country? " << cReset;
        FindBy = clsInputValidate::ReadIntNumberBetween(1, 2);

        if (FindBy == enFindBy::Code)
        {
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
            }
            else
            {
                cout << cCyan << "\n===================================================\n";
                cout << cRed << "\n    [!] Currency not found (Using Code Search)!\n\n" << cReset;
            }
        }
        else if (FindBy == enFindBy::Country)
        {
            string Country = "";
            cout << cYellow << "\n    Please Enter Country Name: " << cReset;
            Country = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());

            clsCurrency Currency2 = clsCurrency::FindByCountry(Country);

            if (!Currency2.IsEmpty())
            {
                cout << cCyan << "\n===================================================\n";
                cout << cGreen << "\n    [-] Currency Found Successfully!\n\n" << cReset;
                cout << cCyan << "----------------- Currency Details ----------------\n" << cWhite;
                _PrintCurrency(Currency2);
                cout << cCyan << "---------------------------------------------------\n\n" << cReset;
            }
            else
            {
                cout << cCyan << "\n===================================================\n";
                cout << cRed << "\n    [!] Currency not found (Using Country Search)!\n\n" << cReset;
            }
        }
    }
		



};

