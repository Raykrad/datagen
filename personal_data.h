#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Класс "персональные данные"
class Personal_information {
private:

public:
    string A_NAME, A_SURNAME, A_STRANA, A_GOROD, A_ADRES, A_MAIL, A_EMAIL, A_PHONE_NUMBER; // Имя, фамилия, страна, город, адрес, почтовый код, электронная почта, номер телефона
    // Конструктор по умолчанию
    Personal_information() {
        this->A_NAME = "";
        this->A_SURNAME = "";
        this->A_STRANA = "";
        this->A_GOROD = "";
        this->A_ADRES = "";
        this->A_MAIL = "";
        this->A_EMAIL = "";
        this->A_PHONE_NUMBER = "";
    }

    // Параметрический
    Personal_information(string name, string surname, string strana, string gorod, string adres, string mail, string email, string phone_number) {
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
    void setA_NAME(string name) {
        this->A_NAME = name;
    }

    void setA_SURNAME(string surname) {
        this->A_SURNAME = surname;
    }

    void setA_STRANA(string strana) {
        this->A_STRANA = strana;
    }

    void setA_GOROD(string gorod) {
        this->A_GOROD = gorod;
    }

    void setA_ADRES(string adres) {
        this->A_ADRES = adres;
    }

    void setA_MAIL(string mail) {
        this->A_MAIL = mail;
    }

    void setA_EMAIL(string email) {
        this->A_EMAIL = email;
    }

    void setA_PHONE_NUMBER(string phone_number) {
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

    string getA_MAIL() {
        return this->A_MAIL;
    }

    string getA_EMAIL() {
        return this->A_EMAIL;
    }

    string getA_PHONE_NUMBER() {
        return this->A_PHONE_NUMBER;
    }

    // Метод отвечающий за отображение
    void show() {
        cout << "Name: " << this->A_NAME << endl;
        cout << "Surname: " << this->A_SURNAME << endl;
        cout << "Country: " << this->A_STRANA << endl;
        cout << "City: " << this->A_GOROD << endl;
        cout << "Address: " << this->A_ADRES << endl;
        cout << "Mail code: " << this->A_MAIL << endl;
        cout << "E-mail: " << this->A_EMAIL << endl;
        cout << "Phone number: " << this->A_PHONE_NUMBER << endl;
    }
};

// Функция для добавления нового человека в массив
void addPersonal_information(vector<Personal_information>& Personal_data) {
    string name, surname, strana, gorod, adres, email, mail, phone_number;
    //Получаем данные от пользователя нужные для добовление человека

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the surname: ";
    getline(cin, surname);
    cout << "Enter Country: ";
    getline(cin, strana);
    cout << "Enter city: ";
    getline(cin, gorod);
    cout << "Enter street and house number: ";
    getline(cin, adres);
    cout << "Enter the mail code: ";
    getline(cin, mail);
    cout << "Enter the email: ";
    getline(cin, email);
    cout << "Enter phone number: ";
    getline(cin, phone_number);
    // Создаем новый объект Personal_information на основе введенных данных и добавляем его в массив
    Personal_data.push_back(Personal_information(name, surname, strana, gorod, adres, mail, email, phone_number));
    cout << "The personal information has been added successfully!" << endl;
}

// Функция для удаления личных данных из массива
void deletePersonal_information(vector<Personal_information>& Personal_data) {
    int index;

    // Вывод списка людей
    for (int i = 0; i < Personal_data.size(); i++) {
        cout << "#" << i << ". ";
        Personal_data[i].show();
        cout << endl;
    }
    // Получаем номер человека, которого нужно удалить
    cout << "Enter the number of the person you want to delete: " << endl;
    cin >> index;
    if (index >= 0 && index < Personal_data.size()) {
        Personal_data.erase(Personal_data.begin() + index);
        cout << "The person has been successfully deleted!" << endl;
    }
    else {
        cout << "Invalid person number!" << endl;
    }
}

// Функция для изменения данных выбраного пользователем человека 
void editPersonal_information(vector<Personal_information>& Personal_data) {
    int index, property;
    string NewValueString;
    // Выводим список персональных данных человека
    for (int i = 0; i < Personal_data.size(); i++) {
        cout << "#" << i << ". ";
        Personal_data[i].show();
        cout << endl;
    }
    // Получаем номер человека, личные данные которого нужно изменить
    cout << "Enter the number of the person whose parameters you want to change: " << endl;
    cin >> index;
    if (index >= 0 && index < Personal_data.size()) {
        cout << "Select the property you want to change: " << endl;
        cout << "1. Person's name" << endl;
        cout << "\n2. Person's surname" << endl;
        cout << "\n3. Person's country" << endl;
        cout << "\n4. Person's city" << endl;
        cout << "\n5. Person's address" << endl;
        cout << "\n6. Person's mail cod" << endl;
        cout << "\n7. Person's email" << endl;
        cout << "\n8. Person's phone number\n" << endl;
        cin >> property;

        switch (property) {
        case 1:
            cout << "Enter the new name of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_NAME(NewValueString);
            break;
        case 2:
            cout << "Enter the new surname of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_SURNAME(NewValueString);
            break;
        case 3:
            cout << "Enter the new country of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_STRANA(NewValueString);
            break;
        case 4:
            cout << "Enter new city og the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_GOROD(NewValueString);
            break;
        case 5:
            cout << "Enter the new address of the person (street_number): ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_ADRES(NewValueString);
            break;
        case 6:
            cout << "Enter the mail code of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_MAIL(NewValueString);
            break;
        case 7:
            cout << "Enter the new email of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_EMAIL(NewValueString);
            break;
        case 8:
            cout << "Enter the new phone number of the person: ";
            cin.ignore();
            getline(cin,NewValueString);
            Personal_data[index].setA_PHONE_NUMBER(NewValueString);
            break;

        default:
            cout << "Incorrect parameter selection!" << endl;
            break;
        }
        cout << "The parameter has been successfully changed!" << endl;
    }
    else {
        cout << " Invalid person number! " << endl;
    }
}

void GeneratePersonal(vector<Personal_information>& Personal_data) {
    vector<Personal_information> Personal_data1;
    // ЗДЕСЬ МАССИВ С ДАННЫМИ
    const string names[5] = { "Egor", "Ilya", "Denis", "Vadim", "Firuz" };
    const string surnames[5] = { "Kalyuzhny","Slivkov", "Miheev", "Shmarin", "Safarzoda" };
    const string countryes[5] = { "Noth_empire", "United_Union", "Russian_Federation", "Border_Republic", "Great_Voronezh" };
    const string cities[5] = { "Moscow", "Uryupinsk", "Voronezh", "New_Magadan", "Pod_kvasinsk" };
    const string adress[5] = { "Krasna_grad_43", "Lenina_122", "Kozia_453", "Gribkova_88", "New_beer_strit_1561" };
    const string indexx[5] = { "345983", "165446", "576567", "354544", "924824" };
    const string emails[5] = { "kdlnfsknl@gmail.ru","seisfjisjefisjafa@mail.com","fsfdskdfks@beep.su","dsfksdfksfs@hehe.gr","walkingtotheriver24@odd.ti" };
    const string phone_numbers[5] = { "2423842", "234432424", "1234567890" , "88005553535" , "7654321" };
    int randIndex1 = rand() % 5; // случайный индекс
    int randIndex2 = rand() % 5;
    int randIndex3 = rand() % 5;
    int randIndex4 = rand() % 5;
    int randIndex5 = rand() % 5;
    int randIndex6 = rand() % 5;
    int randIndex7 = rand() % 5;
    int randIndex8 = rand() % 5;
    string SelectName = names[randIndex1];
    string SelectSurname = surnames[randIndex2];
    string SelectCountry = countryes[randIndex3];
    string SelectCities = cities[randIndex4];
    string SelectAdress = adress[randIndex5];
    string Selectindexx = indexx[randIndex6];
    string SelectEmail = emails[randIndex7];
    string SelectPhone_number = phone_numbers[randIndex8];

    // Создаем два человека со свойствами
    Personal_information Personal_information1(SelectName, SelectSurname, SelectCountry, SelectCities, SelectAdress, Selectindexx, SelectEmail, SelectPhone_number);
    Personal_data.push_back(Personal_information1);
}

// Основная функция программы
void runPersonal() {
    vector<Personal_information> Personal_data1;
    srand(time(0));
    int choice;
    string warning1;
    while (true) {
        // Вывод меню
        cout << endl << "1. Display information about all personal data of persons" << endl;
        cout << "\n2. Add people" << endl;
        cout << "\n3. Change personal data" << endl;
        cout << "\n4. Delete people" << endl;
        cout << "\n5. Generate a persona" << endl;
        cout << "\n6. Save" << endl;
        cout << "\n7. Exit" << endl;
        cout << "\nSelect an action: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1:
            // Выводим информацию обо всех персональных данных человека
            for (int i = 0; i < Personal_data1.size(); i++) {
                cout << "#" << i << ". ";
                Personal_data1[i].show();
                cout << endl;
            }
            break;
        case 2:
            // Добавляем нового человека
            addPersonal_information(Personal_data1);
            break;
        case 3:
            // Изменяем свойства человека
            cout << "Do you really want to edit the person's data?" << endl;
            cout << "If yes then enter [y] if no enter anything" << endl;
            cin.ignore();
            getline(cin, warning1);
            if ((warning1 == "y") || (warning1 == "Y")) {
                editPersonal_information(Personal_data1);
            }
            cout << endl;
            break;
        case 4:
            // Удаляем человека
            cout << "Do you really want to delete the person's data?" << endl;
            cout << "If yes then enter [y] if no enter anything" << endl;
            cin.ignore();
            getline(cin, warning1);

            if ((warning1 == "y") || (warning1 == "Y")) {
                deletePersonal_information(Personal_data1);
            }
            cout << endl;
            break;
        case 5:
            GeneratePersonal(Personal_data1);
            break;
        case 6:
        {
            ofstream outFile("personal.txt"); // Открываем файл для записи
            // Проверяем, открылся ли файл успешно
            if (!outFile.is_open()) {
                cout << "Failed to open file!" << endl;
                break;
            }
            // Записываем информацию об организациях в файл
            for (int i = 0; i < Personal_data1.size(); i++) {
                outFile << "#" << i << ". ";
                outFile << "Name: " << Personal_data1[i].A_NAME << endl;
                outFile << "Surname: " << Personal_data1[i].A_SURNAME << endl;
                outFile << "Country: " << Personal_data1[i].A_STRANA << endl;
                outFile << "City: " << Personal_data1[i].A_GOROD << endl;
                outFile << "Address: " << Personal_data1[i].A_ADRES << endl;
                outFile << "Mail code: " << Personal_data1[i].A_MAIL << endl;
                outFile << "E-mail: " << Personal_data1[i].A_EMAIL << endl;
                outFile << "Phone number: " << Personal_data1[i].A_PHONE_NUMBER << endl;
                outFile << endl;
            }
            outFile.close(); // Закрываем файл
            cout << "Data successfully written to personal.txt" << endl;
            break;
        }
        case 7:
            cout << "Thanks for using our program" << endl;
            // Выход из программы
            return;
        default:
            cout << "Wrong action choice!" << endl;
            break;
        }
    }
}
