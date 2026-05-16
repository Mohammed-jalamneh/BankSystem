#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen :protected clsScreen
{

private:
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }

public:


    static void ShowCurrenciesListScreen()
    {
        system("cls");

        vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();

        string Title = "Currencies List Screen";
        string SubTitle = "    (" + to_string(vCurrencys.size()) + ") Currency.";

        cout << cCyan;
        ShowScreenHeader(Title);

        cout << cYellow << "\t\t\t\t" << SubTitle << "\n\n";

        cout << cCyan << "________________________________________________________________________________________________________\n\n";

        cout << cCyan << "| " << cYellow << left << setw(30) << "Country"
            << cCyan << "| " << cYellow << left << setw(10) << "Code"
            << cCyan << "| " << cYellow << left << setw(40) << "Name"
            << cCyan << "| " << cYellow << left << setw(15) << "Rate/(1$)\n";

        cout << cCyan << "________________________________________________________________________________________________________\n\n";

        if (vCurrencys.size() == 0)
        {
            cout << cRed << "\t\t\t\tNo Currencies Available In the System!\n";
        }
        else
        {
            cout << cWhite;
            for (clsCurrency Currency : vCurrencys)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }

        cout << cCyan << "________________________________________________________________________________________________________\n\n" << cReset;
    }

};

