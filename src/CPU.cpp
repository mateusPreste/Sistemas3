//
// Created by mateu on 03/04/2018.
//

#include <iostream>
#include "CPU.h"

CPU::CPU(IO* io, Schedule* schedule, int CSPENALITY) {
    this->io = io;
    this->schedule = schedule;
    this->CSPENALITY = CSPENALITY;
    executing = schedule->nextProcess();
}

void CPU::clock() {
    intClock.nextClock();
    if(CSTime != 0){
        CSTime--;
        std::cout << "CSTime != 0" << std::endl;
        return;
    } else if(executing == nullptr){
        std::cout << "executing == null " << std::endl;
        return;
    } else if(executing->getIO() == 0 && executing->getCPU() == 0){
        std::cout << "all == 0" << std::endl;
        //std::cout << executing << std::endl;
        delete executing;
        //executing = nullptr;
        //executing->setOut(intClock.getClock());
        contextSwitch();
    } else{
        if(executing->getIO() != 0){
            std::cout << "execIO" << std::endl;
            executing->consumeIO();
            if(executing->getIO() != 0){
                io->add(executing);
            }
            if(executing->getIO() != 0){
                contextSwitch();
            }
        } else if(executing->getCPU() != 0){
            std::cout << "execCPU" << " quantum " << executing->getConsumedT() << " " << quantum << std::endl;
            executing->consumeCPU();
            if(executing->getConsumedT() == quantum && executing->getCPU() != 0){
                std::cout << "out of Quantum" << std::endl;
                schedule->addProcess(executing);
                contextSwitch();
            }
        }
    }

}

void CPU::contextSwitch() {
    firstProcess();
    std::cout << "AAA " << std::to_string(executing == nullptr) << std::endl;
    CSTime = CSPENALITY;
}

void CPU::firstProcess() {
    executing = schedule->nextProcess();
    quantum = schedule->getQuantum();
}

void CPU::setQuantum(int quantum) {
    this->quantum = quantum;
}
