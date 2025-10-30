#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"Global.h"

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLog TranferLogData)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << TranferLogData.Date;
		cout << "| " << setw(8) << left << TranferLogData.SourceAccountNumber;
		cout << "| " << setw(8) << left << TranferLogData.DestinationAccountNumber;
		cout << "| " << setw(10) << left << TranferLogData.Amount;
		cout << "| " << setw(12) << left << TranferLogData.SourceBalance;
		cout << "| " << setw(12) << left << TranferLogData.DestinationBalance;
		cout << "| " << setw(10) << left << TranferLogData.UserName;

	}
public:
	static void ShowTransferLogScreen()
	{

		vector <clsBankClient::stTransferLog> vTransferLogData = clsBankClient::GetTransferLogList();
		string Title = "\t   Transfer Log List Screen";
		string SubTitle = "     (" + to_string(vTransferLogData.size()) + ") Record(s)";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n\n";
		if (vTransferLogData.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Tranfer Operation done in System";
		}
		else
		{
			for (clsBankClient::stTransferLog& C : vTransferLogData)
			{
				_PrintTransferLogRecordLine(C);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n";
	}
};

