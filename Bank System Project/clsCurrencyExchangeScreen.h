#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include<iomanip>
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrncyExchange
    {
        eListCurrency = 1 , eFindCurrency = 2 , eUpdateRate = 3
        , eCurrencyCalculator = 4 , eMainMenu = 5
    };

    static short _ReadCurrenciesMenuOption()
    {
        short Choose; 
        cout << setw(37) << left << "" << "Enter what do you want to do ? [1 to 5] ? ";
        Choose = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number Between 1 And 5");
        return Choose;
    }

    static void _ShowListCurrencyScreen()
    {
      //  cout << "Will be here...";
        clsListCurrenciesScreen::ShowClientListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        //cout << "Will be here...";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
       // cout << "Will be here...";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
       // cout << "Will be here...";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoToCurrencyExchangeMenu()
    {
        cout << "\n\nPress any Key To Go Back To Currencies Menu...";
        system("pause>0");
        ShowCuerrencyExchangeScreen();
    }
   static void _PerformCurrencyExchangeMenuOption(enCurrncyExchange Option)
    {
        switch (Option)
        {
        case enCurrncyExchange::eListCurrency:
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoToCurrencyExchangeMenu();
            break;
        }
        case enCurrncyExchange::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoToCurrencyExchangeMenu();
            break;
        }
        case enCurrncyExchange::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoToCurrencyExchangeMenu();
            break;
        }
        case enCurrncyExchange::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoToCurrencyExchangeMenu();
            break;
        }
        case enCurrncyExchange::eMainMenu:
        {

        }
        }
    }
public:
	static void ShowCuerrencyExchangeScreen()
	{
        
        system("cls");
        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        _DrawScreenHeader("\tCurrency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyExchangeMenuOption((enCurrncyExchange)_ReadCurrenciesMenuOption());

	}
};

