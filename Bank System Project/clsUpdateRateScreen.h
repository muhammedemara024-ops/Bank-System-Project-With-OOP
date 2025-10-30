#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"

class clsUpdateRateScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "\nCurrency Card";
        cout << "\n______________________________";
        cout << "\nCountry  : " << Currency.Counrty();
        cout << "\nCode     : " << Currency.CurrencyCode();
        cout << "\nName     : " << Currency.CurrencyName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n______________________________";
    }

public:
    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\t  Update Rate Screen");
        string CurrencyCode ="";
        cout << "\nPlease Enter Currency Code : ";
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Not Found. Enter Another One : ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);
        char Answer = 'n';
        cout << "\nAre you sure you want to update the rate of this currency ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            float NewRate =0;
            cout << "\nUpdate Currency Rate";
            cout << "\n_______________________________";
            cout << "\nEnter New Rate : ";
            NewRate = clsInputValidate::ReadNumber<float>();
            Currency.UpdateRate(NewRate);
            _PrintCurrencyCard(Currency);
        }
     
    }
};

