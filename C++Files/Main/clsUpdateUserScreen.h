#pragma once
#include <iostream>
#include <vector>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

private:

    static void _PrintUserCard(clsUser User)
    {
        cout << "First Name  :" << User.FirstName << endl;
        cout << "Last Name   :" << User.LastName << endl;
        cout << "Full Name   :" << User.FullName() << endl;
        cout << "Email       :" << User.Email << endl;
        cout << "Phone       :" << User.Phone << endl;
        cout << "User Name   :" << User.UserName << endl;
        cout << "Password    :" << User.Password << endl;
        cout << "Permissions :" << User.Permissions << endl;
    }

    int static _ReadPermisions()
    {
        int Permissions = 0;
        char Answer;


        cout << "\nDo you want to give this user full access? (y/n)? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n";

        cout << "\nShow User list? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pListClients;

        cout << "Add new client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pAddNewClient;

        cout << "Delete client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pDeleteClient;

        cout << "Update client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pUpdateClient;

        cout << "Find User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pFindClient;

        cout << "Transactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pTransactions;

        cout << "Manage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pManageUsers;

        cout << "Login Register List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += clsUser::pLoginRegister;

        return Permissions;
    }


    static void _ReadUpdatedUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();


        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermisions();

    }


public:


    static void ShowUpdateUserScreen()
    {
        system("cls");

        cout << cBlue;
        ShowScreenHeader("Update User Screen");

        cout << cYellow;
        CurrentUserAndSystemDate();

        cout << cBlue << "\n===================================================\n";
        cout << cYellow << "\n    Enter User Name: " << cReset;
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << cRed << "    User Name is not found.\n" << cReset;
            cout << cYellow << "    Choose another one: " << cReset;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        cout << cBlue << "\n----------------- Current Details -----------------\n" << cWhite;
        _PrintUserCard(User1);
        cout << cBlue << "---------------------------------------------------\n\n" << cReset;

        char Answer = 'n';
        cout << cYellow << "    Are you sure you want to update this User? (y/n): " << cReset;
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << cBlue << "\n===================================================\n";
            cout << cYellow << "    Update User Info:\n";
            cout << cBlue << "---------------------------------------------------\n" << cWhite;

            _ReadUpdatedUserInfo(User1);

            clsUser::enSaveResults SaveResult;
            SaveResult = User1.Save();

            cout << cBlue << "\n===================================================\n";

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << cGreen << "\n    User's Info Updated Successfully :-)\n\n" << cWhite;
                _PrintUserCard(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << cRed << "\n    Error account was not saved because it's Empty.\n" << cReset;
                break;
            }
            }
        }
        else
        {
            cout << cBlue << "\n===================================================\n";
            cout << cYellow << "\n    Update Cancelled.\n\n" << cReset;
        }
    }
};

