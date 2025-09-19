#ifndef FILA_H
#define FILA_H

#include <iostream>
using namespace std;

#include "Datagrama.h"

class Fila{
protected:
    int tamanho;
    int inicio = 0;
    int fim = 0;
    int sizee = 0;
    Datagrama** datagramas;

public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama *d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();
    virtual int getSize();

    virtual void imprimir();
};

#endif // FILA_H
