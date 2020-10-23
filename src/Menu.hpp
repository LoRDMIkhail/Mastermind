#ifndef H_MENU
#define H_MENU

#include "Logic.hpp"
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
    void PrintDeveloper();
};

#endif
