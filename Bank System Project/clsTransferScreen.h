#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\nClient Card";
		cout << "\n_______________________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n_______________________________";
	}
	static string _ReadAccountNumberSource()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account number to transfer from : ";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Not found, Please Enter another one ? ";
			cin >> AccountNumber;
		}
		return AccountNumber;
	}
	static string _ReadAccountNumberDestination()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account number to transfer to : ";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Not found, Please Enter another one ? ";
			cin >> AccountNumber;
		}
		return AccountNumber;
	}
	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\nEnter transfer Amount ? ";
		cin >> Amount;
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the avaliable balance, Enter Another Amount ? ";
			cin >> Amount;
		}
		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t\tTransfer Screen");
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumberSource());
		_PrintClientInfo(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumberDestination());
		_PrintClientInfo(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\n Are you sure you want to perform this operation ? y/n ? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout <<"\nFailed Transfer\n";
			}
			_PrintClientInfo(SourceClient);
			_PrintClientInfo(DestinationClient);
		}
		else
		{
			cout << "\nCancelled Operation ";
		}
		

	}
};

