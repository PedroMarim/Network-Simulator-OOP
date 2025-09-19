#include "Hospedeiro.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway, int atraso) : No(endereco){
    this->gateway = gateway;
    this->atraso = atraso;
    chats = new vector<Chat*>();
}

Hospedeiro::~Hospedeiro(){
    for(unsigned i = 0; i < chats->size(); i++)
        delete chats->at(i);
    delete chats;
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino){
    if(getChat(porta) != NULL){
        throw new logic_error("");
    }
    else{
        Chat* c = new Chat(this, porta, enderecoDestino, portaDestino);
        chats->push_back(c);
    }
}

vector<Chat*>* Hospedeiro::getChats(){
    return chats;
}

Chat* Hospedeiro::getChat(int porta){
    for(unsigned i = 0; i < chats->size(); i++){
        if (chats->at(i)->getPorta() == porta )
            return chats->at(i);
    }
    return NULL;
}

Evento* Hospedeiro::processar(int instante){

    if(fila->isEmpty()){
        return NULL;
    }
    else{
        cout << "Hospedeiro " << endereco << endl;
        Datagrama* d = fila->dequeue();

        if(d->getDestino() == endereco){
            Chat* c = getChat(d->getSegmento()->getPortaDeDestino());

            if(c == NULL){
                cout << "\tSem chat:  Origem: "<< d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() << ", Destino: " << d->getDestino()
                << ":" << d->getSegmento()->getPortaDeDestino() << ", " << d->getSegmento()->getDado() << endl;
            }

            else{
                c->receber(d);
                cout << "\tMensagem recebida" << endl;
                cout << c->getTextoCompleto();
            }
            return NULL;
        }
        else{
            Evento* e = new Evento(instante + atraso, gateway, d);
            cout << "\tMensagem enviada" << endl;
            return e;
        }
    }
}
