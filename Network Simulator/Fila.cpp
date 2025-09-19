#include "Fila.h"
#include <stdexcept>

Fila::Fila(int tamanho) {
    if(tamanho <= 0)
        throw new invalid_argument("");

    this->tamanho = tamanho;
    datagramas = new Datagrama*[tamanho + 1];
}

Fila::~Fila() {
    for(int i = 0; i < sizee; i++){
        if(inicio + i >= tamanho + 1)
            delete datagramas[(inicio + i)- (tamanho + 1)];
        else
            delete datagramas[inicio + i];
    }
    delete[] datagramas;
}

void Fila::enqueue(Datagrama* d) {
    if(fim + 1 == inicio || (fim == tamanho && inicio == 0))
        throw new overflow_error("");

    datagramas[fim] = d;
    if(fim == tamanho)
        fim = 0;
    else
        fim = fim + 1;

    sizee = sizee + 1;
}

Datagrama* Fila::dequeue() {
    if(isEmpty())
        throw new underflow_error("");

    sizee = sizee - 1;

    if(inicio == tamanho){
        inicio = 0;
        return datagramas[tamanho];
    }
    else{
        inicio = inicio + 1;
        return datagramas[inicio - 1];
    }
}

bool Fila::isEmpty() {
    return (inicio == fim);
}

int Fila::getSize() {
    return sizee;
}

void Fila::imprimir() {
}
