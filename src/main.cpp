#include "Computer.h"

int main() {
    int quantums[4] = {3, 2, 6};
    // Numero de filas, vetor de quantums, S, Penalidade de troca de contexto
    auto computer = new Computer(3, quantums, 60, 0);
    computer->input();
    while(computer->executing()){
        computer->clock();
    }
    computer->results();
    return 0;
}