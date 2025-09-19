#include "Roteador.h"

Roteador::Roteador(int endereco) : No(endereco) {
    TabelaDeRepasse* t = new TabelaDeRepasse(TAMANHO_TABELA);
    tabela = t;
}

Roteador::Roteador(int endereco, Fila* fila) : No(endereco, fila) {
    TabelaDeRepasse* t = new TabelaDeRepasse(TAMANHO_TABELA);
    tabela = t;
}

Roteador::~Roteador(){
    delete tabela;
}

void Roteador::mapear(int endereco, No* adjacente, int atraso){
    tabela->mapear(endereco,adjacente,atraso);
}

void Roteador::setPadrao(No* padrao, int atraso){
    tabela->setPadrao(padrao,atraso);
}

Evento* Roteador::processar(int instante){

    if(fila->isEmpty()){
        return NULL;
    }

    else{

        cout << "Roteador " << endereco << endl;
        Datagrama* d = fila->dequeue();

        if(d->getDestino() == endereco){
            cout << "\tRecebido: " << d->getSegmento()->getDado() << endl;
            delete d;
            return NULL;
        }
        else{
            int atrasoProcessado = 0;

            No* no = tabela->getProximoSalto(d->getDestino(),atrasoProcessado);

            if(no == NULL){
                cout << "\tSem proximo: Origem: "<< d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem()
                << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << ", " << d->getSegmento()->getDado() << endl;
                delete d;
                return NULL;
            }
            else{
                cout << "\tRepassado para " << no->getEndereco()<< " (instante "<< (instante + atrasoProcessado) << "): Origem: " << d->getOrigem()
                << ":" << d->getSegmento()->getPortaDeOrigem() << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino()<< ", " << d->getSegmento()->getDado()<< endl;

                Evento* e = new Evento(instante + atrasoProcessado, no, d);
                return e;
            }
        }
    }
}
