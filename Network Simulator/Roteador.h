#ifndef ROTEADOR_H_INCLUDED
#define ROTEADOR_H_INCLUDED

#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "No.h"

#include <iostream>
using namespace std;


class Roteador: public No {
public:
    Roteador(int endereco);
    virtual ~Roteador();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual void setPadrao(No* padrao, int atraso);

    virtual Evento* processar(int instante);

    static const int TAMANHO_TABELA = 10;

protected:
    Roteador(int endereco, Fila* fila);
    TabelaDeRepasse* tabela;

private:

};

#endif
