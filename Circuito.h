#ifndef CIRCUITO_H
#define CIRCUITO_H 
#include <iostream>
using namespace std;

class Circuito{
    public:
    Circuito();
    virtual ~Circuito()=0;
    int getID();
    void imprimir();
    static int getUltimoID();
    private:
    int ID;
    static int n;
};
#endif