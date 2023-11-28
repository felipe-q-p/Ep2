#ifndef SINAL_H
#define SINAL_H
#include <iostream>
#include <string>
using namespace std;


class Sinal{
    public:
    Sinal(double *sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir(); // para testes
    void imprimir(int tamanho);

    private:
    double *sequencia;
    int comprimento;
};

#endif