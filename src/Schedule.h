//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_SCHEDULE_H
#define SCHEDULE_SCHEDULE_H


#include "Process.h"
#include "Queue.h"
#include "Cycle_Element.h"

class Schedule : public Cycle_Element{
private:
    int queueAmount;
    int quantum;
    int S;
public:
    Schedule(int, std::vector<int>*, int);
    std::vector< Queue* > schedule;
    void createQueue(int, int);
    Process* nextProcess();
    void addProcess(Process*);
    int getQuantum();
    int size();
    void clock() override;
};

#endif //SCHEDULE_SCHEDULE_H
