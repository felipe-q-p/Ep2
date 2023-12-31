#ifndef MODULO_H 
#define MODULO_H

#include "CircuitoSISO.h"
#include <iostream>
#include <string>
#include "Sinal.h"
#include <list>
using namespace std;

class Modulo: public CircuitoSISO{
    public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
    void imprimir();
    protected:
    list<CircuitoSISO*>* listaCircuitosSISO;
};


#endif