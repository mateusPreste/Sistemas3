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
        std::cout << "Trocando Contexto" << std::endl;
        return;
    } else if(executing == nullptr){
        std::cout << "SEM PROCESSO NA CPU" << std::endl;
        return;
    } else if(executing->getIO() == 0 && executing->getCPU() == 0){
        std::cout << "FIM DO PROCESSO" << std::endl;
        //std::cout << executing << std::endl;
        delete executing;
        executing = nullptr;
        //executing->setOut(intClock.getClock());
        contextSwitch();
    } else{
        if(executing->getIO() != 0){
            std::cout << "EXECUTANDO E/S" << std::endl;
            executing->consumeIO();
            io->add(executing);
            contextSwitch();
        } else if(executing->getCPU() != 0){
            std::cout << "EXECUTANDO " << executing->getId() << " na CPU "
                      << executing->getConsumedT() << "/" << quantum << " quantums consumidos" << std::endl;
            executing->consumeCPU();
            if(executing->getConsumedT() == quantum){
                std::cout << "ACABOU O QUANTUM" << std::endl;
                schedule->addProcess(executing);
                contextSwitch();
            }
        }
    }

    if(executing != nullptr && executing->getIO() == 0 && executing->getCPU() == 0){
        executing->setOut(intClock.getClock());
        std::cout << "FIM DO PROCESSO " << executing->getId() << ": "
                  << "tempo de execucao: " << executing->execTime() <<std::endl;
        delete executing;
        executing = nullptr;
        contextSwitch();
    }
}

void CPU::contextSwitch() {
    firstProcess();
    CSTime = CSPENALITY;
}

void CPU::firstProcess() {
    executing = schedule->nextProcess();
    quantum = schedule->getQuantum();
}

void CPU::setQuantum(int quantum) {
    this->quantum = quantum;
}
