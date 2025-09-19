#ifndef REDE_H
#define REDE_H

#include <iostream>
using namespace std;

#include "No.h"
#include "Hospedeiro.h"

#include <list>

class Rede{
private:
    list<No*>* nos;
    list<Hospedeiro*>* hospedeiros;
    int quantidade = 0;

public:
    Rede();
    virtual ~Rede();

    virtual void adicionar(No* n);
    virtual No* getNo(int endereco);

    virtual list<No*>* getNos();
    virtual list<Hospedeiro*>* getHospedeiros();

    virtual void imprimir();
};

#endif // REDE_H
