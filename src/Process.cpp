//
// Created by mateu on 03/04/2018.
//

#include <iostream>
#include "Process.h"

Process::Process(int x, int y, int z, int id){
    this->clock = clock;
    this->label = "P"+std::to_string(id);
    inTime = x;
    outTime = 0;
    cpuInst = static_cast<int>(y * ((z * 1.0) / 100.0));
    ioInst = y-cpuInst;
    consumedTime = 0;
    ioTimeOut = 0;
    level = 0;
}

void Process::consumeCPU(){
    ++consumedTime;
    --cpuInst;
}

int Process::getInTime() {
    return inTime;
}

void Process::consumeIO() {
    ++consumedTime;
    ioTimeOut = 4;
    --ioInst;
}

int Process::getLevel() {
    return level;
}

int Process::getConsumedT() {
    return consumedTime;
}

void Process::resetConsumed() {
    consumedTime = 0;
}

int Process::getCPU() {
    return cpuInst;
}

int Process::getIO() {
    return ioInst;
}

int Process::waitC() {
    if(ioTimeOut-- == 0){
        return 0; // yet waiting
    }
    return 1; //finish
}

void Process::setOut(int out) {
    outTime = out;
}

int Process::execTime() {
    return outTime - inTime;
}

void Process::setLevel(int level) {
    this->level = level;
}

std::string Process::getId() {
    return label;
}
