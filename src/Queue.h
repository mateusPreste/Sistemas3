//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_QUEUE_H
#define SCHEDULE_QUEUE_H


#include <vector>
#include "Process.h"

class Queue{
private:
    int quantum;
    int id;
public:
    std::vector< Process* > list;
    Queue(int, int);
    void addProcess(Process*);
    Process* nextProcess();
    int getID();
    int getQuantum();
    bool empty();
};


#endif //SCHEDULE_QUEUE_H
