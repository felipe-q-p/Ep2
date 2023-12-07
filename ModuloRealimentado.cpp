#include <iostream>
#include "ModuloRealimentado.h"
#include "ModuloEmSerie.h"
#include "Somador.h"
using namespace std;

#define vInicial 0;

ModuloRealimentado::ModuloRealimentado(): Modulo(){
    moduloInterno = new ModuloEmSerie();
}

ModuloRealimentado::~ModuloRealimentado(){
    delete listaCircuitosSISO;
    delete moduloInterno;
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
    double *sequenciaSaidaInvertida = new double[sinalIN -> getComprimento()];
    sequenciaSaidaInvertida[0] = -vInicial;
    

    double *sequenciaDiferenca = new double[1]; 
    sequenciaDiferenca[0] = sinalIN->getSequencia()[0] + sequenciaSaidaInvertida[0];
    Sinal* diferenca = nullptr;
    diferenca = new Sinal(sequenciaDiferenca, 1);
    

    Sinal* saida = new Sinal(moduloInterno -> processar(diferenca) -> getSequencia(), 1); 
    delete diferenca;

    for (int i = 0; i < sinalIN -> getComprimento(); i++){
        sequenciaSaidaInvertida[i] = -(saida -> getSequencia()[i-1]);
        Sinal* saidaInvertida =  new Sinal(sequenciaSaidaInvertida, i+1);
        Somador* somador = new Somador();
        Sinal* diferenca = new Sinal((somador -> processar(sinalIN, saidaInvertida)) -> getSequencia(), i+1);
        delete saida;
        Sinal* saida = new Sinal(moduloInterno -> processar(diferenca) -> getSequencia(), i+1);
        delete somador;
        delete saidaInvertida;
        delete diferenca;

    }
    
    delete[] sequenciaSaidaInvertida;
    delete[] sequenciaDiferenca;
    return saida;

}


