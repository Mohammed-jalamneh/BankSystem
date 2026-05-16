#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"
#include "clsUtil.h"
#include <fstream>
#include <vector>
#include "clsLoginRegister.h"

using namespace std;

class clsLoginRegister
{
private:

    string _Date;
    string  _UserName;
    string _Password;
    int _Permission;

    static string _ConvertCurrentUserRegisterObjectToLine(string Seperator = "#//#")
    {
        string UserRecord = "";

        UserRecord += clsDate::GetSystemDateTimeString() + Seperator;

        UserRecord += CurrentUser.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(CurrentUser.Password  , 2) + Seperator;
        UserRecord += to_string(CurrentUser.Permissions);

        return UserRecord;
    }

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static clsLoginRegister _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsLoginRegister( vUserData[0], vUserData[1], clsUtil::DecryptText(vUserData[2] , 2),
             stoi(vUserData[3]));   // UserRegisterData (date\time  , username , password ,  permission)

    }


    static  vector <clsLoginRegister> _LoadUsersRegisterDataFromFile()
    {

        vector <clsLoginRegister> vUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsLoginRegister User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }


public:

    clsLoginRegister(string Date, string UserName, string Password, int Permission)
    {
        _Date = Date;
        _UserName = UserName;
        _Password = Password;
        _Permission = Permission;
    }

     string GetDate()
    {
        return _Date;
    }

    string GetUserName()
    {
        return _UserName;
    }

    string GetPassword()
    {
        return _Password;

    }

    int GetPermission()
    {
        return _Permission;
    }



    static void AddRegisteredUserToFile()
    {
        _AddDataLineToFile(_ConvertCurrentUserRegisterObjectToLine());
    }

    static vector <clsLoginRegister> GetUsersRegisterList()
    {
        return _LoadUsersRegisterDataFromFile();
    }
};