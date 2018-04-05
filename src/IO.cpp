//
// Created by mateu on 03/04/2018.
//

#include <iostream>
#include "IO.h"

IO::IO(Schedule* schedule) {
    this->schedule = schedule;
}

void IO::clock() {
    intClock.nextClock();
    auto it = waitList.begin();
    for(it; it != waitList.end(); ){
        Process* waitProcess = *it;
        if(!waitProcess->waitC()){
            std::cout << "ACABOU A ESPERA, " << waitProcess->getId() << " NAO ESTA MAIS ESPERANDO" << std::endl;
            waitList.erase(it);
            schedule->addProcess(waitProcess);
        } else{
            ++it;
        }
    }
}

void IO::add(Process* waitProcess) {
    waitList.push_back(waitProcess);
}

void IO::gamb() {
    auto it = waitList.begin();
    for(it; it != waitList.end(); ++it){
        Process* waitProcess = *it;
        waitProcess->setLevel(1);
        waitProcess->resetConsumed();
    }
}

unsigned long IO::waitListSize() {
    return waitList.size();
}
