#include "Menu.hpp"

void Menu::PrintGame()
{
}
void Menu::PrintDeveloper()
{
    cout << "Разработчик: Михаил Черепанов\nПодождите, скоро вы вернетесь "
            "в меню..."
         << endl;
}
void Menu::PrintMenu()
{
    system("clear");
    cout << "\tБыки и коровы" << endl;
    cout << "1) Начать игру" << endl;
    cout << "2) Разработчик" << endl;
    cout << "3) Выход" << endl;
    cout << "Выберите пункт меню: ";
}
Menu::Menu()
{
    while (menu) {
        PrintMenu();
        string s;
        cin >> s;
        if (s.size() > 1)
            continue;
        switch (s[0]) {
        case '1':
            system("clear");
            PrintMenu();
            break;
        case '2':
            system("clear");
            PrintDeveloper();
            this_thread::sleep_for(chrono::seconds(3));
            system("clear");
            PrintMenu();
            break;
        case '3':
            system("clear");
            return;
        default:
            break;
        }
    }
}
