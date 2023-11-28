#include <iostream>
#include "ModuloEmParalelo.h"
#include "Somador.h"
using namespace std;

ModuloEmParalelo::ModuloEmParalelo(): Modulo(){

}

ModuloEmParalelo::~ModuloEmParalelo(){
    delete listaCircuitosSISO;
}


Sinal* ModuloEmParalelo::processar(Sinal* sinalIN){
    Sinal* sinal = sinalIN;
    if (listaCircuitosSISO -> size() == 0){
        throw new logic_error("Mensagem de erro");
    }
    else{
        list<CircuitoSISO*>::iterator i;
        Somador* somadorInterno = new Somador();
        while (i != listaCircuitosSISO->end()) {
            sinal = somadorInterno -> processar(sinal,(*i) -> processar(sinal));
            i++;
        }
    }
    return sinal;
};