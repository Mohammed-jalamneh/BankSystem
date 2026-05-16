#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

    using namespace std;
    class clsBankClient : public clsPerson
    {
    private:

        enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode =2 , DeleteMode =3 };
        enMode _Mode;
        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool _MarkForDeleted=false;

       


        static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
        {
            vector<string> vClientData;
            vClientData = clsString::Split(Line, Seperator);

            return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

        }
        struct stTransferLogRecord;

        static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
        {
            stTransferLogRecord TrnsferLogRecord;

            vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
            TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
            TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
            TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
            TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
            TrnsferLogRecord.SrcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
            TrnsferLogRecord.DestBalanceAfter = stod(vTrnsferLogRecordLine[5]);
            TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

            return TrnsferLogRecord;

        }

        static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
        {

            string stClientRecord = "";
            stClientRecord += Client.FirstName + Seperator;
            stClientRecord += Client.LastName + Seperator;
            stClientRecord += Client.Email + Seperator;
            stClientRecord += Client.Phone + Seperator;
            stClientRecord += Client.AccountNumber() + Seperator;
            stClientRecord += Client.PinCode + Seperator;
            stClientRecord += to_string(Client.AccountBalance);

            return stClientRecord;

        }

        static  vector <clsBankClient> _LoadClientsDataFromFile()
        {

            vector <clsBankClient> vClients;

            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {

                string Line;


                while (getline(MyFile, Line))
                {

                    clsBankClient Client = _ConvertLinetoClientObject(Line);

                    vClients.push_back(Client);
                }

                MyFile.close();

            }

            return vClients;

        }

        static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
        {

            fstream MyFile;
            MyFile.open("Clients.txt", ios::out);//overwrite

            string DataLine;

            if (MyFile.is_open())
            {

                for (clsBankClient C : vClients)
                {
                    if (C._MarkForDeleted == false)
                    {
                        DataLine = _ConverClientObjectToLine(C);
                        MyFile << DataLine << endl;
                    }
                }

                MyFile.close();

            }

        }

        void _Update()
        {
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();

            for (clsBankClient& C : _vClients)
            {
                if (C.AccountNumber() == AccountNumber())
                {
                    C = *this;
                    break;
                }

            }

            _SaveCleintsDataToFile(_vClients);

        }

        void _AddNew()
        {
            _AddDataLineToFile(_ConverClientObjectToLine(*this));
        }

        void _AddDataLineToFile(string  stDataLine)
        {
            fstream MyFile;
            MyFile.open("Clients.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

        static clsBankClient _GetEmptyClientObject()
        {
            return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
        }

        string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
            string UserName, string Seperator = "#//#")
        {
            string TransferLogRecord = "";
            TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
            TransferLogRecord += AccountNumber() + Seperator;
            TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
            TransferLogRecord += to_string(Amount) + Seperator;
            TransferLogRecord += to_string(AccountBalance) + Seperator;
            TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
            TransferLogRecord += UserName;
            return TransferLogRecord;
        }

        void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
        {

            string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

            fstream MyFile;
            MyFile.open("TransferLog.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

    public:


        clsBankClient(enMode Mode, string FirstName, string LastName,
            string Email, string Phone, string AccountNumber, string PinCode,
            float AccountBalance) :
            clsPerson(FirstName, LastName, Email, Phone)

        {
            _Mode = Mode;
            _AccountNumber = AccountNumber;
            _PinCode = PinCode;
            _AccountBalance = AccountBalance;

        }

        static struct stTransferLogRecord
        {
            string DateTime;
            string SourceAccountNumber;
            string DestinationAccountNumber;
            float Amount;
            float SrcBalanceAfter;
            float DestBalanceAfter;
            string UserName;
        };
       
        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }

        string AccountNumber()
        {
            return _AccountNumber;
        }

        void SetPinCode(string PinCode)
        {
            _PinCode = PinCode;
        }

        string GetPinCode()
        {
            return _PinCode;
        }
        __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

        void SetAccountBalance(float AccountBalance)
        {
            _AccountBalance = AccountBalance;
        }

        float GetAccountBalance()
        {
            return _AccountBalance;
        }
        __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
        
        static clsBankClient Find(string AccountNumber)
        {


            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }

            return _GetEmptyClientObject();
        }

        static clsBankClient Find(string AccountNumber, string PinCode)
        {

            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }
            return _GetEmptyClientObject();
        }

        enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1  , svFaildAccountNumberExists=2};

        void MarkClientForDelete()
        {
            vector <clsBankClient> vClients = _LoadClientsDataFromFile();

            for (clsBankClient& b : vClients)
            {
                if (b.AccountNumber() == _AccountNumber)
                {
                    b._MarkForDeleted = true;

                }
            }

            _SaveCleintsDataToFile(vClients);

            *this = _GetEmptyClientObject();

            return;

        }

        enSaveResults Save()
        {

            switch (_Mode)
            {
            case enMode::EmptyMode:
            {
                if (IsEmpty())
                {
                    return enSaveResults::svFaildEmptyObject;
                }

             }

            case enMode::UpdateMode:
            {
                _Update();

                return enSaveResults::svSucceeded;

                break;
            }
            case enMode::AddNewMode:
            {
                if (clsBankClient::IsClientExist(_AccountNumber))
                {
                    return enSaveResults::svFaildAccountNumberExists;
                }
                else
                {
                    _AddNew();

                   _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }

            } 

            }

        }

		

        static bool IsClientExist(string AccountNumber)
        {

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            return (!Client1.IsEmpty());
        }

        static clsBankClient GetAddNewClientObject(string AccountNumber)
        {

            return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);

        }

        static vector<clsBankClient> GetClientsList()
        {
            return _LoadClientsDataFromFile();
        }

        
        //Transaction Methods

        void Deposit(float Amount)
        {
            AccountBalance += Amount;
            Save();
        }

        bool Withdraw(float Amount)
        {

            if(Amount > AccountBalance)
            {
                cout << "\n";
                return 0;
            }

            AccountBalance -= Amount;
            Save();
            return 1;
		}

        static int TotalBalances()
        {
			vector <clsBankClient> vClients = _LoadClientsDataFromFile();

			int TotalBalances = 0;
            for (clsBankClient c : vClients )
            {
                TotalBalances += c.AccountBalance;
            }
            return TotalBalances;
        }
       
        bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
        {

            if (Amount > AccountBalance)
            {
                return false;
            }

            Withdraw(Amount);
            DestinationClient.Deposit(Amount);
            _RegisterTransferLog(Amount, DestinationClient, UserName);
            
            return true;
        }

        

        static vector <stTransferLogRecord> GetTransferRecord()
        {
            
            vector <stTransferLogRecord> vTransferLogRecord;

            fstream MyFile;
            MyFile.open("Transferlog.txt", ios::in);

            stTransferLogRecord TransferRecord;
            
            if (MyFile.is_open())
            {
                string Line;

                while (getline(MyFile, Line))
                {
                    TransferRecord=  _ConvertTransferLogLineToRecord(Line);
                    vTransferLogRecord.push_back(TransferRecord);
                }
                MyFile.close();
            }


            return vTransferLogRecord;
        }

        


    };



