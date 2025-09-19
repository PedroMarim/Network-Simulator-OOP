#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    if(tamanho <= 0)
        throw new invalid_argument("");

    No** n = new No* [tamanho];
    nosAdjacentes = n;
    atrasos = new int[tamanho];
    enderecos = new int[tamanho];
    atrasoPadrao = 0;
    noPadrao = NULL;
    quantidadeDeAdjacentes = 0;
    tamanhoMax = tamanho;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] nosAdjacentes;
    delete[] enderecos;
    delete[] atrasos;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidadeDeAdjacentes;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso){

    bool jaMapeado = false;
    for(int i = 0; i < quantidadeDeAdjacentes; i++){
        if(endereco == enderecos[i]){
            jaMapeado = true;
            throw new invalid_argument("");
        }
    }

    if(quantidadeDeAdjacentes == tamanhoMax)
        throw new overflow_error("");

    if(jaMapeado == false && quantidadeDeAdjacentes < tamanhoMax){
        enderecos[quantidadeDeAdjacentes] = endereco;
        nosAdjacentes[quantidadeDeAdjacentes] = adjacente;
        atrasos[quantidadeDeAdjacentes] = atraso;
        quantidadeDeAdjacentes++;
    }
}

No** TabelaDeRepasse::getAdjacentes(){
    return nosAdjacentes;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso){
    noPadrao = padrao;
    atrasoPadrao = atraso;
}

No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    No* n;
    int a;
    bool enderecoMapeado = false;
    int i;
    for(i = 0; i < quantidadeDeAdjacentes; i++){
        if(endereco == enderecos[i]){
            enderecoMapeado = true;
            n = nosAdjacentes[i];
            a = atrasos[i];
        }
    }
    if(enderecoMapeado == false){
        atraso = atrasoPadrao;
        return noPadrao;
    }
    else{
        atraso = a;
        return n;
    }
}

void TabelaDeRepasse::imprimir() {
}
