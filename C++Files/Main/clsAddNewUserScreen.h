#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "iomanip"
#include "clsUser.h"
#include <vector>

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

    static void _ReadNewUserInfo(clsUser& User)
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

    static void _PrintUserCard(clsUser User)
    {
        cout<<"First Name  :"<< User.FirstName << endl;
        cout<<"Last Name   :"<< User.LastName << endl;
        cout<<"Full Name   :"<< User.FullName() << endl;
        cout<<"Email       :"<< User.Email << endl;
        cout<<"Phone       :"<< User.Phone << endl;
        cout<<"User Name   :"<< User.UserName << endl;
        cout<<"Password    :"<< User.Password << endl;
        cout<<"Permissions :"<< User.Permissions << endl;
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

        cout << "\nShow Client list? y/n? ";
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

        cout << "Find Client? y/n? ";
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



public:

    static void AddNewUser()
    {
        system("cls");

        cout << cBlue;
        ShowScreenHeader("Add New User Screen");

        cout << cYellow;
        CurrentUserAndSystemDate();

        cout << cBlue << "\n===================================================\n";
        cout << cYellow << "\n    Enter User Name: " << cReset;
        string UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << cRed << "    User Name already exists.\n" << cReset;
            cout << cYellow << "    Enter another User Name: " << cReset;
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        cout << cBlue << "\n------------------ User Details -------------------\n" << cWhite;
        _ReadNewUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();

        cout << cBlue << "\n===================================================\n";

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << cGreen << "\n    User Added Successfully:\n\n" << cWhite;
            _PrintUserCard(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << cRed << "\n    Failed to add new user because the user object is empty!\n" << cReset;
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << cRed << "\n    Failed to add new user because the user name already exists!\n" << cReset;
            break;
        }
        }
        cout << endl << cReset;
    }


};

