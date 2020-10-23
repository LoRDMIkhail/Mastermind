#ifndef H_LOGIC
#define H_LOGIC
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#define const_num_kurs 4
using namespace std;

class Logic {
private:
    bool game = true;
    bool menu = true;
    bool choose;
    char kurs[const_num_kurs];
    char myKurs[const_num_kurs + 1];

public:
    Logic();
    void PrintKurs();
    void CreateKurs();
    bool CheckKursSim(int, int);
    bool CheckMyKurs();
};

#endif
