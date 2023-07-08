#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Класс "данные организаций"
class Organizations_database {
private:

public:
    string A_NAME, A_EMAIL, A_NUMBER;
    int A_ID;
    // Конструктор по умолчанию
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

    // Конструктор копирования
    Organizations_database(const Organizations_database& other) {
        this->A_NAME = other.A_NAME;
        this->A_EMAIL = other.A_EMAIL;
        this->A_ID = other.A_ID;
        this->A_NUMBER = other.A_NUMBER;
    }

    // Деструктор
    ~Organizations_database() { }

    // Методы set
    void setA_NAME(string name) {
        this->A_NAME = name;
    }

    void setA_EMAIL(string email) {
        this->A_EMAIL = email;
    }

    void setA_ID(int id) {
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
        cout << "Organization's name: " << this->A_NAME << endl;
        cout << "Organization's e-mail: " << this->A_EMAIL << endl;
        cout << "Organization's id: " << this->A_ID << endl;
        cout << "Telephon number: " << this->A_NUMBER << endl;
    }
};

// Функция для добавления новой организации в массив
void addOrganizations_database(vector<Organizations_database>& Organizathions) {
    string name, email, number;
    int id;
    // Получаем данные от пользователя
    cout << "Enter the organizathon's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the organizathon's name email: ";
    getline(cin, email);
    cout << "Enter the organization's telephon number: ";
    getline(cin, number);
    cout << "Enter the organization's id: ";
    cin >> id;
    // Создаем новый объект Organizations_database на основе введенных данных и добавляем его в массив
    Organizathions.push_back(Organizations_database(name, email, id, number));
    cout << "The organization has been added successfully!" << endl;
}

// Функция для удаления организации из массива
void deleteOrganizations_database(vector<Organizations_database>& Organizathions) {
    int index;
    for (int i = 0; i < Organizathions.size(); i++) {
        cout << "#" << i << ". ";
        Organizathions[i].show();
        cout << endl;
    }
    cout << "Enter the number of the organization you want to delete: ";
    cin >> index;
    if (index >= 0 && index < Organizathions.size()) {
        Organizathions.erase(Organizathions.begin() + index);
        cout << "The organization has been successfully deleted!" << endl;
    }
    else {
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
        cout << "1. Organization's name" << endl;
        cout << "2. Organization's email" << endl;
        cout << "3. Organization's id" << endl;
        cout << "4. Postal code of the organization telephon number" << endl;
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

void GenerateOrganizathion(vector<Organizations_database>& Organizathions) {
    vector<Organizations_database> Organizathions1;
    const string Names[10] = { "Rostec", "Yahoo", "Yandex", "Google", "OOO Chebyrek", "000 Company", "Pizza time", "Coffe time", "Tea time", "OOO Farmers" };
    const string Emails[10] = { "Qwe@yandex.ru", "Org@mail.ru", "Company@rambler.ru", "Jojo@gmail.com", "serega@Microsoft.com", "OOO@gmail.ru", "Boss@mail.ru", "pochta@yandex.ru", "DontWrite@gmail.com", "BadCompany@mail.ru" };
    const string numbers[10] = { "+7-(922)-555-1234", "+1-(231)-189-0643", "+5-(851)-755-7330", "+9-(326)-111-1114", "+6-(666)-666-6666", "+1-(261)-116-1616", "+2-(222)-622-2262", "+3-(456)-789-1234", "+5-(555)-555-5555", "+9-(876)-543-2100" };
    int Selectid = rand() % 100000000 + 1;
    int randIndex1 = rand() % 10;
    int randIndex2 = rand() % 10;
    int randIndex3 = rand() % 10;
    string SelectName = Names[randIndex1];
    string SelectEmail = Emails[randIndex2];
    string SelectNumbers = numbers[randIndex3];
    // Создаем две организации со свойствами
    Organizations_database Organizations_database1(SelectName, SelectEmail, Selectid, SelectNumbers);
    Organizathions.push_back(Organizations_database1);
}
// Основная функция программы
void Organizathions() {
    srand(time(0));
    vector<Organizations_database> Organizathions1;
    int choice;
    while (true) {
        cout << endl << "1. Display information about all data of organizations" << endl;
        cout << "\n2. Add an organization" << endl;
        cout << "\n3. Delete an organization" << endl;
        cout << "\n4. Change the parameters of the organization" << endl;
        cout << "\n5. Generate an organization" << endl;
        cout << "\n6. Save" << endl;
        cout << "\n7. Exit" << endl;
        cout << "\nSelect an action: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1:
            for (int i = 0; i < Organizathions1.size(); i++) {
                cout << "#" << i << ". ";
                Organizathions1[i].show();
                cout << endl;
            }
            break;
        case 2:
            addOrganizations_database(Organizathions1);
            break;
        case 3:
            deleteOrganizations_database(Organizathions1);
            break;
        case 4:
            editOrganizations_database(Organizathions1);
            break;
        case 5:
            GenerateOrganizathion(Organizathions1);
            cout << "Successfully generated!" << endl;
            break;
        case 6:
        {
            ofstream outFile("organizathions.txt"); // Открываем файл для записи
            // Проверяем, открылся ли файл успешно
            if (!outFile.is_open()) {
                cout << "Failed to open file!" << endl;
                break;
            }
            // Записываем информацию об организациях в файл
            for (int i = 0; i < Organizathions1.size(); i++) {
                outFile << "#" << i << ". ";
                outFile << "Organization's name: " << Organizathions1[i].A_NAME << endl;
                outFile << "Organization's e-mail: " << Organizathions1[i].A_EMAIL << endl;
                outFile << "Organization's id: " << Organizathions1[i].A_ID << endl;
                outFile << "Telephon number: " << Organizathions1[i].A_NUMBER << endl;
                outFile << endl;
            }
            outFile.close(); // Закрываем файл
            cout << "Data successfully written to organizathions.txt" << endl;
            break;
        }
        case 7:
            return;
        default:
            cout << "Wrong choice of action!" << endl;
            break;
        }
    }
}
