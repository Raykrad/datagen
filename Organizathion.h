#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>

#include <ctime>

using namespace std;

// Класс "данные организаций"

class Organizations_database {

private:

    string A_NAME; // Название организации

    string A_EMAIL; // E-mail организации

    int A_ID; // ID организации

    string A_NUMBER; // Телефон организации



public:
    // Конструктор по умолчан

    Organizations_database() {

        this->A_NAME = "";

        this->A_EMAIL = "";

        this->A_ID = 0;

        this->A_NUMBER = "";

    }

    // Параметр конструктор

    Organizations_database(string name, string email, int id, string number) {

        this->A_NAME = name;

        this->A_EMAIL = email;

        this->A_ID = id;

        this->A_NUMBER = number;

    }

    // Конструктор копир

    Organizations_database(const Organizations_database& other) {

        this->A_NAME = other.A_NAME;

        this->A_EMAIL = other.A_EMAIL;

        this->A_ID = other.A_ID;

        this->A_NUMBER = other.A_NUMBER;

    }



    // Деструктор

    ~Organizations_database() {}

    // Методы set

    void setA_NAME(string name) {

        this->A_NAME = name;

    }

    void setA_EMAIL(string email)
    {
        this->A_EMAIL = email;
    }

    void setA_ID(int id)
    {
        this->A_ID = id;
    }

    void setA_NUMBER(string number) {

        this->A_NUMBER = number;

    }


    string getA_NAME() {

        return this->A_NAME;
    }

    string getA_EMAIL() {

        return this->A_EMAIL;

    }

    int getA_ID() {

        return this->A_ID;

    }

    string getA_NUMBER() {

        return this->A_NUMBER;

    }

    void show() {

        cout << " Organization's name: " << this->A_NAME << endl;

        cout << " Organization's e-mail: " << this->A_EMAIL << endl;

        cout << " Organization's id: " << this->A_ID << endl;

        cout << " Telephon number: " << this->A_NUMBER << endl;

    }

};

// Функция для добавления новой организации в массив

void addOrganizations_database(vector<Organizations_database>& Organizathions)
{

    string name, email, number;

    int id;

    // Получаем данные от пользователя

    cout << "Enter the organizathon's name: ";

    cin.ignore();
    getline(cin, name);

    cout << "Enter the organizathon's name email: ";

    cin.ignore();
    getline(cin, email);

    cout << "Enter the organization's id: ";

    cin >> id;

    cout << "Enter the organization's telephon number: ";

    cin.ignore();
    getline(cin, number);


    // Создаем новый объект Organizations_database на основе введенных данных и добавляем его в массив

    Organizathions.push_back(Organizations_database(name, email, id, number));

    cout << "The organization has been added successfully!" << endl;

}

// Функция для удаления организации из массива

void deleteOrganizations_database(vector<Organizations_database>& Organizathions) {

    int index;


    for (int i = 0; i < Organizathions.size(); i++)
    {

        cout << "#" << i << ". ";

        Organizathions[i].show();

        cout << endl;

    }

    cout << "Enter the number of the organization you want to delete: ";

    cin >> index;

    if (index >= 0 && index < Organizathions.size())
    {

        Organizathions.erase(Organizathions.begin() + index);

        cout << "The organization has been successfully deleted!" << endl;

    }

    else
    {
        cout << "Invalid organization number!" << endl;
    }

}

// Функция для изменения свойства выбранной пользователем организации на новое значение

void editOrganizations_database(vector<Organizations_database>& Organizathions) {

    int index, property, newValue;
    string NewValueString;


    for (int i = 0; i < Organizathions.size(); i++) {

        cout << "#" << i << ". ";

        Organizathions[i].show();

        cout << endl;

    }

    cout << "Enter the number of the organization whose parameters you want to change: ";

    cin >> index;

    if (index >= 0 && index < Organizathions.size())
    {

        cout << "Select the property you want to change: " << endl;

        cout << "1 - Organization's name" << endl;

        cout << "2 - Organization's email" << endl;

        cout << "3 - Organization's id" << endl;

        cout << "4 - Postal code of the organization telephon number" << endl;

        cin >> property;

        switch (property) {

        case 1:

            cout << "Enter the new name of the organization: ";

            cin.ignore();
            getline(cin, NewValueString);

            Organizathions[index].setA_NAME(NewValueString);


            break;

        case 2:

            cout << "Enter the organization's new email: ";

            cin.ignore();
            getline(cin, NewValueString);

            Organizathions[index].setA_EMAIL(NewValueString);

            break;

        case 3:

            cout << "Enter the new id of the organization: ";

            cin >> newValue;

            Organizathions[index].setA_ID(newValue);

            break;

        case 4:

            cout << "Enter the new telephon number: ";

            cin.ignore();
            getline(cin, NewValueString);

            Organizathions[index].setA_NUMBER(NewValueString);

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


void Organizathions() {

    srand(time(0));

    vector<Organizations_database> Organizathions;



    const string Names[5] = { "Rostec", "Yahoo", "Yandex", "Google", "OOO Chebyrek" };
    const string Emails[5] = { "Qwe@yandex.ru", "Org@mail.ru", "Company@rambler.ru", "Jojo@gmail.com", "serega@Microsoft.com" };
    const string numbers[5] = { "+7-(922)-555-1234", "+1-(231)-189-0643", "+5-(851)-755-7330", "+9-(326)-111-1114", "+6-(666)-666-6666" };

    int Selectid = rand() % 100000000 + 1;

    int randIndex = rand() % 5; 

    string SelectName = Names[randIndex];
    string SelectEmail = Emails[randIndex];
    string SelectNumbers = numbers[randIndex];

    // Создаем две организации со свойствами

    Organizations_database Organizations_database1(SelectName, SelectEmail, Selectid, SelectNumbers);

    int Selectid2 = rand() % 100000000 + 1;
    int randIndex2 = rand() % 5;
    while (randIndex2 == randIndex) {
        int randIndex2 = rand() % 5;
    }

    string SelectName2 = Names[randIndex2];
    string SelectEmail2 = Emails[randIndex2];
    string SelectNumbers2 = numbers[randIndex2];

    Organizations_database Organizations_database2(SelectName2, SelectEmail2, Selectid2, SelectNumbers2);

    Organizathions.push_back(Organizations_database1);

    Organizathions.push_back(Organizations_database2);


    int choice;

    while (true) {


        cout << endl << "1 - Display information about all data of organizations" << endl;

        cout << "2 - Add an organization" << endl;

        cout << "3 - Delete an organization" << endl;

        cout << "4 - Change the parameters of the organization" << endl;

        cout << "0 - Exit" << endl;

        cout << "Select an action: ";

        cin >> choice;

        cout << "\n";



        switch (choice) {

        case 1:



            for (int i = 0; i < Organizathions.size(); i++) {

                cout << "#" << i << ". ";

                Organizathions[i].show();

                cout << endl;

            }

            break;

        case 2:



            addOrganizations_database(Organizathions);

            break;

        case 3:


            deleteOrganizations_database(Organizathions);

            break;

        case 4:


            editOrganizations_database(Organizathions);

            break;

        case 0:


            return;

        default:

            cout << "Wrong choice of action!" << endl;

            break;

        }

    }

}
