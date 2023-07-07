#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Класс "География организаций"
class Geograf_organizations {
private:

public:
    string A_STRANA, A_GOROD, A_ADRES, A_POCHTA; // СТРАНА, ГОРОД, АДРЕС, ПОЧТА!
    // Конструктор по умолчанию
    Geograf_organizations() {
        this->A_STRANA = "";
        this->A_GOROD = "";
        this->A_ADRES = "";
        this->A_POCHTA = "";
    }

    // Параметрический конструктор
    Geograf_organizations(string strana, string gorod, string adres, string pochta) {
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
    ~Geograf_organizations() { }

    // Методы set
    void setA_STRANA(string strana) {
        this->A_STRANA = strana;
    }

    void setA_GOROD(string gorod) {
        this->A_GOROD = gorod;
    }

    void setA_ADRES(string adres) {
        this->A_ADRES = adres;
    }

    void setA_POCHTA(string pochta) {
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

    string getA_POCHTA() {
        return this->A_POCHTA;
    }

    // Метод show
    void show() {
        cout << "Organization's country: " << this->A_STRANA << endl;
        cout << "Organization's city: " << this->A_GOROD << endl;
        cout << "Organization's address: " << this->A_ADRES << endl;
        cout << "Postal code: " << this->A_POCHTA << endl;
    }

};

// Функция для добавления новой организации в массив
void addGeograf_organizations(vector<Geograf_organizations>& Geografies) {
    string strana, gorod, adres, pochta;
    // Получаем данные от пользователя
    cout << "Enter the organization's Country: ";
    cin.ignore();
    getline(cin, strana);
    cout << "Enter the organization's city: ";
    getline(cin, gorod);
    cout << "Enter the organization's Address (Street_Number): ";
    getline(cin, adres);
    cout << "Enter the zip code: ";
    getline(cin, pochta);
    // Создаем новый объект Geograf_organizations на основе введенных данных и добавляем его в массив
    Geografies.push_back(Geograf_organizations(strana, gorod, adres, pochta));
    cout << "The organization has been added successfully!" << endl;
}

// Функция для удаления организации из массива
void deleteGeograf_organizations(vector<Geograf_organizations>& Geografies) {
    int index;
    // Выводим список организаций
    for (int i = 0; i < Geografies.size(); i++) {
        cout << "#" << i << ". ";
        Geografies[i].show();
        cout << endl;
    }
    // Получаем номер организации, который нужно удалить
    cout << "Enter the number of the organization you want to delete: ";
    cin >> index;
    if (index >= 0 && index < Geografies.size()) {
        Geografies.erase(Geografies.begin() + index);
        cout << "The organization has been successfully deleted!" << endl;
    }
    else {
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
    if (index >= 0 && index < Geografies.size()) {
        cout << "Select the property you want to change: " << endl;
        cout << "1. Organization's country" << endl;
        cout << "2. Organization's city" << endl;
        cout << "3. Organization's address" << endl;
        cout << "4. Postal code of the organization" << endl;
        cin >> property;

        switch (property) {
        case 1:
            cout << "Enter the new country of the organization: ";
            cin.ignore();
            getline(cin, NewValueString);
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
            Geografies[index].setA_POCHTA(NewValueString);
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
void GenerateOrganization(vector<Geograf_organizations>& Geografies) {
    vector<Geograf_organizations> Geografies1;
    // ЗДЕСЬ МАССИВ СО ЗНАЧЕНИЯМИ, КОТОРЫЕ БУДУТ СЛУЧАЙНО ПРИСВАИВАТЬСЯ ДЛЯ ПЕРВЫХ ДРУХ ОРГАНИЗАЦИЙ И ГЕНЕРАЦИЯ ЧИСЕЛ ДЛЯ ID
    const string countryes[] = {
     "Russian Federation", "Germany", "France", "Poland", "Belarus", "Finland", "Denmark", "Italy", "China", "Japan",
     "Canada", "Australia", "Brazil", "India", "Mexico", "South Korea", "Spain", "Netherlands", "Switzerland", "Sweden",
     "United States", "United Kingdom", "Austria", "Norway", "Portugal", "Turkey", "Argentina", "Egypt", "Greece", "Israel",
     "Ireland", "Singapore", "Thailand", "New Zealand", "Chile", "Colombia", "Indonesia", "Malaysia", "Peru", "Philippines",
     "Saudi Arabia", "United Arab Emirates", "Kuwait", "Qatar", "Oman", "Bahrain", "Jordan", "Lebanon", "Morocco", "Tunisia",
     "Algeria", "Angola", "Bulgaria", "Czech Republic", "Hungary", "Iceland", "Romania", "Slovakia", "South Africa", "Ukraine", 
     "United States", "United Kingdom", "Spain", "Brazil", "Canada", "Australia", "India", "South Korea", "Mexico", "Netherlands", 
     "Switzerland", "Norway", "Sweden", "Portugal", "Argentina", "Turkey", "Greece", "Egypt", "Israel", "Ireland", "Austria", "Czech Republic", 
     "Hungary", "Indonesia", "Malaysia", "Thailand", "Vietnam", "Philippines", "Singapore", "New Zealand", "South Africa", "Kenya", "Nigeria", 
     "Ghana", "Morocco", "Saudi Arabia", "United Arab Emirates", "Qatar", "Chile", "Colombia", "Peru", "Ecuador", "Venezuela", "Bolivia", 
     "Cuba", "Puerto Rico", "Dominican Republic", "Costa Rica", "Panama", "Honduras", "Guatemala", "El Salvador", "Nicaragua", "Nepal", "Pakistan", 
     "Bangladesh", "Sri Lanka", "Myanmar", "Mongolia", "Kazakhstan", "Uzbekistan", "Tajikistan", "Kyrgyzstan", "Turkmenistan", "Iran", "Iraq", "Syria", 
     "Afghanistan", "Pakistan", "Lebanon", "Jordan", "Kuwait", "Oman", "Yemen", "Ethiopia", "Ghana", "Cameroon", "Ivory Coast", "Senegal", "Sudan", "Tanzania", 
     "Uganda", "Zambia", "Zimbabwe", "Botswana", "Namibia", "Angola", "Mozambique", "Malawi", "Madagascar", "Mauritius", "Mali", "Niger", "Benin", "Togo", "Burkina Faso", 
     "Central African Republic", "Sierra Leone", "Liberia", "Guinea", "Guinea-Bissau", "Gambia", "Equatorial Guinea" };
    const string cities[] = {
     "Moscow", "Berlin", "Paris", "Warsaw", "Minsk", "Helsinki", "Copenhagen", "Rome", "Beijing", "Tokyo",
     "Ottawa", "Sydney", "Brasilia", "New Delhi", "Mexico City", "Seoul", "Madrid", "Amsterdam", "Zurich", "Stockholm",
     "Washington, D.C.", "London", "Vienna", "Oslo", "Lisbon", "Ankara", "Buenos Aires", "Cairo", "Athens", "Jerusalem",
     "Dublin", "Singapore", "Bangkok", "Wellington", "Santiago", "Bogota", "Jakarta", "Kuala Lumpur", "Lima", "Manila",
     "Riyadh", "Dubai", "Kuwait City", "Doha", "Muscat", "Manama", "Amman", "Beirut", "Rabat", "Tunis",
     "Algiers", "Luanda", "Sofia", "Prague", "Budapest", "Reykjavik", "Bucharest", "Bratislava", "Cape Town", "Kyiv",
     "New York", "London", "Barcelona", "Sao Paulo", "Toronto", "Sydney", "Mumbai", "Seoul", "Mexico City", "Amsterdam",
     "Zurich", "Oslo", "Stockholm", "Lisbon", "Buenos Aires", "Ankara", "Athens", "Cairo", "Jerusalem", "Dublin",
     "Vienna", "Prague", "Budapest", "Jakarta", "Kuala Lumpur", "Bangkok", "Hanoi", "Manila", "Singapore", "Wellington",
     "Cape Town", "Nairobi", "Lagos", "Accra", "Rabat", "Riyadh", "Dubai", "Doha", "Santiago", "Bogota", "Lima",
     "Quito", "Caracas", "La Paz", "Havana", "San Juan", "Santo Domingo", "San Jose", "Panama City", "Tegucigalpa",
     "Guatemala City", "San Salvador", "Managua", "Kathmandu", "Islamabad", "Dhaka", "Colombo", "Yangon", "Ulaanbaatar",
     "Astana", "Tashkent", "Dushanbe", "Bishkek", "Ashgabat", "Tehran", "Baghdad", "Damascus", "Kabul", "Islamabad",
     "Beirut", "Amman", "Kuwait City", "Muscat", "Sana'a", "Addis Ababa", "Accra", "Yaounde", "Abidjan", "Dakar",
     "Khartoum", "Dar es Salaam", "Kampala", "Lusaka", "Harare", "Gaborone", "Windhoek", "Luanda", "Maputo", "Lilongwe",
     "Antananarivo", "Port Louis", "Bamako", "Niamey", "Cotonou", "Lome", "Ouagadougou", "Bangui", "Freetown", "Monrovia",
     "Conakry", "Bissau", "Banjul", "Malabo"
    };
    const string adress[] = {
     "Tverskaya Street", "Unter den Linden", "Champs-Elysees", "Nowy Swiat", "Nemiga Street", "Mannerheimintie", "Stroget", "Via del Corso", "Wangfujing Street", "Ginza",
     "Wellington Street", "George Street", "Esplanada dos Ministerios", "Janpath", "Paseo de la Reforma", "Gangnam-daero", "Gran Via", "Dam Square", "Bahnhofstrasse", "Drottinggatan",
     "Pennsylvania Avenue", "Oxford Street", "Ringstrasse", "Karl Johans Gate", "Avenida da Liberdade", "Ataturk Boulevard", "Avenida 9 de Julio", "Sharia Al Tahrir", "Syngrou Avenue", "Jaffa Street",
     "Grafton Street", "Orchard Road", "Thanon Sukhumvit", "Lambton Quay", "Avenida Libertador", "Carrera 7", "Jalan Thamrin", "Jalan Bukit Bintang", "Avenida 28 de Julio", "Roxas Boulevard",
     "King Fahd Road", "Sheikh Zayed Road", "Al Soor Street", "Corniche Street", "Sultan Qaboos Highway", "Government Avenue", "Abdali Boulevard", "Beirut Coastal Road", "Mohammed V Avenue", "Boulevard Habib Bourguiba",
     "Abdelkader Street", "Avenida Salvador Allende", "Vitosha Boulevard", "Wenceslas Square", "Andrassy Avenue", "Laugavegur", "Calea Victoriei", "Námestie SNP", "Long Street", "Khreshchatyk Street",
     "Fifth Avenue", "Baker Street", "Las Ramblas", "Avenida Paulista", "Queen Street", "George Street", "Linking Road", "Gangnam-gu Keywon Street", "Paseo de la Reforma", "Rembrandtplein",
     "Kungstradgarden", "Rossio Square", "Avenida de Mayo", "Cibubur Junction", "Jalan Bukit Bintang", "Thanon Sukhumvit", "Tay Ho District", "Escolta Street", "Scotts Road", "Lambton Quay",
     "Adderley Street", "University Way", "Accra Mall", "Kanda Highway", "Medina Road", "King Fahd Road", "Jumeirah Beach Road", "Al Matar Street", "Bernardo O'Higgins Avenue", "Avenida El Sol",
     "Plaza de San Francisco", "Avenida Ashford", "Avenida Juan Pablo Duarte", "Calle 6A", "Avenida Balboa", "Avenida Lincoln", "Avenida Central", "Calle del Sol", "Calle del Duque",
     "Calle del Prado", "Kathmandu Durbar Square", "Islamabad Expressway", "Kazi Nazrul Islam Avenue", "Galle Road", "Strand Road", "Sukhbaatar Square", "Abay Avenue", "Mirzo Ulugbek Street", "Dushanbe City Boulevard",
     "Chui Avenue", "Archabil Avenue", "Valiasr Street", "Al Rasheed Street", "Mar Mousa Street", "Darul Aman Road", "Kabul-Jalalabad Road", "Imran Khan Avenue", "Hamdan bin Mohammed Street", "Sana'a University Street",
     "Churchill Avenue", "Independence Avenue", "Yaounde One Way Street", "Abidjan Boulevard", "Independence Avenue", "Bagamoyo Road", "Kampala Road", "Freedom Way", "Samora Machel Avenue", "Botswana A1 Highway",
     "Independence Avenue", "Avenida 25 de Setembro", "Robert Mugabe Avenue", "Independence Avenue", "Antananarivo Avenue", "Sir William Newton Street", "Rue Mohammed V", "Avenue de la Republique", "Boulevard 13 Janvier", 
     "Avenue de l'independance", "Avenue de la Liberation", "Banjul Highway", "Avenida de Guinea Ecuatorial"
    };
    const string indexx[100] = {
     "666666", "123456", "126758", "838351", "146111", "198755", "375734", "5235123", "645375", "696722",
     "201932", "435262", "687468", "235970", "873656", "102983", "497566", "675840", "109573", "567813",
     "908721", "453897", "128797", "385627", "765932", "989281", "203588", "389074", "746090", "428507",
     "721082", "372624", "928384", "148215", "290386", "758312", "966243", "173405", "586931", "493857",
     "620379", "184750", "936580", "403971", "857398", "678120", "238647", "410930", "856328", "726374",
     "638470", "902734", "147908", "527117", "908293", "123499", "298139", "795237", "345212", "830498",
     "360134", "875939", "176434", "691092", "233983", "875910", "871263", "287520", "620389", "193857",
     "564290", "765912", "342163", "702832", "982726", "491087", "902384", "841263", "238758", "586731",
     "239687", "593871", "957130", "473819", "682759", "689273", "457610", "438900", "775832", "914627",
     "165398", "677234", "903586", "456871", "687439", "358340", "989214", "264739", "786983", "905832" };
    int randIndex = rand() % 100; // рандом индекс
    string SelectCountry = countryes[randIndex];
    string SelectCities = cities[randIndex];
    string SelectAdress = adress[randIndex];
    string Selectindexx = indexx[randIndex];
    Geograf_organizations Geograf_organizations(SelectCountry, SelectCities, SelectAdress, Selectindexx);
    Geografies.push_back(Geograf_organizations);
    cout << "\nThe organization has been successfully generated!" << endl;
}


// Основная функция программы
void runGeografy() {
    srand(time(0));
    vector<Geograf_organizations> Geografies1;
    ofstream fileOut("file.txt");
    if (!fileOut) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }
    int choice;
    while (true) {
        // Выводим меню
        cout << endl << "1. Display information about all geographical data of organizations" << endl;
        cout << "\n2. Add an organization" << endl;
        cout << "\n3. Delete an organization" << endl;
        cout << "\n4. Change the geographical parameters of the organization" << endl;
        cout << "\n5. Generate one organization" << endl;
        cout << "\n6. Save data" << endl;
        cout << "\n7. Exit" << endl;
        cout << "\nSelect an action: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            // Выводим информацию обо всех географических данных организаций
            for (int i = 0; i < Geografies1.size(); i++) {
                cout << "#" << i << ". ";
                Geografies1[i].show();
                cout << endl;
            }
            break;
        case 2:
            // Добавляем новую организацию
            addGeograf_organizations(Geografies1);
            break;

        case 3:
            // Удаляем организацию
            deleteGeograf_organizations(Geografies1);
            break;
        case 4:
            // Изменяем свойства организации
            editGeograf_organizations(Geografies1);
            break;
        case 5:
            // Сгенерировать организацию с географическими данными.
            GenerateOrganization(Geografies1);
            break;
        case 6:
        {
            ofstream outFile("geografy.txt"); // Открываем файл для записи
            // Проверяем, открылся ли файл успешно
            if (!outFile.is_open()) {
                cout << "Failed to open file!" << endl;
                break;
            }
            // Записываем информацию об организациях в файл
            for (int i = 0; i < Geografies1.size(); i++) {
                outFile << "#" << i << ". ";
                outFile << "Organization's country: " << Geografies1[i].A_STRANA << endl;
                outFile << "Organization's city: " << Geografies1[i].A_GOROD << endl;
                outFile << "Organization's address: " << Geografies1[i].A_ADRES << endl;
                outFile << "Postal code: " << Geografies1[i].A_POCHTA << endl;
                outFile << endl;
            }
            outFile.close(); // Закрываем файл
            cout << "Data successfully written to geografy.txt" << endl;
            break;
        }
        case 7:
            // Выходим из программы
            return;
        default:
            cout << "Wrong choice of action!" << endl;
            break;
        }
    }
}
