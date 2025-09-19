#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Rede.h"

using namespace std;


class PersistenciaDeRede
{
    public:
        PersistenciaDeRede(string);
        virtual ~PersistenciaDeRede();

        Rede* carregar();

    private:

        string arquivo;
};
#endif // PERSISTENCIADEREDE_H
