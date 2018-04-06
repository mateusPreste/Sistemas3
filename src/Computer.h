//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_COMPUTER_H
#define SCHEDULE_COMPUTER_H

#include <vector>
#include "Schedule.h"
#include "IO.h"
#include "CPU.h"
#include "Memory.h"

class Computer {
private:
    int amountList; // quantidade de listas
    int clocks = 0;
    std::vector< int >* quantums;
    Schedule* schedule;
    IO* io;
    CPU* cpu;
    Memory* memory;
    int filas, S, constSwitchPenality;
    int* quantumL;
    int processes = 0;
public:
    Computer(int, int*, int, int);
    void input();
    void clock();
    void results();
    bool executing();
};


#endif //SCHEDULE_COMPUTER_H
