#include "Chat.h"
#include <stdexcept>
#include <string>

Chat::Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino){
    if(h == NULL)
        throw new invalid_argument("");

    this->h = h;
    this->porta = porta;
    this->enderecoDestino = enderecoDestino;
    this->portaDestino = portaDestino;
}

Chat::~Chat(){
}

int Chat::getPorta(){
    return porta;
}

void Chat::enviar(string texto){
    Segmento* s = new Segmento(porta, portaDestino, texto);
    Datagrama* d = new Datagrama(h->getEndereco(), enderecoDestino, s);

    h->receber(d);

    textoCompleto += "\t\tEnviado: " + texto + "\n";
}

void Chat::receber(Datagrama* d){
    textoCompleto += "\t\tRecebido: " + d->getSegmento()->getDado() + "\n";

    delete d;
}

string Chat::getTextoCompleto(){
    return textoCompleto;
}

void Chat::imprimir(){
}
