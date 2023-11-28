#include <iostream>
#include "ModuloEmSerie.h"
using namespace std;

ModuloEmSerie::ModuloEmSerie(): Modulo(){

}

ModuloEmSerie::~ModuloEmSerie(){
    delete listaCircuitosSISO;
}


Sinal* ModuloEmSerie::processar(Sinal* sinalIN){
    Sinal* sinal = sinalIN;
    if (listaCircuitosSISO -> size() == 0){
        throw new logic_error("Mensagem de erro");
    }
    else{
    list<CircuitoSISO*>::iterator i;
    while (i != listaCircuitosSISO->end()) {
        sinal = (*i) -> processar(sinal);
        i++;
    }
    }
    return sinal;
}