#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include"clsTransactionsMenuScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eShowClientList = 1 , eAddNewClient = 2 , eDeleteClient = 3
        , eUpdateClient = 4 , eFindClient = 5 , eShowTransactoinScreen = 6
        , eManageUsers = 7 , eLoginRegister = 8 , eCurrencyExchange = 9 ,eLogOut = 10
    };
    static short _ReadMainMenueOption()
    {
        short Choose;
        cout << setw(37) << left << "" << "Enter What to do you want to do ? [1 to 10] ? ";
        Choose = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number Between 1 And 10");
        return Choose;
    }

    static void _ShoweClientsListScreen()
    {
      //  cout << "\nClient List will be here...";
        clsClientListScreen::ShowClientListScreen();
    }

    static void _ShoweAddNewClientScreen()
    {
       // cout << "\nAdd New Client will be here...";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _ShoweDeleteClientScreen()
    {
       // cout << "\nClient will be here...";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static  void _ShoweUpdateClientScreen()
    {
      //  cout << "\nClient List will be here...";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }
    static void _ShoweFindClientScreen()
    {
      //  cout << "\nClient List will be here...";
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShoweTransactoinScreen()
    {
      //  cout << "\nClient List will be here...";
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShoweManageUsersScreen()
    {
      //  cout << "\nClient List will be here...";
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    static void _ShowLogoutScreen()
    {
      //  cout << "\nProgram End";
        CurrentUser = clsUser::Find("", "");
    }
    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCuerrencyExchangeScreen();
    }
   
    static  void _GoToMainMenuScreen()
    {
        cout << "\n\n\t\t Press any key to go back to Mian Menu";
        system("pause>0");
        ShowMainManu();
    }
  static  void _PerfromMainMenueOption(enMainMenueOptions Option)
    {
        switch (Option)
        {
        case enMainMenueOptions::eShowClientList:
        {
            system("cls");
            _ShoweClientsListScreen();
            _GoToMainMenuScreen();
                break;
        }
        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShoweAddNewClientScreen();
            _GoToMainMenuScreen();
                break;
        }
        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShoweDeleteClientScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eUpdateClient:
        {
            system("cls");
            _ShoweUpdateClientScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eFindClient:
        {
            system("cls");
            _ShoweFindClientScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eShowTransactoinScreen:
        {
            system("cls");
            _ShoweTransactoinScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eManageUsers:
        {
            system("cls");
            _ShoweManageUsersScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eCurrencyExchange:
        {
            _ShowCurrencyExchangeScreen();
            _GoToMainMenuScreen();
            break;
        }
        case enMainMenueOptions::eLogOut:
        {
            system("cls");
            _ShowLogoutScreen();
            break;
        }
        }

    }
public:
	static void ShowMainManu()
	{
        system("cls");
		clsScreen::_DrawScreenHeader("\t\tMain Screen");
       
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());


	}
};

