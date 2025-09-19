#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "Chat.h"
#include "Roteador.h"
#include "No.h"
#include <vector>

class Chat;

class Hospedeiro: public No {
public:
    Hospedeiro(int endereco, Roteador* gateway, int atraso);
    virtual ~Hospedeiro();

    virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
    virtual vector<Chat*>* getChats();
    virtual Chat* getChat(int porta);

    virtual Evento* processar(int instante);

protected:

private:
    vector<Chat*>* chats;

    Roteador* gateway;
    int atraso;

};

#endif // HOSPEDEIRO_H
