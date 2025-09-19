#include "Agendador.h"
#include "Chat.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Fila.h"
#include "FilaComPrioridade.h"
#include "Hospedeiro.h"
#include "No.h"
#include "PersistenciaDeRede.h"
#include "Rede.h"
#include "Roteador.h"
#include "RoteadorComQoS.h"
#include "Segmento.h"
#include "TabelaDeRepasse.h"


#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main()
{

    string arquivo;
    int instante;

    cout << "Nome do arquivo: ";
    cin >> arquivo;
    cout << "Instante inicial: ";
    cin >> instante;
    cout << "" << endl;
    PersistenciaDeRede* p= new PersistenciaDeRede(arquivo);


    try{
    Rede* rede= p->carregar();
    Agendador* a = new Agendador(instante, rede, 10);
    int tarefa = 3;

    while(tarefa != 0){

        if(tarefa == 1){
            string mensagem;

            list<Hospedeiro*>::iterator iterador= rede->getHospedeiros()->begin();

            for(unsigned i=0; i < rede->getHospedeiros()->size(); i++){
                cout << "Hospedeiro: "<< (*iterador)->getEndereco() << endl;/////////////////////PRINTANDO HOSPEDEIROS E CHATS

                for(unsigned l=0; l < (*iterador)->getChats()->size(); l++){
                    cout<<"\tChat: "<< (*iterador)->getChats()->at(l)->getPorta()<<endl;
                }
                iterador++;
            }

            int endereco;
            int porta;

            cout << "Endereco do hospedeiro: ";
            cin >> endereco;

            cout << "Porta do chat: ";
            cin >> porta;

            Hospedeiro* hospedeiroTemporario = dynamic_cast<Hospedeiro*>(rede->getNo(endereco));

            if(hospedeiroTemporario == NULL || hospedeiroTemporario->getChat(porta) == NULL){
                cout << "" << endl;
                cout << "Erro: origem desconhecida" << endl;
                cout << "" << endl;
            }
            else{
                cout << "Conteudo: " << endl;


                cout << (hospedeiroTemporario)->getChat(porta)->getTextoCompleto() << endl;
                cout << "Mensagem: ";
                cin >> mensagem;
                cout << "" << endl;

                hospedeiroTemporario->getChat(porta)->enviar(mensagem);

            }
        }
        if(tarefa == 2){

            int tempo = 1;
            int n;

            cout << "Quantidade de tempo: ";
            cin >> n;
            cout << "" << endl;

            for(tempo = 1; tempo <= n; tempo++){
                cout << "Instante " << a->getInstante() << endl;
                cout << "---" << endl;

                a->processar();
                cout << "" << endl;
            }
        }
        cout << "Simulador de Rede" << endl;
        cout << "1) Enviar um datagrama" << endl;
        cout << "2) Passar tempo" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";

        cin >> tarefa;

        cout << "" << endl;
    }

    delete rede;
    delete a;
    return 0;

    }catch (exception* e){
        cout<<"Excecao: "<< e->what()<<endl;
        delete e;
    }

}

