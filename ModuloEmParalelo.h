#ifndef MODULOEMPARALELO_H 
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class ModuloEmParalelo: public Modulo{
    public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal* processar(Sinal*SinalIN);

};
#endif