#include <iostream>
#include "Modulo.h"
#include <list>
using namespace std;

Modulo::Modulo(): CircuitoSISO(){
    listaCircuitos = new list<CircuitoSISO*>;
}

Modulo::~Modulo(){
    delete listaCircuitos;
}

void Modulo::adicionar(CircuitoSISO* circ){
    listaCircuitos -> push_back(circ);
}

list <CircuitoSISO*>* Modulo::getCircuitos(){
    return listaCircuitos;
}

void Modulo::imprimir(){
    cout << "Modulo com ID " << getID() << "e:" <<endl;
    list<CircuitoSISO*>::iterator i;
    while (i != listaCircuitos->end()) {
        cout << "Circuito com ID " << (*i) -> getID() << endl;
        i++;
    }
}

