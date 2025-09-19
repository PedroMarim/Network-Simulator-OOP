#include "PersistenciaDeRede.h"

#include <stdexcept>
#include "Roteador.h"
#include "RoteadorComQoS.h"

PersistenciaDeRede::PersistenciaDeRede(string arquivo){
    this->arquivo=arquivo;
}

PersistenciaDeRede::~PersistenciaDeRede(){
}

Rede* PersistenciaDeRede::carregar(){
    Rede* rede= new Rede();

    int quantidadeDeRoteadores;
    int quantidadeDeHospedeiros;

    ifstream redePersistida;
    redePersistida.open(arquivo);

    if(redePersistida.fail()){
        throw new logic_error("Falha ao abrir o arquivo");
    }

    redePersistida >> quantidadeDeRoteadores;

    if(redePersistida.eof()){
        throw new logic_error("Erro de formatacao");
    }

    for(int i = 0; i < quantidadeDeRoteadores; i++){

        string tipoDoRoteador;
        int endereco;

        redePersistida >> tipoDoRoteador;

        if(tipoDoRoteador == "r"){
            redePersistida >> endereco;
            Roteador* r = new Roteador(endereco);
            rede->adicionar(r);
        }

        if(tipoDoRoteador == "q"){
            redePersistida >> endereco;
            RoteadorComQoS* rq = new RoteadorComQoS(endereco);

            int quantidadeDePrioridades;
            redePersistida >> quantidadeDePrioridades;

            for(int l=0; l < quantidadeDePrioridades; l++){
                int prioridade;
                redePersistida >> prioridade;
                rq->priorizar(prioridade);
            }
            rede->adicionar(rq);
        }
    }

    redePersistida >> quantidadeDeHospedeiros;

    for(int i=0; i < quantidadeDeHospedeiros; i++){
        int endereco;
        int gateway;
        int atraso;
        int quantidadeDeChats;

        redePersistida >> endereco;
        redePersistida >> gateway;
        redePersistida >> atraso;

        Roteador* temporario = dynamic_cast<Roteador*>(rede->getNo(gateway));

        Hospedeiro* h = new Hospedeiro(endereco,temporario,atraso);
        rede->adicionar(h);

        redePersistida >> quantidadeDeChats;

        for(int l=0; l < quantidadeDeChats; l++){
            int porta;
            int enderecoDeDestino;
            int portaDeDestino;

            redePersistida >> porta;
            redePersistida >> enderecoDeDestino;
            redePersistida >> portaDeDestino;

            h->adicionarChat(porta, enderecoDeDestino, portaDeDestino);

        }
    }

    for(int i=0; i < quantidadeDeRoteadores; i++){
        int roteador;
        int roteadorPadrao;
        int atrasoPadrao;
        int quantidadeDeMapeamentos;

        redePersistida >> roteador;
        redePersistida >> roteadorPadrao;
        redePersistida >> atrasoPadrao;

        Roteador* rotTemporario = dynamic_cast<Roteador*>(rede->getNo(roteador));
        Roteador* padraoTemporario = dynamic_cast<Roteador*>(rede->getNo(roteadorPadrao));

        if(rotTemporario && padraoTemporario)
            rotTemporario->setPadrao(padraoTemporario,atrasoPadrao);

        redePersistida >> quantidadeDeMapeamentos;

        for(int l = 0; l < quantidadeDeMapeamentos; l++){
            int enderecoDeDestino;
            int enderecoAdjacente;
            int atraso;

            redePersistida >> enderecoDeDestino;
            redePersistida >> enderecoAdjacente;
            redePersistida >> atraso;

            Roteador* temporario = dynamic_cast<Roteador*>(rede->getNo(roteador));
            temporario->mapear(enderecoDeDestino,rede->getNo(enderecoAdjacente),atraso);

        }
    }

    string fim;
    redePersistida >> fim;

    if(!redePersistida.eof()){
        throw new logic_error("Formatacao incorreta");
    }

    redePersistida.close();
    return rede;
}
