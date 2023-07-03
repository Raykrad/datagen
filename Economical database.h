#include "stdafx.h"
#pragma once
#include <vector>
#include <string>
#include "windows.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
//ЗДЕСЬ БЫЛ ИЛЬЯ
using namespace std;

class EconomicalDate
{
    private:
	vector<EconomicalDate> EcoDate;
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

		void Show()
		{
			cout << "Revenue: " << revenue << endl;
			cout << "Expenses: " << expenses << endl;
			cout << "Profit: " << calculateNetProfit(revenue, expenses) << endl; // костыль который никто не заметит :3
			cout << "Assets: " << assets << endl;
			cout << "Liabilities: " << liabilities << endl;
		}
		
		double calculateNetProfit(double revenue, double expenses) // подсчёт чистой прибыли
		{
            return revenue - expenses;
        }

		void ShowEconomicalDate(vector<EconomicalDate>& EcoDate)
		{
			string cases;
			bool emergencyShutdown = false; // предохранитель
				if (EcoDate.size() >= 10000)
				{
					cout <<"\n This is going to be a VERY long time. Are you sure?(n/y)"<< endl;
					while (cin.get() != '\n');
					getline(cin, cases);
					if (cases == "n")
					 {
						 cout<<"Your computer say << Thank you :) >> "<<endl;
						 emergencyShutdown = true;
					 }
					 else if (cases == "y")
					 {
						 cout<<"Ah sir...";
						 cout<<"I warned you :(";
						 cout<<"Good luck!";
						 cout<<"\n (Press any symbol to continue)" <<endl;
						 cin.get();
						 emergencyShutdown = false;
					 }
					 else if ((cases != "n") && (cases != "y"))
					 {
						 cout<<"I will take that as a << no >>";
						 emergencyShutdown = true;
					 }
				}
			if (EcoDate.size() == 0) cout<<"\n Oh, there's nothing here!"<< endl;

			if (emergencyShutdown == false)
			{
				for (int i = 0; i<EcoDate.size();i++)
					{
						cout << endl;
						cout <<"#" << i << ". ";
						EcoDate[i].Show();
						cout << endl;
					}
			}
		}

		void EnterEconomicalDate(vector<EconomicalDate>& EcoDate) // ручной ввод финансовых данных
		{
			double rev;
			double exp;
			double prof;
			double ass;
			double liab;

			cout<<"Enter the revenue"<<endl;
			cin>>rev;
			cout<<"Enter the expenses"<<endl;
			cin>>exp;
			cout<<"Enter the assets"<<endl;
			cin>>ass;
			cout<<"Enter the liabilities"<<endl;
			cin>>liab;
			prof = calculateNetProfit(rev, exp);

			EcoDate.push_back(EconomicalDate(rev,exp,prof,ass,liab));
		}

		void EditEconomicalDate(vector<EconomicalDate>& EcoDate)
		{
			double newRev;
			double newExp;
			double newAss;
			double newLiab;
			int cases = 0;
			ShowEconomicalDate(EcoDate);
			cout<<"\n Enter the number of data you want to edit"<<endl;
			cin>>cases;

			if ((cases>= 0) && (cases < EcoDate.size()))
			{
				cout <<"\n Enter new revenue or 0 if you do not want to change it"<<endl;
				cin>>newRev;
				if (newRev != 0 ) EcoDate[cases].setRevenue(newRev);
				
				cout <<"\n Enter new expenses or 0 if you do not want to change it"<<endl;
				cin>>newExp;
				if (newExp != 0 ) EcoDate[cases].setExpenses(newExp);
				
				cout <<"\n Enter new assets or 0 if you do not want to change it"<<endl;
				cin>>newAss;
				if (newAss != 0 ) EcoDate[cases].setAssets(newAss);
				
				cout <<"\n Enter new liabilities or 0 if you do not want to change it"<<endl;
				cin>>newLiab;
				if (newLiab != 0 ) EcoDate[cases].setLiabilities(newLiab);
			}    else
        cout << "\n No data for editing was found!" << endl;
		}

		void DeleteEconomicalDate(vector<EconomicalDate>& EcoDate)
		{
			int cases;
			ShowEconomicalDate(EcoDate);
			cout<<"\n Enter the number of data you want to delete:"<<endl;
			cin>> cases;

			 if ((cases >= 0) && (cases < EcoDate.size())) 
			 {
				 EcoDate.erase(EcoDate.begin() + cases);
				 cout << "\n Data deleted successfully!"<< endl;
			 }
			else  cout << "\n Oops, no deletion data found!" << endl;
		}

				void FullGenerate(vector<EconomicalDate>& EcoDate) // функция генерирующая случайные значения всех параметров объекта базы данных
		{
			double rev;
			double exp;
			double prof;
			double ass;
			double liab;
			int n;
			cout<<"\n Enter the number of generated database objects:"<<endl;
			cin>>n;
			for (int i = 0; i < n ; i++ )
			{
            rev = generateRevenue();
            exp = generateExpenses();
            prof = calculateNetProfit(rev, exp);
            ass = generateAssets();
            liab = generateLiabilities();

			EcoDate.push_back(EconomicalDate(rev,exp,prof,ass,liab));
			}
			if (n <= 10)
			{
				cout<<"\n The generation was successful! It was easy."<<endl;
			}
			else if ((n > 10) && (n <= 100))
				{
					cout <<"\n The generation was successful! That's not fast."<< endl;
				}
				else if ((n == 1911) ||( n == 911))
					{
						cout <<"\n You made it!"<< endl;
					}
					else if ((n > 10) && (n <= 10000))
						{
							cout <<"\n It was hard... but we made it!"<< endl;
						}
							else if ( n > 10000)
								{
									cout <<"\n You better NOT call the <Show> function :/"<<endl;
								}
        }

    public:
		void EcoMenu()
		{
			int cases = 0;
			bool EcoCompleted = false;
        while (EcoCompleted != true)
        {
            cout<< "\n Select the item for further work:"<<endl;
            cout<< "\n 1) Output financial data"<<endl;
            cout<< "\n 2) Generate new data N times"<<endl;
            cout<< "\n 3) Generate new data manually"<<endl;
            cout<< "\n 4) Edit existing data"<<endl;
            cout<< "\n 5) Delete existing data"<<endl;
            cout<< "\n Please, enter number of your chose:"<<endl;
            cin >> cases;
            switch (cases)
            {
            case 1:
                ShowEconomicalDate(EcoDate);
                break;
            case 2:
                FullGenerate(EcoDate);
                break;
            case 3:
                EnterEconomicalDate(EcoDate);
                break;
            case 4:
                EditEconomicalDate(EcoDate);
                break;
            case 5:
                DeleteEconomicalDate(EcoDate);
                break;
            }
        }
		}
		
		~EconomicalDate(){}// деконструктор по умолчанию

        EconomicalDate()// конструктор по умолчанию
		{
			srand(time(NULL));
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

};
