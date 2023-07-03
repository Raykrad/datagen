#pragma once
#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>

#include <ctime>

using namespace std;

// Класс "География организаций"

class Geograf_organizations {

private:

    string A_STRANA; // СТРАНА!

    string A_GOROD; // ГОРОД!

    string A_ADRES; // АДРЕС

    int A_POCHTA; // ПОЧТА



public:
    // Конструктор по умолчанию

    Geograf_organizations() {

        this->A_STRANA = "";

        this->A_GOROD = "";

        this->A_ADRES = "";

        this->A_POCHTA = 0;

    }

    // Параметрический конструктор

    Geograf_organizations(string strana, string gorod, string adres, int pochta) {

        this->A_STRANA = strana;

        this->A_GOROD = gorod;

        this->A_ADRES = adres;

        this->A_POCHTA = pochta;

    }

    // Конструктор копирования

    Geograf_organizations(const Geograf_organizations& other) {

        this->A_STRANA = other.A_STRANA;

        this->A_GOROD = other.A_GOROD;

        this->A_ADRES = other.A_ADRES;

        this->A_POCHTA = other.A_POCHTA;

    }



    // Деструктор

    ~Geograf_organizations() {}

    // Методы set

    void setA_STRANA(string strana) {

        this->A_STRANA = strana;

    }

    void setA_GOROD(string gorod)
    {
        this->A_GOROD = gorod;
    }

    void setA_ADRES(string adres)
    {
        this->A_ADRES = adres;
    }

    void setA_POCHTA(int pochta) {

        this->A_POCHTA = pochta;

    }

    // Методы get

    string getA_STRANA() {

        return this->A_STRANA;

    }

    string getA_GOROD() {

        return this->A_GOROD;

    }

    string getA_ADRES() {

        return this->A_ADRES;

    }


    int getA_POCHTA() {

        return this->A_POCHTA;

    }



    // Метод show

    void show() {

        cout << "\nOrganization's country: " << this->A_STRANA << endl;

        cout << "Organization's city: " << this->A_GOROD << endl;

        cout << "Organization's address: " << this->A_ADRES << endl;

        cout << "Postal code: " << this->A_POCHTA << endl;

    }

};


/////////////////////////////////////// НОВАЯ ЧАСТЬ!!!
// Функция для добавления новой организации в массив

void addGeograf_organizations(vector<Geograf_organizations>& Geografies)
{

    string strana, gorod, adres;

    int pochta;

    // Получаем данные от пользователя

    cout << "Enter the organization's Country: ";

    cin.ignore();
    getline(cin, strana);


    cout << "Enter the organization's city: ";



    cin.ignore();
    getline(cin, gorod);


    cout << "Enter the organization's Address (Street_Number): ";

 
    cin.ignore();
    getline(cin, adres);


    cout << "Enter the zip code: ";


    cin >> pochta;

    // Создаем новый объект Geograf_organizations на основе введенных данных и добавляем его в массив

    Geografies.push_back(Geograf_organizations(strana, gorod, adres, pochta));

    cout << "The organization has been added successfully!" << endl;

}

// Функция для удаления организации из массива

void deleteGeograf_organizations(vector<Geograf_organizations>& Geografies) {

    int index;

    // Выводим список организаций

    for (int i = 0; i < Geografies.size(); i++)
    {

        cout << "#" << i << ". ";

        Geografies[i].show();

        cout << endl;

    }

    // Получаем номер организации, который нужно удалить

    cout << "Enter the number of the organization you want to delete: ";

    cin >> index;

    if (index >= 0 && index < Geografies.size())
    {

        Geografies.erase(Geografies.begin() + index);

        cout << "The organization has been successfully deleted!" << endl;

    }

    else
    {
        cout << "Invalid organization number!" << endl;
    }

}

// Функция для изменения свойства выбранной пользователем организации на новое значение

void editGeograf_organizations(vector<Geograf_organizations>& Geografies) {

    int index, property, newValue;
    string NewValueString;

    // Выводим список географических данных организаций

    for (int i = 0; i < Geografies.size(); i++) {

        cout << "#" << i << ". ";

        Geografies[i].show();

        cout << endl;

    }

    // Получаем номер организации, свойство которого нужно изменить, и какое свойство

    cout << "Enter the number of the organization whose parameters you want to change: ";

    cin >> index;

    if (index >= 0 && index < Geografies.size())
    {

        cout << "Select the property you want to change: " << endl;

        cout << "1 - Organization's country" << endl;

        cout << "2 - Organization's city" << endl;

        cout << "3 - Organization's address" << endl;

        cout << "4 - Postal code of the organization" << endl;

        cin >> property;

        switch (property) {

        case 1:

            cout << "Enter the new country of the organization: ";

            cin.ignore();
            getline(cin,NewValueString);

            Geografies[index].setA_STRANA(NewValueString);


            break;

        case 2:

            cout << "Enter the organization's new city: ";

            cin.ignore();
            getline(cin, NewValueString);

            Geografies[index].setA_GOROD(NewValueString);

            break;

        case 3:

            cout << "Enter the new address of the organization (street_number): ";

            cin.ignore();
            getline(cin, NewValueString);

            Geografies[index].setA_ADRES(NewValueString);

            break;

        case 4:

            cout << "Enter the zip code: ";

            cin >> newValue;

            Geografies[index].setA_POCHTA(newValue);

            break;

        default:

            cout << "Incorrect parameter selection!" << endl;

            break;

        }

        cout << "The parameter has been successfully changed!" << endl;

    }

    else {

        cout << "Invalid organization number!" << endl;

    }

}

// Основная функция программы


void runGeografy() {

    srand(time(0));

    vector<Geograf_organizations> Geografies;

    // ЗДЕСЬ МАССИВ СО ЗНАЧЕНИЯМИ, КОТОРЫЕ БУДУТ СЛУЧАЙНО ПРИСВАИВАТЬСЯ ДЛЯ ПЕРВЫХ ДРУХ ОРГАНИЗАЦИЙ И ГЕНЕРАЦИЯ ЧСЕЛ ДЛЯ ID

    const string countryes[10] = { "Russian Federation", "Germany", "France", "Poland", "Belarus", "Finland", "Denmark", "Italy", "China", "Japan"};
    const string cities[10] = { "Moscow", "Berlin", "Paris", "Krakow", "Minsk", "Helsinki", "Copenhagen", "Rome", "Nankin", "Tokio"};
    const string adress[10] = { "Lenin avenue 20", "Unter den Linden 19", "Champs - Elysees 66", "Ulica Puławska 30", "Independence Avenue 40", "Aleksanterinkatu 50", "Nyhavn 17", "Via del Corso 80", "Changanjie 1", "Ginza 7"};
    const int indexx[10] = { 666666, 123456, 126758, 838351, 146111, 198755, 375734, 5235123, 645375, 696722 };
    int randIndex = rand() % 10; // рандом индекс
    string SelectCountry = countryes[randIndex];
    string SelectCities = cities[randIndex];
    string SelectAdress = adress[randIndex];
    int Selectindexx = indexx[randIndex];

    // Создаем две организации со свойствами

    Geograf_organizations Geograf_organizations1(SelectCountry, SelectCities, SelectAdress, Selectindexx);

    int randIndex2 = rand() % 10; // рандом индекс заново, для второй организации
    while (randIndex2 == randIndex) {
        int randIndex2 = rand() % 10;
    }

    string SelectCountry2 = countryes[randIndex2];
    string SelectCities2 = cities[randIndex2];
    string SelectAdress2 = adress[randIndex2];
    int Selectindexx2 = indexx[randIndex2];

    Geograf_organizations Geograf_organizations2(SelectCountry2, SelectCities2, SelectAdress2, Selectindexx2);

    Geografies.push_back(Geograf_organizations1);

    Geografies.push_back(Geograf_organizations2);


    int choice;

    while (true) {

        // Выводим меню

        cout << endl << "1 - Display information about all geographical data of organizations" << endl;

        cout << "2 - Add an organization" << endl;

        cout << "3 - Delete an organization" << endl;

        cout << "4 - Change the geographical parameters of the organization" << endl;

        cout << "0 - Exit" << endl;

        cout << "Select an action: ";

        cin >> choice;

        cout << "\n";

        switch (choice) {

        case 1:

            // Выводим информацию обо всех географических данных организаций

            for (int i = 0; i < Geografies.size(); i++) {

                cout << "#" << i << ". ";

                Geografies[i].show();

                cout << endl;

            }

            break;

        case 2:

            // Добавляем новую организацию

            addGeograf_organizations(Geografies);

            break;

        case 3:

            // Удаляем организацию

            deleteGeograf_organizations(Geografies);

            break;

        case 4:

            // Изменяем свойства организации

            editGeograf_organizations(Geografies);

            break;

        case 0:

            // Выходим из программы

            return;

        default:

            cout << "Wrong choice of action!" << endl;

            break;

        }

    }

}
