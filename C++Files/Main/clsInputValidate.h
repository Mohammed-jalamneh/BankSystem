#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class clsInputValidate
{
public:

    //  Validation Methods

    static bool IsNumberBetween(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From && Number <= To);
    }

    template <typename T> static bool IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }

    // Reading Numbers with Type Validation 

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again: ")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << ErrorMessage;
        }
        return Number;
    }

    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again: ")
    {
        float Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again: ")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    template <typename T> static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again: ")
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    // Reading Numbers within a Specific Range 

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again: ")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again: ")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    template <typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again: ")
    {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    // Reading Strings 

    static string ReadString()
    {
        string S1;
        // ws extracts whitespace characters from the input stream before reading the string
        getline(cin >> ws, S1);
        return S1;
    }
};