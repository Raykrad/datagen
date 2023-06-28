#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
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

        saveLoginAndPassword(autologin, autopassword, "login_password.txt");
    }

    void enterLoginAndPassword() // для ручного ввода данных
    {
        string login, password;

        cout << "Введите логин (до 12 символов): ";
        getline(cin, login);

        while (login.length() > 12)
        {
            cout << "Логин должен быть не более 12 символов. Попробуйте еще раз: ";
            getline(cin, login);
        }

        cout << "Введите пароль (восемь символов): ";
        getline(cin, password);

        while (password.length() != 8)
        {
            cout << "Пароль должен быть ровно восемь символов. Попробуйте еще раз: ";
            getline(cin, password);
        }

        saveLoginAndPassword(login, password, "login_password.txt");
    }

    void checkLoginAndPassword() // для проверки логина и пароля, тобишь для входа в систему условно
    {
        string login, password, name;
        name = "0";
        cout << "Введите логин: ";
        getline(cin, login);
        cout << "Введите пароль: ";
        getline(cin, password);


        ifstream file("login_password.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line)) // считывание файла по строкам
            {
                if (line.find("Логин: " + login) != string::npos) // если найдена строка с указанным логином, считываем и пароль
                {
                    getline(file, line);
                    if (line.find("Пароль: " + password) != string::npos)
                    {
                        file.close();
                        name = login;
                        cout << "Добро пожаловать, " << name << "!" << endl;
                    }
                }
            }
            file.close();
        }
        if (name == "0")
        {
            cout << "Неправильно введены логин или пароль " << endl;
        }
        name = "0";
    }

private:

    void saveLoginAndPassword(const string& login, const string& password, const string& filename) // сохранялка
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "Логин: " << login << endl;
            file << "Пароль: " << password << '\n' << endl;
            file.close();
            cout << "Данные сохранены " << endl;
        }
        else
        {
            cout << "Ошибка открытия файла " << filename << endl;
        }
    }
};
