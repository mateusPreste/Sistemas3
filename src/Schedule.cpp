//
// Created by mateu on 03/04/2018.
//

#include <iostream>
#include "Schedule.h"

Schedule::Schedule(int queueAmount, std::vector<int>* quantList, int S) {
    this->queueAmount = queueAmount;
    this->S = S;
    int id = 1;
    for(int thisQuantum : *quantList){
        createQueue(id++, thisQuantum);
    }
}

void Schedule::createQueue(int id, int quantum) {
    Queue* queue = new Queue(id, quantum);
    schedule.push_back(queue);
}

Process* Schedule::nextProcess() {
    for(Queue* queue : schedule){
        Process* pointer = queue->nextProcess();
        if(pointer != nullptr){
            quantum = queue->getQuantum();
            return pointer;
        }
    }
    return nullptr;
}

void Schedule::addProcess(Process* newProcess) {
    Queue* thisQueue = nullptr;
    for(Queue* queue : schedule){
        thisQueue = queue;
        if(newProcess->getLevel() == 0){ //first insertion, go to top
            queue->addProcess(newProcess);
            return;
        }
        if(newProcess->getLevel() == queue->getID()){ // same level
            if(newProcess->getConsumedT() >= queue->getQuantum()){ // no quantum left
                newProcess->resetConsumed(); // reset quantum
            } else{
                queue->addProcess(newProcess); // insert
                return;
            }
        } else if(newProcess->getLevel() < queue->getID()){
            queue->addProcess(newProcess); // insert one level below
            return;
        }
    }
    if(thisQueue != nullptr){
        thisQueue->addProcess(newProcess);
    } else{
        std::cout << "ERROR" << std::endl;
    }
}

int Schedule::getQuantum() {
    return quantum;
}

int Schedule::size() {
    int size = 0;
    for(Queue* queue : schedule){
        size += queue->list.size();
    }
    return size;
}

void Schedule::clock() {
    Cycle_Element::clock();

    //restart Schedule
    if(intClock.getClock() % S == 0){
        std::cout << "GAMBIARRA EXECUTED" << std::endl;
        for(Queue* queue : schedule){
            if(queue->getID() != 1){
                for(Process* tP = queue->nextProcess(); tP != nullptr; tP = queue->nextProcess()){
                    tP->resetConsumed();
                    tP->setLevel(0);
                    addProcess(tP);
                }
            }
        }
    }
}
