#include <iostream>
#include "Modulo.h"
#include <list>
using namespace std;

Modulo::Modulo(): CircuitoSISO(){
    listaCircuitosSISO = new list<CircuitoSISO*>;
}

Modulo::~Modulo(){
    delete listaCircuitosSISO;
}

void Modulo::adicionar(CircuitoSISO* circ){
    listaCircuitosSISO -> push_back(circ);
}

list <CircuitoSISO*>* Modulo::getCircuitos(){
    return listaCircuitosSISO;
}

void Modulo::imprimir(){
    cout << "Modulo com ID " << getID() << "e:" <<endl;
    list<CircuitoSISO*>::iterator i;
    while (i != listaCircuitosSISO->end()) {
        cout << "Circuito com ID " << (*i) -> getID() << endl;
        i++;
    }
}
