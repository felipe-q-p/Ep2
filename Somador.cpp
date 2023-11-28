#include <iostream> //
#include <string>
#include "Sinal.h"
#include "Somador.h"
#include "CircuitoMISO.h"

Somador::Somador():CircuitoMISO(){

};

Somador::~Somador(){

};

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    int menorComprimento = sinalIN1 -> getComprimento();
    if (sinalIN2 -> getComprimento() < menorComprimento){
        menorComprimento = sinalIN2 -> getComprimento();
    }
    double *sequenciaSoma = new double[menorComprimento];
    for (int i = 0; i < menorComprimento; i++){
        sequenciaSoma[i] = (sinalIN1 -> getSequencia())[i]+ (sinalIN2 -> getSequencia())[i];
    }
    Sinal* sinalSoma = new Sinal(sequenciaSoma, menorComprimento);
    return sinalSoma;
};