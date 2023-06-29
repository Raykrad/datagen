#include "stdafx.h"
#pragma once
#include<string>
#include <iostream>
#include <cstdlib>
using namespace std;

class EconomicalDate
{
    private:
        double revenue; // доход
        double expenses; // расходы
        double profit; // прибыль
        double assets; // активы
        double liabilities; // обязательсва/кредиты

		// функции в привате
		        
        double generateRevenue() // функция для генерации случайного значения дохода
		{
            return rand() % 10000000 + 100000; // случайное число от 100 000 до 10 100 000
        }
        
        double generateExpenses() // функция для генерации случайного значения расходов
		{
            return rand() % static_cast<int>(generateRevenue() * 0.8) + 1000; // случайное число от 1000 до 80% от дохода
        }
        
        double generateAssets() // функция для генерации случайного значения активов
		{
            return rand() % 100000000 + 500000; // случайное число от 500 000 до 100 500 000
        }
        
        double generateLiabilities() // функция для генерации случайного значения обязательств/кредитов
		{
            return rand() % static_cast<int>(generateAssets() * 0.5) + 50000; // случайное число от 50 000 до 50% от активов
        }
    public:
        EconomicalDate()// конструктор по умолчанию
		{
            revenue = 0.0;
            expenses = 0.0;
            profit = 0.0;
            assets = 0.0;
            liabilities = 0.0;
        }

		        
        EconomicalDate(double rev, double exp, double pro, double ass, double lia)// конструктор с параметрами
		{
            revenue = rev;
            expenses = exp;
            profit = pro;
            assets = ass;
            liabilities = lia;
        }

		// Гетеры / сетеры

		double getRevenue()
		{
            return revenue;
        }

        void setRevenue(double rev)
		{
            revenue = rev;
        }

        double getExpenses()
		{
            return expenses;
        }

        void setExpenses(double exp)
		{
            expenses = exp;
        }

        double getProfit()
		{
            return profit;
        }

        void setProfit(double pro)
		{
            profit = pro;
        }

        double getAssets()
		{
            return assets;
        }

        void setAssets(double ass)
		{
            assets = ass;
        }

        double getLiabilities()
		{
            return liabilities;
        }

        void setLiabilities(double lia)
		{
            liabilities = lia;
        }

		double calculateNetProfit() // подсчёт чистой прибыли
		{
            return revenue - expenses;
        }

        void FullRandomGenerate() {// функция генерирующая случайные значения всех параметров объекта базыданных
            revenue = generateRevenue();
            expenses = generateExpenses();
            profit = calculateNetProfit();
            assets = generateAssets();
            liabilities = generateLiabilities();
        }
}
