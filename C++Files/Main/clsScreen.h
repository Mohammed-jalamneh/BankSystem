#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsScreen
{

protected:

	static void ShowScreenHeader(string Title  )
	{
		cout << "\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\t\t\n";
		cout << "\t\t\t\t\t\t"<<Title<<"\t\t"<< endl;
		cout << "\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\t\t\n\n";
	}

    static void CurrentUserAndSystemDate()
    {
        cout << "\t\t\t\t\t\tUser: " << CurrentUser.UserName<< "\n";
        cout << "\t\t\t\t\t\tDate: ";
        CurrentDate.PrintDate();
        cout << "\n";

    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

