#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<vector>

class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(32) << left << Currency.Counrty();
		cout << "| " << setw(10) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(12) << left << Currency.Rate();
		
	}
public:
	static void ShowClientListScreen()
	{
		
		vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
		string Title = "\t   Currencies List Screen";
		string SubTitle = "     (" + to_string(vCurrencys.size()) + ") Currency";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(32) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(12) << "Rate/(1$)";
		
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n\n";
		
		if (vCurrencys.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

			for (clsCurrency Currency : vCurrencys)
			{

				PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t____________________________________________________";
		cout << "________________________________________________\n";

	}

};

