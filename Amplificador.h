#ifndef AMPLIFICADOR_H //
#define AMPLIFICADOR_H

#include "CircuitoMISO.h"
#include <iostream>
#include <string>
#include "Sinal.h"
using namespace std;

 
class Amplificador : CircuitoSISO  {
    public: 
    Amplificador(double ganho);
    virtual ~Amplificador();
    Sinal* processar(Sinal* sinalIN);
    void setGanho(double ganho);
    double getGanho();

    private:
    double ganho;
};
#endif