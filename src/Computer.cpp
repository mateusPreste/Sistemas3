//
// Created by mateu on 03/04/2018.
//

#include "Computer.h"
#include <iostream>

Computer::Computer(int filas, int quantumL[], int S, int contSwitchPenality) {
    this->filas = filas;
    this->S = S;
    this->constSwitchPenality = contSwitchPenality;
    this->quantumL = quantumL;

    amountList = filas; // quantidade de listas
    quantums = new std::vector<int>(quantumL, quantumL + filas);
    std::cout << ">>>>>>>>>>>>>> " << quantums->size() << std::endl;

    schedule = new Schedule(amountList, quantums, S);
    io = new IO(schedule);
    cpu = new CPU(io, schedule, contSwitchPenality);
    memory = new Memory(schedule);

    clocks = 0;
}

void Computer::clock() {
    clocks++;

    if(!memory->empty()){
        memory->clock();
    }
    if(schedule->size() != 0 && cpu->executing == nullptr){
        cpu->firstProcess();
    }
    schedule->clock();
    io->clock();
    cpu->clock();
    std::cout << ">>> FIM DO CLOCK: " << clocks << std::endl << std::endl;


    if(clocks % S == 0 && cpu->executing != nullptr){
        cpu->executing->setLevel(1);
        cpu->executing->resetConsumed();
        cpu->setQuantum(quantumL[0]);
        io->gamb();
    }
}

bool Computer::executing() {
    return !(cpu->executing == nullptr && schedule->size() == 0) || !memory->empty() || io->waitListSize() != 0;
}

void Computer::input() {
    int amount;
    std::cin >> amount;
    processes = amount;
    int x, y, z;
    int id = 1;
    while(amount--){
        std::cin >> x >> y >> z;
        memory->addProcess(x, y, z, id);
        ++id;
    }
}

void Computer::results() {
    std::cout << "Resultados: " << clocks << std::endl << "Tempo de Execucao: " << (double) cpu->Texec/processes
              << std::endl << "Tempo de Espera: " << (double) cpu->Twait/processes;
}
