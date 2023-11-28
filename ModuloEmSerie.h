#ifndef MODULOEMSERIE_H 
#define MODULOEMSERIE_H

#include "Modulo.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class ModuloEmSerie: public Modulo{
    public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    Sinal* processar(Sinal*SinalIN);

};
#endif