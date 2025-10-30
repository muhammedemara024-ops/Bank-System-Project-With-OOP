#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include<vector>
#include<fstream>

class clsCurrency
{
private:
	enum enMode {EmptyMode = 0 , UpdateMode = 1};
	enMode _Mode;
	string _CurrencyCode; 
	string _Country;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _ConvertLineToCurrencyObject(string Line , string Separater = "#//#")
	{
		vector<string> vData = clsString::Split(Line, Separater);
		return clsCurrency(enMode::UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
	}
	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency> vData;
		fstream File;
		File.open("Currencies.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vData.push_back(Currency);
			}
			File.close();
		}
		return vData;
	}
	string _ConvertCurrencyObjectToLine(clsCurrency Currency , string Separater = "#//#")
	{
		string stDataLine = "";
		stDataLine += Currency.Counrty() + Separater;
		stDataLine += Currency.CurrencyCode() + Separater;
		stDataLine += Currency.CurrencyName() + Separater;
		stDataLine += to_string( Currency.Rate()) ;
		return stDataLine;
	}
	void _SaveCurrencyDataToFile(vector<clsCurrency> vData)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);
		if (File.is_open())
		{
			string DataLine;
			for (clsCurrency& C : vData)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				File << DataLine << endl;
			}
			File.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency> vData = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : vData)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vData);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Counrty()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	 bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}


	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		vector<clsCurrency> vData = _LoadCurrencyDataFromFile();
		fstream File;
		File.open("Currencies.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					File.close();
					return Currency;
				}
			}
			File.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		vector<clsCurrency> vData = _LoadCurrencyDataFromFile();
		fstream File;
		File.open("Currencies.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString( Currency.Counrty()) == Country)
				{
					File.close();
					return Currency;
				}
			}
			File.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return float(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountToUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountToUSD  ;
		}

		return (AmountToUSD * Currency2.Rate());
	}
};

