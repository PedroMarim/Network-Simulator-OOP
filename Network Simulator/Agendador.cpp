#include "Agendador.h"
#include <list>
#include <algorithm>

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho){
    this->instante = instanteInicial;
    this->rede = rede;
    this->tamanho = tamanho;
    eventosAgendados = new Evento*[tamanho];
}


Agendador::~Agendador(){

    for(int i = 0; i < quantidade; i++)
        delete eventosAgendados[i];

    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, No* n, Datagrama* d){

    if(quantidade < tamanho) {

        Evento* e = new Evento(instante, n, d);
        eventosAgendados[quantidade] = e;

        quantidade++;
        return true;
    }
    else
        return false;
}


void Agendador::processar() {

    for(int i = 0; i < quantidade; i++){
        if(eventosAgendados[i]->getInstante() <= instante){
            eventosAgendados[i]->getDestino()->receber(eventosAgendados[i]->getDatagrama());
            delete eventosAgendados[i];
            for(int j = i+1; j < quantidade; j++){
                eventosAgendados[j-1] = eventosAgendados[j];
            }
            quantidade--;
            i--;
        }
    }

    list<No*>::iterator i = rede->getNos()->begin();

    while(i != rede->getNos()->end()){
        Evento* e = (*i)->processar(instante);

        if(e!= NULL)
            agendar(e->getInstante(), e->getDestino(), e->getDatagrama());
        i++;
    }
    instante++;
}

int Agendador::getInstante(){
    return instante;
}
