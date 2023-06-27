// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

    ~Authorization()
    { }

	string autoLoginGeneration()
	{
        const int loginLength = 12;
        char login[loginLength + 1];

        for (int i = 0; i < loginLength; i++)
        {
            int random = rand() % 48;
            if (random < 19)
                login[i] = 'a' + random;
            else
                login[i] = 'A' + random - 19;
        }

        login[loginLength] = '\0';

        return string(login);
	}


    string autoPasswordGeneration()
    {
        const int passwordLength = 8;
        char password[passwordLength + 1];
        for (int i = 0; i < passwordLength; i++)
        {
            int random = rand() % 62; // генерация случайного числа от 0 до 61, для определения символа, буква или цифра, какого реестра
            if (random < 26)
                password[i] = 'a' + random; // случайная буква от 'a' до 'z'
            else if (random < 52)
                password[i] = 'A' + random - 26; // случайная буква от 'A' до 'Z'
            else
                password[i] = '0' + random - 52; // случайная цифра от '0' до '9'
        }

        password[passwordLength] = '\0';

        return string(password);
    }

    string manualLoginGeneration()
    {
        const int loginLength = 12;
        char login[loginLength + 1];

        for (int i = 0; i < loginLength; i++)
        {
            int random = rand() % 48;
            if (random < 19)
                login[i] = 'a' + random;
            else
                login[i] = 'A' + random - 19;
        }

        login[loginLength] = '\0';

        return string(login);
    }

    void saveLoginAndPassword(const string& login, const string& password, const string& filename)
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "Логин: " << login << endl;
            file << "Пароль: " << password << '\n' << endl;
            file.close();
        }
        else
        {
            cout << "Ошибка открытия файла " << filename << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Authorization aza;
    string login = aza.autoLoginGeneration();
    string password = aza.autoPasswordGeneration();

    cout << "Логин: " << login << endl;
    cout << "Пароль: " << password << endl;

    aza.saveLoginAndPassword(login, password, "login_password.txt");

    return 0;
}
