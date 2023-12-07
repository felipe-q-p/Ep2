#include "PersistenciaDeModulo.h"
#include <iostream>
#include <fstream>
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "Amplificador.h"
#include <string>
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Derivador.h"
#include "Integrador.h"

using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this ->nomeDoArquivo = nomeDoArquivo;
}

PersistenciaDeModulo::~PersistenciaDeModulo(){

}

string PersistenciaDeModulo::identificarOperacao(CircuitoSISO* circuito){
    Derivador* der = dynamic_cast<Derivador*> (circuito);
    Integrador* inte = dynamic_cast<Integrador*> (circuito);
    Amplificador* amp = dynamic_cast<Amplificador*> (circuito);
     if (der != NULL){
        return "D";
    }
    if (inte != NULL){
        return "I";
    }
    if (amp != NULL){
        string stringAmp = "A " + to_string(amp -> getGanho());
        return stringAmp;
    }
    else{
        return NULL;
    }
}

string PersistenciaDeModulo::identificarModulo(CircuitoSISO* circuito){
    ModuloEmSerie* MeS = dynamic_cast<ModuloEmSerie*> (circuito);
    ModuloEmParalelo* MeP = dynamic_cast<ModuloEmParalelo*> (circuito);
    ModuloRealimentado* MeR = dynamic_cast<ModuloRealimentado*> (circuito);
    if (MeS != NULL){
        return "S";
    }
    if (MeP != NULL){
        return "P";
    }
    if (MeR != NULL){
        return "R";
    }
    else{
        return identificarOperacao(circuito);
    }
}
void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod){
    ofstream output;
    output.open(nomeDoArquivo, ios_base::app);
    output << identificarModulo(mod) << endl;
    list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin();
    while (i != mod->getCircuitos()->end()){
        if (identificarModulo(*i)=="S" || identificarModulo(*i) == "P" || identificarModulo(*i) == "R"){
            Modulo* circuitoParaModulo = dynamic_cast<Modulo*>(*i);
            output.close();
            salvarEmArquivo(circuitoParaModulo);
            output.open(nomeDoArquivo, ios_base::app);
            i++;
            output << identificarModulo(*i) << endl;
        }
        else{
            output << identificarModulo(*i) << endl;
        }
    i++;
    }
    output << "f" <<endl;
    output.close();
     
}

/*ModuloEmSerie* MeS = dynamic_cast<ModuloEmSerie*> (mod);
        ModuloEmParalelo* MeP = dynamic_cast<ModuloEmParalelo*> (mod);
        ModuloRealimentado* MeR = dynamic_cast<ModuloRealimentado*> (mod);
        while (MeS!=NULL || MeP!=NULL || MeR != NULL){
            if (MeS!=NULL){
                output << "S" <<endl;
                list<CircuitoSISO*>::iterator i;
                while (i != (MeS -> getCircuitos())->end()) {
                    Amplificador *amp = dynamic_cast<Amplificador*>(*i);
                    if (amp!=NULL){
                        output << "A" << endl;
                    }
                    Derivador *der = dynamic_cast<Derivador*>(*i);
                    if (der!=NULL){
                        output << "D" << endl;
                    }   
                    Integrador *inte = dynamic_cast<Integrador*>(*i);
                    if (inte!=NULL){
                        output << "I" << endl;    

                    }
                    

                }
            }
        }
}*/

void PersistenciaDeModulo::lerRecursiva(string nomeDoArquivo, Modulo* modulo){ 
    ifstream input;
    input.open(nomeDoArquivo, ios_base::app);
}


Modulo* PersistenciaDeModulo::lerDeArquivo(){
    
}