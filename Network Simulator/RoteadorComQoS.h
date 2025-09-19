#ifndef ROTEADORCOMQOS_H
#define ROTEADORCOMQOS_H

#include <iostream>
using namespace std;

#include "FilaComPrioridade.h"
#include "Roteador.h"
#include <vector>

class RoteadorComQoS: public Roteador {
public:
    RoteadorComQoS(int endereco);
    virtual ~RoteadorComQoS();

    virtual void priorizar(int destino);
    virtual vector<int>* getDestinosPriorizados();

    virtual void receber(Datagrama* d);

protected:

private:
    vector<int>* destinosPriorizados;
};

#endif // ROTEADORCOMQOS_H
