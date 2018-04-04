//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_PROCESS_H
#define SCHEDULE_PROCESS_H


#include "Clock.h"

class Process{
public:
    Process(int, int, int);
    void consumeCPU();
    void consumeIO();
    void resetConsumed();
    void setOut(int);
    void setLevel(int);
    int waitC(); //decrement ioTimeOut
    int getInTime();
    int getLevel();
    int getConsumedT();
    int getCPU();
    int getIO();
    int execTime();
private:
    int inTime, outTime; //life cycle
    int level;
    int cpuInst;
    int ioInst, ioTimeOut;
    int consumedTime;
    Clock clock;
};


#endif //SCHEDULE_PROCESS_H
