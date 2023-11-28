#include <iostream>
#include "Circuito.h"
using namespace std;

Circuito::Circuito(){
    static int n = 0;
    ID = n;
}

Circuito::~Circuito(){

}

int Circuito::getUltimoID(){
/*????*/
}

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID " << getID() << endl;
}
