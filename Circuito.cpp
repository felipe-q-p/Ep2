#include <iostream>
#include "Circuito.h"
using namespace std;

int Circuito::n = 0; 

Circuito::Circuito(){
    n++;
    ID = n;
}

Circuito::~Circuito(){

}

int Circuito::getUltimoID(){
    return n;
}

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID " << ID << endl;
}
