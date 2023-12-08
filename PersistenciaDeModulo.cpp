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
#include <vector>

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


/*void PersistenciaDeModulo::lerRecursiva(string nomeDoArquivo, Modulo* modulo){ 
    ifstream input;
    input.open(nomeDoArquivo);
    if (input.fail())
    {
        throw new invalid_argument("Nao foi possivel abrir o arquivo");
    }

    string l;
    input >> l;
    double d;
    

    while (!input.eof()){   
        
        if (l == "S"){
            moduloTemp1 = new ModuloEmSerie();
            modulo -> adicionar(moduloTemp1);
            lerRecursiva(nomeDoArquivo, moduloTemp1);
        }
        if (l == "P"){
            moduloTemp1 = new ModuloEmParalelo();
            modulo -> adicionar(moduloTemp1);
            lerRecursiva(nomeDoArquivo, moduloTemp1);
        }
        if (l == "R"){
            moduloTemp1 = new ModuloRealimentado();
            modulo -> adicionar(moduloTemp1);
            lerRecursiva(nomeDoArquivo, moduloTemp1);
        }



        if (l == "A"){
            input >> d;
            operacaoTemp = new Amplificador(d);
            modulo -> adicionar(operacaoTemp);
        }
        if (l == "I"){
            operacaoTemp = new Integrador();
            modulo -> adicionar(operacaoTemp);
        }
        if (l == "D"){
            operacaoTemp = new Derivador();
            modulo -> adicionar(operacaoTemp);
        }
        if(l == "f"){
            break;
        }
    }
}


Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream input;
    input.open(nomeDoArquivo);
    if (input.fail())
    {
        throw new invalid_argument("Nao foi possivel abrir o arquivo");
    }   

    
    vector<Modulo*>* vetorModulos = new vector<Modulo*>();

    string l;
    input >> l;
    if (l == "S"){
        moduloPrincipal = new ModuloEmSerie();
        lerRecursiva(nomeDoArquivo, moduloPrincipal);
    }
    if (l == "P"){
        moduloTemp1 = new ModuloEmParalelo();
        vetorModulos -> push_back(moduloTemp1);
        lerRecursiva(nomeDoArquivo, moduloTemp1);
    }
    if (l == "R"){
        moduloTemp1 = new ModuloRealimentado();
        vetorModulos -> push_back(moduloTemp1);
        lerRecursiva(nomeDoArquivo, moduloTemp1);
    }


}


*/

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream input;
    input.open(nomeDoArquivo);
    
    string l;

    if (input.fail())
    {
        throw new invalid_argument("Nao foi possivel abrir o arquivo");
    }   

    vector<Modulo*>* vetorModulos = new vector<Modulo*>();

    int i = -1;
    double d;

    input >> l;
    while (input){   
        
        if (l == "S"){
            ModuloEmSerie *modulo = new ModuloEmSerie();
            if (i == -1){
                moduloPrincipal = modulo;
            }
            cout <<"S" << endl;
            if(i != -1)
            {
                vetorModulos->at(i)->adicionar(modulo);
            }
            vetorModulos->push_back(modulo);
            i++;
        }
        if (l == "P"){
            ModuloEmParalelo *modulo = new ModuloEmParalelo();
            if (i == -1){
                moduloPrincipal = modulo;
            }
            cout <<"P" << endl;
            if(i != -1)
            {
                vetorModulos->at(i)->adicionar(modulo);
            }
            vetorModulos->push_back(modulo);
            i++;
        }
        if (l == "R"){
            ModuloRealimentado *modulo = new ModuloRealimentado();
            if (i == -1){
                moduloPrincipal = modulo;
            }
            cout <<"R" << endl;
            if(i != -1)
            {
                vetorModulos->at(i)->adicionar(modulo);
            }
            vetorModulos->push_back(modulo);
            i++;
        }
        if (l == "A"){
            input >> d;
            vetorModulos->at(i)->adicionar(new Amplificador(d));
            cout <<"A" << endl;
        }
        if (l == "I"){
            vetorModulos->at(i)->adicionar(new Integrador());
            cout <<"I" << endl;
        }
        if (l == "D"){
            vetorModulos->at(i)->adicionar(new Derivador());
            cout <<"D" << endl;
        }
        if(l == "f"){
            cout <<"f" << endl;
            i--;
        }
        input >> l;
    }
    return moduloPrincipal;
}