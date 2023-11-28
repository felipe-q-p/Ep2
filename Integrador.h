#ifndef INTEGRADOR_H 
#define INTEGRADOR_H 


#include "Sinal.h"
#include "CircuitoSISO.h"
#include <iostream>
#include <string>
using namespace std;

class Integrador : CircuitoSISO {
    public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN1);
};


#endif