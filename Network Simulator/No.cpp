#include "No.h"

No::No(int endereco) {
    this->endereco = endereco;
    fila = new Fila(TAMANHO_FILA);
}

No::No(int endereco, Fila* fila){
    this->endereco = endereco;
    this->fila = fila;
}

No::~No(){
    delete fila;
}

int No::getEndereco() {
    return endereco;
}

/*
Evento* No::processar(int instante)
{

}
*/

void No::receber(Datagrama* d){
    try {
        fila->enqueue(d);
    }
    catch(overflow_error *e){
        cout << "\tFila em " << endereco << " estourou" << endl;
        cout<<"No elementos fila: "<<fila->getSize()<<endl;
        delete d;
        delete e;
    }
}

void No::imprimir(){
}
