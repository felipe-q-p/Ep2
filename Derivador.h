#ifndef DERIVADOR_H //
#define DERIVADOR_H


#include "Sinal.h"
#include "CircuitoSISO.h"
#include <iostream>
#include <string>
using namespace std;

class Derivador : public CircuitoSISO {
    public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN1);
};


#endif