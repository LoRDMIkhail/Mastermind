#include "Logic.hpp"

Logic::Logic()
{
    game = true;
    menu = true;
    while (menu) {
        CreateKurs();
        cout << "Быки и коровы" << endl;
        while (game) {
            cout << "Введите число: ";
            cin >> myKurs;
            if (CheckMyKurs()) {
                game = false;
                cout << "Правильно!";
                PrintKurs();
                this_thread::sleep_for(chrono::seconds(5));
            }
        }
        cout << "Играть снова? 1 - yes 0 - no" << endl;
        cin >> choose;
        system("clear");
        if (choose)
            game = true;
        else
            menu = false;
    }
}

bool Logic::CheckKursSim(int numMax, int numRand)
{
    if (kurs[0] == '0')
        return false;
    for (int i = 0; i < numMax; i++) {
        if (kurs[i] == numRand) {
            return false;
        }
    }
    return true;
}

void Logic::CreateKurs()
{
    int min = 48, max = 57, randNum;
    bool checkSim = true;
    for (int i = 0; i < const_num_kurs; i++) {
        while (checkSim) {
            srand((unsigned int)time(NULL));
            randNum = min + rand() % (max - min + 1);
            if (CheckKursSim(i, randNum))
                checkSim = false;
        }
        kurs[i] = randNum;
        checkSim = true;
    }
}

void Logic::PrintKurs()
{
    for (int i = 0; i < const_num_kurs; i++) {
        cout << kurs[i];
    }
    cout << endl;
}

bool Logic::CheckMyKurs()
{
    int numSovp = 0, numPlace = 0;
    for (int i = 0; i < const_num_kurs; i++) {
        if (kurs[i] == myKurs[i])
            numPlace++;
    }
    for (int i = 0; i < const_num_kurs; i++) {
        for (int j = 0; j < const_num_kurs; j++) {
            if (kurs[i] == myKurs[j])
                numSovp++;
        }
    }
    cout << "Цифр совпало\t\t " << numSovp << endl;
    cout << "Цифр совпало на своих местах\t " << numPlace << endl << endl;
    if (numPlace == const_num_kurs)
        return true;
    return false;
}
