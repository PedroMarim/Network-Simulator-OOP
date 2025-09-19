#ifndef TABELA_DE_REPASSE_H_INCLUDED
#define TABELA_DE_REPASSE_H_INCLUDED

#include "No.h"

#include <iostream>
using namespace std;


class TabelaDeRepasse{
public:
    TabelaDeRepasse(int tamanho);
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();
    virtual void setPadrao(No* padrao, int atraso);
    virtual No* getProximoSalto(int endereco, int& atraso);
    virtual void imprimir();

private:
    No** nosAdjacentes;
    int* atrasos;
    int* enderecos;
    int quantidadeDeAdjacentes;
    int atrasoPadrao;
    No* noPadrao;
    int tamanhoMax;

};

#endif // TABELA_DE_REPASSE_H_INCLUDED
