#ifndef AGENDADOR_H
#define AGENDADOR_H

#include <iostream>
using namespace std;

#include "Rede.h"
#include "Evento.h"
#include "No.h"
#include "Datagrama.h"

class Agendador{
private:
    int instante;
    Rede* rede;
    int tamanho;
    Evento** eventosAgendados;
    int quantidade = 0;

public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    ~Agendador();

    bool agendar(int instante, No* n, Datagrama* d);
    void processar();
    int getInstante();
};

#endif // AGENDADOR_H
