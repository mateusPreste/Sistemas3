//
// Created by mateu on 03/04/2018.
//

#ifndef SCHEDULE_CYCLE_ELEMENT_H
#define SCHEDULE_CYCLE_ELEMENT_H


#include "Clock.h"

class Cycle_Element {
public:
    Clock intClock;
    virtual void clock();
};


#endif //SCHEDULE_CYCLE_ELEMENT_H
