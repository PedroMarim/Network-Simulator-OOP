#include "RoteadorComQoS.h"
#include <algorithm>


RoteadorComQoS::RoteadorComQoS(int endereco) : Roteador(endereco, new FilaComPrioridade(TAMANHO_FILA)){
    destinosPriorizados = new vector<int>();

}

RoteadorComQoS::~RoteadorComQoS(){
    delete destinosPriorizados;
}

void RoteadorComQoS::priorizar(int destino){
    destinosPriorizados->push_back(destino);
}

vector<int>* RoteadorComQoS::getDestinosPriorizados(){
    return destinosPriorizados;
}

void RoteadorComQoS::receber(Datagrama* d){
    bool prioridade = false;

    for (unsigned i = 0; i < destinosPriorizados->size() && !prioridade; i++){
        if (destinosPriorizados->at(i) == d->getDestino())
            prioridade = true;
    }

    try {
        FilaComPrioridade* filaComPrioridade= dynamic_cast<FilaComPrioridade*>(fila);
        filaComPrioridade->enqueue(d, prioridade);
    }
    catch(overflow_error *e){
        cout << "\tFila em " << endereco << " estourou" << endl;
        delete e;
    }

}
