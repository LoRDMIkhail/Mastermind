#ifndef H_MENU
#define H_MENU

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

class Menu {
private:
    bool menu = true;
    bool exit = false;

public:
    Menu();
    void PrintMenu();
    void PrintGame();
    void PrintDeveloper();
};

#endif
