#include "Computer.h"

int main() {
    int quantums[4] = {20, 4, 8, 16};
    // Numero de filas, vetor de quantums, S, Penalidade de troca de contexto
    auto computer = new Computer(4, quantums, 20, 2);
    computer->input();
    while(computer->executing()){
        computer->clock();
    }
    computer->results();
    return 0;
}