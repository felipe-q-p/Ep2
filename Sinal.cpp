#include <iostream>
#include <string>
#include "Sinal.h"
#include "Grafico.h"

Sinal::Sinal(double *sequencia, int comprimento){
    this -> comprimento = comprimento;
    if (comprimento > 0){
        this -> sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            this ->sequencia[i] = sequencia[i];
        }
    }
    else{
        throw new invalid_argument("Mensagem de erro");
    }
    
}

Sinal::Sinal(double constante, int comprimento){
    if (comprimento > 0){
        sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            sequencia[i] = constante;
        }
    }
    else{
        throw new invalid_argument("Mensagem de erro");
    }
}

Sinal::~Sinal(){
    delete[] sequencia;
}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){
    Grafico *grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico -> plot();
}

void Sinal::imprimir(){
    for (int i = 0; i<comprimento; i++){
        cout << i << "- " << sequencia[i]<< endl;
    }
    cout <<"--"<< endl;
}

void Sinal::imprimir(int tamanho){
    if (comprimento < tamanho){
        for (int i = 0; i < comprimento; i++) {
            cout << i << "- "<< this->sequencia[i] << endl;
    }    
}
    else {
        for (int i = 0; i < tamanho; i++) {
            cout << i << "- "<< this->sequencia[i] << endl;
        }
    }
cout << "--"<< endl;
}