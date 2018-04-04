//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_MEMORY_H
#define SCHEDULE_MEMORY_H


#include "Clock.h"
#include "Process.h"
#include "Schedule.h"
#include "Cycle_Element.h"

class Memory : public Cycle_Element{
private:
    std::vector< Process* > list;
    Schedule* schedule = nullptr;
public:
    Memory(Schedule*);
    void addProcess(int x, int y, int z);
    void clock() override; //add process to Schedule at the right time
    bool empty();
};


#endif //SCHEDULE_MEMORY_H
