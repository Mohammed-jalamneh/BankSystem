#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << cWhite;
		cout << "| Country    : " << Currency.Country() << endl;
		cout << "| Code       : " << Currency.CurrencyCode() << endl;
		cout << "| Name       : " << Currency.CurrencyName() << endl;
		cout << "| Rate(1$)   : " << Currency.Rate() << endl;
	}

	static void _ConvertCurrencies(clsCurrency Currency1, clsCurrency Currency2, float AmountOfExchange)
	{
		float AmountInUSD = AmountOfExchange / Currency1.Rate();

		if (Currency2.CurrencyCode() == "USD")
		{
			cout << cGreen << "    [$] " << AmountOfExchange << " " << Currency1.CurrencyCode()
				<< " = " << AmountInUSD << " " << Currency2.CurrencyCode() << "\n\n" << cReset;
		}
		else
		{
			float ToAnotherCurrency = AmountInUSD * Currency2.Rate();

			cout << cGreen << "    [$] " << AmountOfExchange << " " << Currency1.CurrencyCode()
				<< " = " << ToAnotherCurrency << " " << Currency2.CurrencyCode() << "\n\n" << cReset;
		}
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			cout << cCyan;
			clsScreen::ShowScreenHeader("Currency Calculator Screen");

			cout << cCyan << "\n===================================================\n";

			cout << cYellow << "\n    Enter Currency1 Code: " << cReset;
			string Currency1Code = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());
			clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

			while (Currency1.IsEmpty())
			{
				cout << cRed << "    [!] Currency not found.\n" << cReset;
				cout << cYellow << "    Enter another Currency Code: " << cReset;
				Currency1Code = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());
				Currency1 = clsCurrency::FindByCode(Currency1Code);
			}

			cout << cYellow << "\n    Enter Currency2 Code: " << cReset;
			string Currency2Code = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());
			clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

			while (Currency2.IsEmpty())
			{
				cout << cRed << "    [!] Currency not found.\n" << cReset;
				cout << cYellow << "    Enter another Currency Code: " << cReset;
				Currency2Code = clsString::SwitchStatmentToUpper(clsInputValidate::ReadString());
				Currency2 = clsCurrency::FindByCode(Currency2Code);
			}

			cout << cYellow << "\n    Enter Amount to Exchange: " << cReset;
			float AmountOfExchange = 0.0;
			cin >> AmountOfExchange;

			cout << cCyan << "\n----------------- Convert From: -------------------\n" << cWhite;
			_PrintCurrency(Currency1);

			cout << cCyan << "------------------ Convert To: --------------------\n" << cWhite;
			_PrintCurrency(Currency2);
			cout << cCyan << "---------------------------------------------------\n\n" << cReset;

			_ConvertCurrencies(Currency1, Currency2, AmountOfExchange);

			cout << cCyan << "===================================================\n";
			cout << cYellow << "    Do you want to perform another calculation? (y/n): " << cReset;
			cin >> Continue;
		}
	}
};