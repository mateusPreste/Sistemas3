//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_CPU_H
#define SCHEDULE_CPU_H


#include "IO.h"
#include "Schedule.h"
#include "Clock.h"
#include "Cycle_Element.h"

class CPU : public Cycle_Element{
private:
    int CSTime = 0; //Switch Context penality
    int quantum = 0;
    int CSPENALITY = 0;
    IO* io;
    Schedule* schedule;
public:
    Process* executing = nullptr;
    CPU(IO*, Schedule*, int);
    void clock() override;
    void contextSwitch();
    void firstProcess();
    void setQuantum(int);
    int Texec = 0;
    int Twait = 0;
};


#endif //SCHEDULE_CPU_H
