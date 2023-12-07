#include "Sinal.h"
#include "Derivador.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Circuito.h"
#include "CircuitoMISO.h"
#include "CircuitoSISO.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "PersistenciaDeModulo.h" 


#include <iostream>

void teste1(){
    double* sequencia = new double[3];
    sequencia[0] = 2.3;
    sequencia[1] = 3.5;
    sequencia[2] = 5.7;
    Sinal* sinal = new Sinal(sequencia, 3);
    ModuloEmSerie* um = new ModuloEmSerie();
    Amplificador* amp = new Amplificador(1.2);
    um -> adicionar(amp);
    amp -> processar(sinal);
}