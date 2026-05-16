#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SrcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.DestBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }

public:

	static void ShowTransferLogScreen()
	{
		system("cls");

		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferRecord();

		string Title = "Transfer Log List Screen";
		string SubTitle = "    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		cout << cMagenta;
		ShowScreenHeader(Title);
		cout << cYellow << "\t" << SubTitle << "\n\n";

		cout << cMagenta << "________________________________________________________________________________________________\n\n";

		cout << cMagenta << "| " << cYellow << left << setw(20) << "Date/Time"
			<< cMagenta << "| " << cYellow << left << setw(8) << "s.Acct"
			<< cMagenta << "| " << cYellow << left << setw(8) << "d.Acct"
			<< cMagenta << "| " << cYellow << left << setw(8) << "Amount"
			<< cMagenta << "| " << cYellow << left << setw(10) << "s.Balance"
			<< cMagenta << "| " << cYellow << left << setw(10) << "d.Balance"
			<< cMagenta << "| " << cYellow << left << setw(8) << "User\n";

		cout << cMagenta << "________________________________________________________________________________________________\n\n";

		if (vTransferLogRecord.size() == 0)
		{
			cout << cRed << "\t\t\t\tNo Transfers Available In the System!\n";
		}
		else
		{
			cout << cWhite;
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{
				PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		}

		cout << cMagenta << "________________________________________________________________________________________________\n\n" << cReset;
	}

};

