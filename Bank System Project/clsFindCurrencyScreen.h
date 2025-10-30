#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
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
    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-) ";
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\nCurrency Not Found :-(";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        short Choose;
          cout << "\nFind By : [1] Code or [2] Country ? ";
          Choose = clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter Number Between 1 And 2 : ");
          
          if (Choose == 1)
          {
              string CurrencyCode;
              cout << "\nPlease Enter CurrencyCode : ";
              CurrencyCode = clsInputValidate::ReadString();
              clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
              _ShowResult(Currency);
          }
          else
          {
              string Country;
              cout << "\nPlease Enter Country Name : ";
              Country = clsInputValidate::ReadString();
              clsCurrency Currency = clsCurrency::FindByCountry(Country);
              _ShowResult(Currency);
          }
    }
};

