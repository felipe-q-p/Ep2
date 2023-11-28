#ifndef SOMADOR_H //
#define SOMADOR_H 

#include "Sinal.h"
#include "CircuitoMISO.h"
#include <string>
#include <iostream>
using namespace std;

class Somador : public CircuitoMISO {
    public:
        Somador();
        virtual ~Somador();
        Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif