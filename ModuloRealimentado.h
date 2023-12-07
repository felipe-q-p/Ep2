#ifndef MODULOREALIMENTADO_H 
#define MODULOREALIMENTADO_H 

#include "Modulo.h"
#include "ModuloEmSerie.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class ModuloRealimentado: public Modulo{
    public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal*SinalIN);    
    private:
    ModuloEmSerie* moduloInterno;

    
};
#endif