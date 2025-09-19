#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include "Segmento.h"

#include <iostream>
using namespace std;

#include <string>

class Datagrama{
private:
    int origem;
    int destino;
    Segmento* segmento;

public:
    Datagrama(int origem, int destino, Segmento* dado);
    virtual ~Datagrama();
    virtual int getOrigem();
    virtual int getDestino();
    virtual Segmento* getSegmento();

    virtual void imprimir();
};

#endif // DATAGRAMA_H
