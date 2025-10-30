#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"
class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool FaildLogin = false;
		string UserName, Password;
		short Count = 3;
		do
		{
			if (FaildLogin)
			{
				cout << "\nInvalidate User Name / Password!";
				cout << "\nYou have " << Count << " Trials to login\n";
			}
			cout << "\nEnter User Name ? ";
			cin >> UserName;
			cout << "\nEnter Password ? ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			FaildLogin = CurrentUser.IsEmpty();
			if (--Count == 0)
			{
				cout << "\nYou are locked after 3 falied trials \n";
				return false;
			}
			
		} while (FaildLogin);
		CurrentUser.RegisterLogIn();
         clsMainScreen::ShowMainManu();
		 return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}
};

