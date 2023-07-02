#include <iostream>
#include "authorization.h"
#include <Windows.h>

using namespace std;

int main()
{
    Authorization user;
    user.authorizationMenu();
    int cases = 0;
    while (cases != 5)
    {
        cout << "\nMenu" << endl;
        cout << "Possible actions:" << endl;
        cout << "1. Personal data; \n2. Geographical data; \n3. Organizational data; \n4. Financial data; \n5. Exit." << endl;
        cout << "Enter the desired action number: ";
        cin >> cases;
        switch (cases) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            break;
        default:
            cout << "Incorrect index entered." << endl;
            break;
        }
    }
    return 0;
}
