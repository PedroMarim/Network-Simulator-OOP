#include "Rede.h"
#include <algorithm>

Rede::Rede() {
    nos = new list<No*>();
    hospedeiros = new list<Hospedeiro*>();
}

Rede::~Rede() {
    list<No*>::iterator i = nos->begin();

    while(i != nos->end()){
        delete (*i);
        i++;
    }

    delete nos;
}

void Rede::adicionar(No* n) {
    list<No*>::iterator i = nos->begin();

    while(i != nos->end()){
        if(n->getEndereco() == (*i)->getEndereco())
            throw new logic_error("");
        i++;
    }
    nos->push_back(n);
}

No* Rede::getNo(int endereco) {
    list<No*>::iterator i = nos->begin();

    while(i != nos->end()){
        if(endereco == (*i)->getEndereco())
            return (*i);
        i++;
    }
    return NULL;
}

list<No*>* Rede::getNos(){
    return nos;
}

list<Hospedeiro*>* Rede::getHospedeiros(){
    hospedeiros = new list<Hospedeiro*>();

    list<No*>::iterator i = nos->begin();

    while(i != nos->end()){
        Hospedeiro* h = dynamic_cast<Hospedeiro*>((*i));
        if(h != NULL)
            hospedeiros->push_back(h);
        i++;
    }
    return hospedeiros;
}

void Rede::imprimir() {
}

