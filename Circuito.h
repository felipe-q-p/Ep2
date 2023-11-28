#ifndef CIRCUITO_H
#include <iostream>
using namespace std;

class Circuito{
    public:
    Circuito();
    virtual ~Circuito();
    int getID();
    void imprimir();
    static int getUltimoID();
    private:
    int ID;
};
#endif