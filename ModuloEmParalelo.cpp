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
    if (listaCircuitosSISO -> size() == 0){
        throw new logic_error("Mensagem de erro");
    }
    else{
        double sequencia[60];
        for (int j = 0; j < 60; j++){
            sequencia[j]=0.0;
        }


        Sinal* sinal = new Sinal(sequencia, 60);
        list<CircuitoSISO*>::iterator i = listaCircuitosSISO -> begin();
        Somador* somadorInterno = new Somador();
        while (i != listaCircuitosSISO->end()) {
            sinal = somadorInterno -> processar(sinal,(*i) -> processar(sinalIN));
            i++;
        }
        return sinal;
    }
};