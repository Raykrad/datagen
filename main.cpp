#include <iostream>
#include "authorization.h"
#include "personal_data.h"
#include "Organizathion.h"
#include "GeografyDatabase.h"
#include "Economical database.h"
#include <Windows.h>
using namespace std;

int main() {
    Authorization user;
    user.authorizationMenu();
    int cases = 0;
    while (cases != 5) {
        cout << "\nMenu" << endl;
        cout << "\nPossible actions:" << endl;
        cout << "\n1. Personal data;\n \n2. Geographical data;\n \n3. Organizational data;\n \n4. Financial data;\n \n5. Exit." << endl;
        cout << "Enter the desired action number: ";
        cin >> cases;
        switch (cases) 
        {
        case 1:
        {
            runPersonal();
            break;
        }
        case 2:
        {
            runGeografy();
            break;
        }
        case 3:
        {
            Organizathions();
            break;
        }
        case 4:
        {
            EconomicalDate eco;
            eco.EcoMenu();
            break;
        }
        case 5:
            break;
        default:
            cout << "Incorrect index entered." << endl;
            break;
        }
    }
    return 0;
}