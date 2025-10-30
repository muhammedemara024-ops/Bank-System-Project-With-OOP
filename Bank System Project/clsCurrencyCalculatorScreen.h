#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private :
    static void _PrintCurrencyCard(clsCurrency Currency , string Title ="\nCurrency Card")
    {
        cout << Title;
        cout << "\n______________________________";
        cout << "\nCountry  : " << Currency.Counrty();
        cout << "\nCode     : " << Currency.CurrencyCode();
        cout << "\nName     : " << Currency.CurrencyName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n______________________________\n";
    }
    
    static clsCurrency _FindCurrency(string stCurrency)
    {
        string CurrencyCode;
        cout << "\nPlease Enter "<< stCurrency <<" Code : ";
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Not Found, Enter Another One : ";
           
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }
    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrencyCard(Currency1 , "\nConvert From");
        float AmountInUSD =  Currency1.ConvertToUSD(Amount) ;
        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";
        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }
        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }
public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Answer = 'n';
        do
        {
            system("cls");
            _DrawScreenHeader("\tCurrency Calculator Screen");
            
            clsCurrency CurrencyFrom = _FindCurrency("Corrency1");
            clsCurrency  CurrencyTo = _FindCurrency("Corrency2");

            float Amount = 0;
            cout << "\n\nEnter Amount To Exchange : ";
            Amount = clsInputValidate::ReadNumber<float>();
            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);
            cout << "\n\nDo you want to perform another calculation ? y/n ? ";
            cin >> Answer;
        } while (Answer == 'y' || Answer == 'Y');
    }
};

