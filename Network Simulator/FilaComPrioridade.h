#ifndef FILACOMPRIORIDADE_H
#define FILACOMPRIORIDADE_H

#include <iostream>
using namespace std;

#include "Fila.h"
#include "Datagrama.h"

class FilaComPrioridade: public Fila {
public:
    FilaComPrioridade(int tamanho);
    virtual ~FilaComPrioridade();
    virtual void enqueue(Datagrama* d, bool prioritario);
    virtual void enqueue(Datagrama* d);

    virtual Datagrama* dequeue();

private:
    int quantidadePrioritarios = 0;
    virtual int getPosicaoAnterior(int posicao);
};

#endif // FILACOMPRIORIDADE_H
