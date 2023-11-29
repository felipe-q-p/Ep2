#ifndef PERSISTENCIADEMODULO_h
#define PERSISTENCIADEMODULO_h 

#include "Modulo.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class PersistenciaDeModulo{
    public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};
#endif