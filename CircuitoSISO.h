#ifndef CircuitoSISO_H
#define CircuitoSISO_H
#include <iostream>
#include "Sinal.h"
#include "Circuito.h"
#include <string>
using namespace std;

class CircuitoSISO : public Circuito{
    public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* sinalIN) = 0; // abstrato
};

#endif