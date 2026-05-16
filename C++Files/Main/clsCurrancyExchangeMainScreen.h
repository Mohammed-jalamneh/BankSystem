#pragma once
#include <iostream>
#include "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "iomanip"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrancyExchangeMainScreen : protected clsScreen
{

private:

    enum enCurrancyExchangeOption
    {
        ListCurrancies =1 , FindCurrency , UpdateRate , CurrencyCalculator , MainMenue
    };


    static short _ReadMainCurranceOption()
    {
        short number;

        cout << cCyan << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]:- ";
        number = clsInputValidate::ReadIntNumberBetween(1,5);
        
        return number;
    }

    static void _GoBackToMainCurrancyMenue()
    {
        cout << "\n\nPress any key to go back to Currancy Exchange Menue...";
        system("pause>0");
        ShowCurrancyExchangeMainScreen();

    }

    static void _ListCurrancies()
    {
        system("cls");
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
        
    }

    static void _FindCurrency()
    {
        system("cls");
        clsFindCurrencyScreen::FindCurrancy();
    }

    static void _UpdateRate()
    {
        system("cls");
        clsUpdateCurrencyRateScreen::UpdateCurrencyRate();
    }

    static void _CurrencyCalculator()
    {
        system("cls");
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

   

    static void PerformMainCurrancyExchangeOption(enCurrancyExchangeOption CurrancyExchangeOption)
    {
        switch (CurrancyExchangeOption)
        {
        case enCurrancyExchangeOption::ListCurrancies:
        {
            system("cls");
            _ListCurrancies();
            _GoBackToMainCurrancyMenue();
            break;
        }

        case enCurrancyExchangeOption::FindCurrency:
        {
            system("cls");
            _FindCurrency();
            _GoBackToMainCurrancyMenue();
            break;
        }

        case enCurrancyExchangeOption::UpdateRate:
        {
            system("cls");
            _UpdateRate();
            _GoBackToMainCurrancyMenue();
            break;
        }

        case enCurrancyExchangeOption::CurrencyCalculator:
        {
            system("cls");
            _CurrencyCalculator();
            _GoBackToMainCurrancyMenue();
            break;
        }

        case enCurrancyExchangeOption::MainMenue:
        {
            break;
        }


        }



    }


public :

    static void ShowCurrancyExchangeMainScreen()
    {
        system("cls");

        cout << setfill(' ');

        cout << cCyan;
        ShowScreenHeader("Currency Exchange Main Screen");

        cout << cYellow;
        cout << setw(37) << left << "" << "User: " << CurrentUser.UserName << endl;
        cout << setw(37) << left << "" << "Date: " << CurrentDate.GetSystemDateTimeString() << endl << endl;

        cout << cCyan;
        cout << setw(37) << left << "" << "=================================================\n";
        cout << setw(37) << left << "" << "|            Currency Exchange Menue            |\n";
        cout << setw(37) << left << "" << "=================================================\n";

        cout << setw(37) << left << "" << "| " << cGreen << setw(46) << left << "    [1] List Currencies." << cCyan << "|\n";
        cout << setw(37) << left << "" << "| " << cGreen << setw(46) << left << "    [2] Find Currency." << cCyan << "|\n";
        cout << setw(37) << left << "" << "| " << cGreen << setw(46) << left << "    [3] Update Rate." << cCyan << "|\n";
        cout << setw(37) << left << "" << "| " << cGreen << setw(46) << left << "    [4] Currency Calculator." << cCyan << "|\n";
        cout << setw(37) << left << "" << "| " << cRed << setw(46) << left << "    [5] Main Menue." << cCyan << "|\n";

        cout << setw(37) << left << "" << "=================================================\n\n";

        
        cout << cReset;

        PerformMainCurrancyExchangeOption((enCurrancyExchangeOption)_ReadMainCurranceOption());
    }


};

