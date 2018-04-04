//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_IO_H
#define SCHEDULE_IO_H


#include "Process.h"
#include "Schedule.h"
#include "Cycle_Element.h"

class IO : public Cycle_Element{
private:
    std::vector < Process* > waitList;
    Schedule* schedule;
public:
    IO(Schedule*);
    void clock() override;
    void gamb();
    void add(Process*);
};


#endif //SCHEDULE_IO_H
