//
// Created by mateu on 03/04/2018.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(int id, int quantum) {
    this->id = id;
    this->quantum = quantum;
}

void Queue::addProcess(Process* process) {
    process->setLevel(getID());
    std::cout << "ADDED IN " << getID() << " " << getQuantum() << std::endl;
    list.push_back(process);
}

Process* Queue::nextProcess() {
    auto it = list.begin();
    if(!list.empty()){
        Process* head = *it;
        std::cout << ">>> " << head->getCPU() << " " << head->getIO() << std::endl;
        list.erase(list.begin());
        return head;
    } else{
        return nullptr;
    }
}

int Queue::getID() {
    return id;
}

int Queue::getQuantum() {
    return quantum;
}

bool Queue::empty() {
    return list.empty();
}