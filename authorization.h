#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Authorization
{

public:

    Authorization()
    {
        srand(time(NULL));
    }

    void authorizationMenu()
    {
        int cases = 0;
        bool loginCompleted = false;
        while (loginCompleted != true)
        {
            cout << "\nTo access the system, log in to your account." << endl;
            cout << "To log in, enter '1';\nIf you don't have an account, enter '2' for automatic generation or '3' for manual data entry;\nIf you want to edit already existing data, enter '4'." << endl;
            cout << "Enter the desired action number: ";
            cin >> cases;
            switch (cases)
            {
            case 1:
                checkLoginAndPassword();
                break;
            case 2:
                autoGeneration();
                break;
            case 3:
                enterLoginAndPassword();
                break;
            case 4:
                changeLoginOrPassword();
                break;
            }
        }
    }

private:

    void autoGeneration() // для автогенерации логина с паролем
    {
        const int passwordLength = 8, loginLength = 12;
        char autopassword[passwordLength + 1], autologin[loginLength + 1];
        for (int i = 0; i < passwordLength; i++)
        {
            int random = rand() % 62; // генерация случайного числа от 0 до 61, для определения символа, буква или цифра, какого реестра
            if (random < 26)
                autopassword[i] = 'a' + random; // случайная буква от 'a' до 'z'
            else if (random < 52)
                autopassword[i] = 'A' + random - 26; // случайная буква от 'A' до 'Z'
            else
                autopassword[i] = '0' + random - 52; // случайная цифра от '0' до '9'
        }

        for (int i = 0; i < loginLength; i++)
        {
            int random = rand() % 48;
            if (random < 19)
                autologin[i] = 'a' + random;
            else
                autologin[i] = 'A' + random - 19;
        }

        autologin[loginLength] = '\0';
        autopassword[passwordLength] = '\0';

        cout << "Login and password were generated successfully, remember them for further login." << endl;
        cout << "Login: " << autologin << endl;
        cout << "Password: " << autopassword << "" << endl;
        saveLoginAndPassword(autologin, autopassword, "login_password.txt");
    }

    void enterLoginAndPassword() // для ручного ввода данных
    {
        string login, password;

        cout << "Enter your username (up to 12 characters): ";
        cin >> login;

        while (login.length() > 12)
        {
            cout << "The username must be no more than 12 characters. Try again: ";
            cin >> login;
        }

        cin.ignore();

        cout << "Enter the password (eight characters): ";
        cin >> password;

        while (password.length() != 8)
        {
            cout << "The password must be exactly eight characters long. Try again: ";
            cin >> password;
        }

        saveLoginAndPassword(login, password, "login_password.txt");
    }

    void checkLoginAndPassword() // для проверки логина и пароля, тобишь для входа в систему условно
    {
        string login, password, name;
        bool loginCompleted = false;
        name = "0";
        cout << "Enter your username: ";
        cin >> login;
        cout << "Enter the password: ";
        cin >> password;


        ifstream file("login_password.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line)) // считывание файла по строкам
            {
                if (line.find("Username: " + login) != string::npos) // если найдена строка с указанным логином, считываем и пароль
                {
                    getline(file, line);
                    if (line.find("Password: " + password) != string::npos)
                    {
                        file.close();
                        loginCompleted = true;
                        name = login;
                        cout << "Welcome, " << name << "!" << endl;
                    }
                }
            }
            file.close();
        }
        if (name == "0")
        {
            cout << "Username or password entered incorrectly " << endl;
        }
        name = "0";
    }

    void changeLoginOrPassword() // редактура уже существующих логинов с паролями
    {
        string login, password;
        cout << "Enter your username: ";
        cin >> login;
        cout << "Enter the password: ";
        cin >> password;

        ifstream file("login_password.txt");
        if (!file)
        {
            cout << "File opening error login_password.txt" << endl;
            return;
        }

        string line, newLine;
        bool found = false;

        cout << "Choose what you want to change (1 - username, 2 - password): ";
        int choice;
        cin >> choice;
        cin.ignore(); // игнор новой строки, без этого всё ломается (костыль)

        while (getline(file, line))
        {
            if (line.find("Username: " + login) != string::npos && choice == 1)
            {
                cout << "Old username: " << login << endl;
                cout << "Enter new username: ";
                cin >> login;
                newLine += "Username: " + login + "\n";
                found = true;
                cout << "Username successfully changed" << endl;
                continue;
            }
            if (line.find("Password: " + password) != string::npos && choice == 2)
            {
                cout << "Old password: " << password << endl;
                cout << "Enter new password: ";
                cin >> password;
                newLine += "Password: " + password + "\n";
                found = true;
                cout << "Password successfully changed" << endl;
                continue;
            }
            newLine += line + "\n";
        }

        file.close();

        if (!found)
        {
            cout << "Login or password not found" << endl;
            return;
        }

        ofstream outFile("login_password.txt");
        if (!outFile)
        {
            cout << "File opening error login_password.txt" << endl;
            return;
        }

        outFile << newLine;
        outFile.close();

    }

    void saveLoginAndPassword(const string& login, const string& password, const string& filename) // сохранялка 
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "Username: " << login << endl;
            file << "Password: " << password << '\n' << endl;
            file.close();
            cout << "Data saved." << endl;
        }
        else
        {
            cout << "File opening error." << filename << endl;
        }
    }

};
