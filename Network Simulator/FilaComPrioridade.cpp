#include "FilaComPrioridade.h"
#include <stdexcept>

FilaComPrioridade::FilaComPrioridade(int tamanho) : Fila(tamanho) {
}

FilaComPrioridade::~FilaComPrioridade() {
}


void FilaComPrioridade::enqueue(Datagrama* d, bool prioritario) {
    if(fim + 1 == inicio || (fim == tamanho && inicio == 0))
        throw new overflow_error("");

    datagramas[fim] = d;

    if(prioritario){
        int posicao = fim;
        int posicaoP;

        if(inicio + quantidadePrioritarios >= tamanho + 1)
            posicaoP = (inicio + quantidadePrioritarios) - (tamanho + 1);
        else
            posicaoP = inicio + quantidadePrioritarios;

        while(posicao != posicaoP){
            datagramas[posicao] = datagramas[getPosicaoAnterior(posicao)];
            datagramas[getPosicaoAnterior(posicao)] = d;
            posicao = getPosicaoAnterior(posicao);
        }
        quantidadePrioritarios++;
    }

    if(fim == tamanho)
        fim = 0;
    else
        fim = fim + 1;

    sizee = sizee + 1;
}

void FilaComPrioridade::enqueue(Datagrama* d) {
    enqueue(d, false);
}

Datagrama* FilaComPrioridade::dequeue() {
    if(isEmpty())
        throw new underflow_error("");

    sizee = sizee - 1;

    if(quantidadePrioritarios > 0)
        quantidadePrioritarios--;

    if(inicio == tamanho){
        inicio = 0;
        return datagramas[tamanho];
    }
    else{
        inicio = inicio + 1;
        return datagramas[inicio - 1];
    }
}

int FilaComPrioridade::getPosicaoAnterior(int posicao) {
    if(posicao == 0)
        return tamanho;
    else
        return posicao - 1;
}

