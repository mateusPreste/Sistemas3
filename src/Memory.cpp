//
// Created by mateu on 03/04/2018.
//

#include "Memory.h"

Memory::Memory(Schedule* schedule) {
    this->schedule = schedule;
}

void Memory::addProcess(int x, int y, int z, int id){
    Process* newProcess = new Process(x, y, z, id);
    list.push_back(newProcess);
}

void Memory::clock() {
    intClock.nextClock();
    auto it = list.begin();
    for(it; it != list.end(); ){
        Process* process = *it;
        if(process->getInTime() == intClock.getClock()){
            schedule->addProcess(process);
            list.erase(it);
        } else{
            return;
        }
    }
}

bool Memory::empty() {
    return list.empty();
}