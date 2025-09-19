#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, Segmento* dado) {
    this->origem = origem;
    this->destino = destino;
    this->segmento = dado;
}
Datagrama::~Datagrama() {
    delete segmento;
}

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

Segmento* Datagrama::getSegmento() {
    return segmento;
}

void Datagrama::imprimir() {
}
