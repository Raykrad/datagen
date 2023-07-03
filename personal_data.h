#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>


using namespace std;

// Класс "персональные данные"

class Personal_information {

private:

    string A_NAME; //ИМЯ

    string A_SURNAME; // ФАМИЛИЯ

    string A_STRANA; // СТРАНА!

    string A_GOROD; // ГОРОД!

    string A_ADRES; // АДРЕС

    int A_MAIL; // ПОЧТА

    string A_EMAIL; // ЕЛЕКТРОННАЯ ПОЧТА

    int A_PHONE_NUMBER; // НОМЕР ТЕЛЕФОНА



public:
    // Конструктор по умолчанию

    Personal_information() {

        this->A_NAME = "";

        this->A_SURNAME = "";

        this->A_STRANA = "";

        this->A_GOROD = "";

        this->A_ADRES = "";

        this->A_MAIL = 0;

        this->A_EMAIL = "";

        this->A_PHONE_NUMBER = 0;


    }

    // Параметры

    Personal_information(string name,string surname, string strana, string gorod, string adres, int mail, string email, int phone_number) {


        this->A_NAME = name;

        this->A_SURNAME = surname;

        this->A_STRANA = strana;

        this->A_GOROD = gorod;

        this->A_ADRES = adres;

        this->A_MAIL = mail;

        this->A_EMAIL = email;

        this->A_PHONE_NUMBER = phone_number;

    }

    // Конструктор копирования

    Personal_information(const Personal_information& other) {

        this->A_NAME = other.A_NAME;

        this->A_SURNAME = other.A_SURNAME;

        this->A_STRANA = other.A_STRANA;

        this->A_GOROD = other.A_GOROD;

        this->A_ADRES = other.A_ADRES;

        this->A_MAIL = other.A_MAIL;

        this->A_EMAIL = other.A_EMAIL;

        this->A_PHONE_NUMBER = other.A_PHONE_NUMBER;

    }



    // Деструктор

    ~Personal_information() {}

    // Методы set

    void setA_NAME(string name){
        this->A_NAME = name;
    }

    void setA_SURNAME(string surname){
        this->A_SURNAME = surname;
    }

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

    void setA_MAIL(int mail) {

        this->A_MAIL = mail;

    }

    void setA_EMAIL(string email){
        this->A_EMAIL = email;
    }

    void setA_PHONE_NUMBER(int phone_number){
        this->A_PHONE_NUMBER = phone_number;
    }



    // Методы get


    string getA_NAME() {
        return this->A_NAME;
    }
    
    string getA_SURNAME() {
        return this->A_SURNAME;
    }
    
    string getA_STRANA() {

        return this->A_STRANA;

    }

    string getA_GOROD() {

        return this->A_GOROD;

    }

    string getA_ADRES() {

        return this->A_ADRES;

    }


    int getA_MAIL() {

        return this->A_MAIL;

    }

    string getA_EMAIL() {
        return this->A_EMAIL;
    }

    int getA_PHONE_NUMBER() {
        return this->A_PHONE_NUMBER;
    }



    // Метод show

    void show() {

        cout << "Name: " << this->A_NAME << endl;

        cout << "Surname: " << this->A_SURNAME << endl;

        cout << "Country: " << this->A_STRANA << endl;

        cout << "City: " << this->A_GOROD << endl;

        cout << "address: " << this->A_ADRES << endl;

        cout << "Postal code: " << this->A_MAIL << endl;

        cout << "Email: " << this->A_EMAIL << endl;

        cout << "Phone number: " << this->A_PHONE_NUMBER << endl;  

    }

};



// Функция для добавления нового человека в массив

void addPersonal_information(vector<Personal_information>& Personal_data)
{

    string name, surname, strana, gorod, adres, email;

    int mail;
    int phone_number;

    //Получаем имя от пользователя
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, name);

    // Получаем фамилию от пользователя

    cout << "Enter the surname: ";
    cin.ignore();
    getline(cin, surname);



    cout << "Enter  Country: ";
    cin.ignore();
    getline(cin, strana);


    cout << "Enter  city: ";
    cin.ignore();
    getline(cin, gorod);


    cout << "Enter  Address (Street_Number): ";
    cin.ignore();
    getline(cin, adres);

    cout << "Enter the zip code: ";
    cin >> mail;

    cout << "Enter the email: ";
    cin.ignore();
    getline(cin, email);

    cout << "Enter  phone number: ";
    cin >> phone_number;





    // Создаем новый объект Personal_information на основе введенных данных и добавляем его в массив

    Personal_data.push_back(Personal_information(name, surname, strana, gorod, adres, mail, email, phone_number));

    cout << "The personal information has been added successfully!" << endl;

}

// Функция для удаления личных данных из массива

void deletePersonal_information(vector<Personal_information>& Personal_data) {

    int index;

    // Выводим список людей

    for (int i = 0; i < Personal_data.size(); i++)
    {

        cout << "#" << i << ". ";

        Personal_data[i].show();

        cout << endl;

    }

    // Получаем номер человека, которого нужно удалить

    cout << "Enter the number of the person you want to delete: ";

    cin >> index;

    if (index >= 0 && index < Personal_data.size())
    {

        Personal_data.erase(Personal_data.begin() + index);

        cout << "The person has been successfully deleted!" << endl;

    }

    else
    {
        cout << "Invalid person number!" << endl;
    }

}



// Функция для изменения данных выбраного пользователем человека 

void editPersonal_information(vector<Personal_information>& Personal_data) {

    int index, property, newValue;
    string NewValueString;

    // Выводим список персональных данных человека

    for (int i = 0; i < Personal_data.size(); i++) {

        cout << "#" << i << ". ";

        Personal_data[i].show();

        cout << endl;

    }

    // Получаем номер человека, личные данные которого нужно изменить

    cout << "Enter the number of the person whose parameters you want to change: ";

    cin >> index;

    if (index >= 0 && index < Personal_data.size())
    {

        cout << "Select the property you want to change: " << endl;

        cout << "1 - person's name" << endl;

        cout << "2 - person's surname" << endl;

        cout << "3 - person's country" << endl;

        cout << "4 - person's city" << endl;

        cout << "5 - person's address" << endl;

        cout << "6 - Postal code of the person" << endl;

        cout << "7 - person's email" << endl;

        cout << "8 - person's phone number" << endl;

        cin >> property;

        switch (property) {

        case 1:
            cout << "Enter the new name of the person: ";
            cin >> NewValueString;
            Personal_data[index].setA_NAME(NewValueString);
            break;

        case 2:
            cout << "Enter the new surname of the person: ";
           cin >> NewValueString;
           Personal_data[index].setA_SURNAME(NewValueString);
           break;

        case 3:

            cout << "Enter the new country of the person: ";

            cin >> NewValueString;

            Personal_data[index].setA_STRANA(NewValueString);


            break;

        case 4:

            cout << "Enter  new city: ";

            cin >> NewValueString;

            Personal_data[index].setA_GOROD(NewValueString);

            break;

        case 5:

            cout << "Enter the new address of the person (street_number): ";

            cin >> NewValueString;

            Personal_data[index].setA_ADRES(NewValueString);

            break;

        case 6:

            cout << "Enter the zip code: ";

            cin >> newValue;


            Personal_data[index].setA_MAIL(newValue);

            break;

        case 7:
            cout << "Enter the new email of the person: ";
            cin >> NewValueString;
            Personal_data[index].setA_EMAIL(NewValueString);
            break;

        case 8:
            cout << "Enter the new phone number of the person: ";
            cin >> newValue;
            Personal_data[index].setA_PHONE_NUMBER(newValue);
            break;
       
        default:

            cout << "Incorrect parameter selection!" << endl;

            break;

        }

        cout << "The parameter has been successfully changed!" << endl;

    }

    else {

        cout << "Invalid person number!" << endl;

    }

}

// Основная функция программы


void runPersonal() {

    setlocale(LC_ALL, "Russian");

    vector<Personal_information> Personal_data;


    // ЗДЕСЬ МАССИВ С ИМЕНАМИ, ФАМИЛИЯМИ, СТРАНАМИ, ГОРОДАМИ, АДРЕСАМИ, ИНДЕКСАМИ, ЭЛЕКТРОННЫМИ ПОЧТАМИ, ТЕЛЕФОННЫМИ НОМЕРАМИ И ПЕРЕМЕННЫЕ "ИМЯ","ФАМИЛИЯ","СТРАНА","ГОРОД","УЛИЦА","ИНДЕКС","ЕМАИЛ","НОМЕР ТЕЛЕФОНА" БУДУТ ПРИСВАИВАТЬСЯ ИЗ МАССИВА РАНДОМНЫМ ИНДЕКСОМ
    const string names[5] = {"Egor", "Ilya", "Denis", "Vadim", "Firuz"};
    const string surnames[5] = {"Kalyuzhny","Slivkov", "Miheev", "Shmarin", "Safarzoda" };
    const string countryes[5] = {"Noth_empire", "United_Union", "Russia_Federation", "Border_Republic", "Great_Voronezh"};
    const string cities[5] = { "Moscow", "Uryupinsk", "Voronezh", "New_Magadan", "Pod_kvasinsk"};
    const string adress[5] = { "Krasna_grad_43", "Lenina_122", "Kozia_453", "Gribkova_88", "New_beer_strit_1561" };
    const int indexx[5] = { 345983, 165446, 576567, 354544, 924824};
    const string emails[5] = {"kdlnfsknl@gmail.ru","seisfjisjefisjafa@mail.com","fsfdskdfks@beep.su","dsfksdfksfs@hehe.gr","walkingtotheriver24@odd.ti"};
    const int phone_numbers[5] = {2423842, 234432424, 1234567890 , 885553535 , 7654321 };


    int randIndex = rand() % 5; // случайный индекс
    string SelectName = names[randIndex];
    string SelectSurname = surnames[randIndex];
    string SelectCountry = countryes[randIndex];
    string SelectCities = cities[randIndex];
    string SelectAdress = adress[randIndex];
    int Selectindexx = indexx[randIndex];
    string SelectEmail = emails[randIndex];
    int SelectPhone_number = phone_numbers[randIndex];

    // Создаем два человека со свойствами

    Personal_information Personal_information1(SelectName, SelectSurname, SelectCountry, SelectCities, SelectAdress, Selectindexx, SelectEmail, SelectPhone_number );

    int randIndex2 = rand() % 5; // cлучайный индекс заново, для второго человека
    
    string SelectName2 = names[randIndex2];
    string SelectSurname2 = surnames[randIndex2];
    string SelectCountry2 = countryes[randIndex2];
    string SelectCities2 = cities[randIndex2];
    string SelectAdress2 = adress[randIndex2];
    int Selectindexx2 = indexx[randIndex2];
    string SelectEmail2 = emails[randIndex2];
    int SelectPhone_number2 = phone_numbers[randIndex2];

    Personal_information Personal_information2(SelectName2, SelectSurname2, SelectCountry2, SelectCities2, SelectAdress2, Selectindexx2, SelectEmail2, SelectPhone_number2);

    Personal_data.push_back(Personal_information1);

    Personal_data.push_back(Personal_information2);


    int choice;

    while (true) {

        // Выводим меню

        cout << endl << "1 - Display information about all personal data of persons" << endl;

        cout << "2 - add people" << endl;

        cout << "3 - delete people" << endl;

        cout << "4 - change personal data" << endl;

        cout << "0 - exit" << endl;

        cout << "Select an action: ";

        cin >> choice;

        cout << "\n";



        switch (choice) {

        case 1:

            // Выводим информацию обо всех персональных данных человека

            for (int i = 0; i < Personal_data.size(); i++) {

                cout << "#" << i << ". ";

                Personal_data[i].show();

                cout << endl;

            }

            break;

        case 2:

            // Добавляем нового человека


            addPersonal_information(Personal_data);

            break;

        case 3:

            // Удаляем человека

            deletePersonal_information(Personal_data);

            break;

        case 4:

            // Изменяем свойства человека

            editPersonal_information(Personal_data);

            break;

        case 0:

            // Выходим из программы

            return;

        default:

            cout << "wrong action choice!" << endl;

            break;

        }

    }

}