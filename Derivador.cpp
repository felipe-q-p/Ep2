#include <iostream>
#include <string>
#include "Grafico.h"
#include "Derivador.h"

Derivador::Derivador() : CircuitoSISO() {

};

Derivador::~Derivador(){

}

Sinal* Derivador::processar(Sinal* sinalIN){
    double* sequenciaDer = new double[sinalIN->getComprimento()];
    sequenciaDer[0] = sinalIN->getSequencia()[0];
    for (int i = 1;  i < sinalIN->getComprimento(); i++){
        sequenciaDer[i] = (sinalIN->getSequencia()[i] - sinalIN->getSequencia()[i-1]);
    }
    Sinal* sinalDerivada = new Sinal(sequenciaDer, sinalIN -> getComprimento());
    return sinalDerivada;
};