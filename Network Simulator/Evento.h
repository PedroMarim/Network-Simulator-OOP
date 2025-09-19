#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
using namespace std;

#include "Datagrama.h"
#include "No.h"

class No;

class Evento{
private:
    int instante;
    No* destino;
    Datagrama* d;

public:
    Evento(int instante, No* destino, Datagrama* d);
    virtual ~Evento();

    virtual int getInstante();
    virtual No* getDestino();
    virtual Datagrama* getDatagrama();

    virtual void imprimir();
};

#endif // EVENTO_H

