#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) <<left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(22) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public:
	static void ShowClientListScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t   Clients List Screen";
		string SubTitle = "     (" + to_string(vClients.size()) + ") Client(s)";
	
		clsScreen::_DrawScreenHeader(Title, SubTitle);
	cout <<setw(8) << left << ""<< "\n\t____________________________________________________";
	cout << "________________________________________________\n\n";
	cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(22) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << setw(8) << left << "" << "\n\t____________________________________________________";
	cout << "________________________________________________\n\n";
	if (vClients.size() == 0)
	{
		cout << "\n\t\t\t\t\tNo Clients Available in System";
	}
	else
	{
		for (clsBankClient& C : vClients)
		{
			_PrintClientRecordLine(C);
			cout << endl;
		}
	}
	cout << setw(8) << left << "" << "\n\t____________________________________________________";
	cout << "________________________________________________\n";

}

};

