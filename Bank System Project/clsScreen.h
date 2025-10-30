#pragma once
#include<iostream>
#include"Global.h"
#include"clsUser.h"
using namespace std;

class clsScreen 
{
protected:
	static void _DrawScreenHeader(string Title , string SubTitle = "")
	{
		cout << "\n\t\t\t\t_____________________________________________________";
		cout << "\n\n\t\t\t\t\t" << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t_____________________________________________________\n";
		cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName;
		clsDate Date;
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << "\n\n";
		
	}
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________________________";
			cout << "\n\n\t\t\t\t\t\t Access Denies ! Contact Your Admin ";
			cout << "\n\t\t\t\t\t______________________________________________________";
			return false;
		}
		else
			return true;
	}
};

