#include "Sinal.h"
#include "Derivador.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Integrador.h"

#include "ModuloRealimentado.h"
#include "Circuito.h"
#include "CircuitoMISO.h"
#include "CircuitoSISO.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "PersistenciaDeModulo.h" 


#include <iostream>

using namespace std;

void teste() {
    double* sequencia = new double[3];
    sequencia[0] = 2.3;
    sequencia[1] = 3.5;
    sequencia[2] = 5.7;
    Sinal* sinal = new Sinal(sequencia, 3);

    cout << "Teste: Imprime sequencia do sinal criado" << endl;

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    delete[] sequencia;
    delete sinal;
}

void testeAmplificador() {
    double* sequencia = new double[3];
    sequencia[0] = 1;
    sequencia[1] = 2;
    sequencia[2] = 7;
    Sinal* sinal = new Sinal(sequencia, 3);

    cout << "Teste: Imprime sequencia do sinal criado" << endl;

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    cout << "Teste: Imprime sequencia apos uso do amplificador" << endl;

    Amplificador* amplificador = new Amplificador(1.1);

    sinal = amplificador->processar(sinal);

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    sinal->imprimir("Grafico pos amplificador 1.1");
    
    delete[] sequencia;
    delete sinal;
    delete amplificador;
}

void testeDerivador() {
    double* sequencia = new double[3];
    sequencia[0] = 2.3;
    sequencia[1] = 3.5;
    sequencia[2] = 5.7;
    Sinal* sinal = new Sinal(sequencia, 3);

    cout << "Teste: Imprime sequencia do sinal criado" << endl;

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    cout << "Teste: Imprime sequencia apos uso do derivador" << endl;

    Derivador* derivador = new Derivador();

    sinal = derivador->processar(sinal);

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    sinal->imprimir("Grafico derivado");
    
    delete[] sequencia;
    delete sinal;
    delete derivador;
}

void testeSomador() {
    double* sequencia = new double[3]; // Cria Sinal 1
    sequencia[0] = 1.0;
    sequencia[1] = 2.5489584758;
    sequencia [2] = 3.0;
    Sinal* sinal = new Sinal(sequencia, 3);

    double* sequencia2 = new double[3]; // Cria Sinal 2
    sequencia2[0] = 1.7;
    sequencia2[1] = 4.5489584758;
    Sinal* sinal2 = new Sinal(sequencia2, 2);

    Somador* somador = new Somador();

    sinal = somador->processar(sinal, sinal2);

    cout << "Teste: Imprime sequencia do sinal criado" << endl;

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    delete[] sequencia;
    delete sinal;
    delete somador;
}

void testeIntegrador() {
    double* sequencia = new double[3];
    sequencia[0] = 2.3;
    sequencia[1] = 3.5;
    sequencia[2] = 5.7;
    Sinal* sinal = new Sinal(sequencia, 3);

    cout << "Teste: Imprime sequencia do sinal criado" << endl;

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    cout << "Teste: Imprime sequencia apos uso do integrador" << endl;

    Integrador* integrador = new Integrador();

    sinal = integrador->processar(sinal);

    for(int i=0; i<sinal->getComprimento(); i++) {
        cout << sinal->getSequencia()[i] << endl;
    }

    sinal->imprimir("Gráfico derivado");
    
    delete[] sequencia;
    delete sinal;
    delete integrador;
}

void testeGrafico() {
    double* sequencia = new double[15];
    for(int i=0; i<15; i++) {
        sequencia[i] = (i+5.0) / 2;
    }
    Sinal* sinal = new Sinal(sequencia, 15);

    sinal->imprimir("Sinal puro");

    delete[] sequencia;
    delete sinal;
}




/* void testeModuloRealimentado() {
    int comprimento = 20;
    double* sequencia = new double[comprimento];
    for(int i=0; i<comprimento; i++) {
        sequencia[i] = 10.0;
    }
    Sinal* sinal = new Sinal(sequencia, comprimento);

    ModuloRealimentado* modulo = new ModuloRealimentado();

    sinal = modulo->processar(sinal);

    sinal->imprimir("sinal");

    delete[] sequencia;
    delete sinal;
    delete modulo;
}*/

void testeCircuito() {
    Derivador* circuito1 = new Derivador();
    Integrador* integrador = new Integrador();
    cout << "ID do circuito1: " << circuito1->getID() << endl;
    cout << "ID do circuito2: " << integrador->getID() << endl;
}

void testeModuloEmSerie() {
    double* sequencia = new double[3];
    sequencia[0] = 2.3;
    sequencia[1] = 3.5;
    sequencia[2] = 5.7;
    Sinal* sinal = new Sinal(sequencia, 3);
    ModuloEmSerie* um = new ModuloEmSerie();
    Amplificador* amp = new Amplificador(1.2);
    um->adicionar(amp);
}

void testeModuloEmParalelo() {

}

void testePers1() {
    Modulo* m = new ModuloEmSerie();
    Modulo* m1 = new ModuloEmParalelo();
    Derivador* d = new Derivador();
    Integrador* i = new Integrador();
    Amplificador* a = new Amplificador(0.2);
    Amplificador* a2 = new Amplificador(0.3);
    m1->adicionar(m);

    m1->adicionar(d);
    m1->adicionar(i);

    m->adicionar(a);
    m->adicionar(d);
    m->adicionar(i);
    m->adicionar(a2);

    PersistenciaDeModulo* p = new PersistenciaDeModulo("texto1.txt");
    p->salvarEmArquivo(m1);

}

void testePers2() {
    /*try {*/
    PersistenciaDeModulo* p = new PersistenciaDeModulo("texto.txt");
    cout << "aaaaaaaa" << endl;
    Modulo* m = p->lerDeArquivo();
    
    /*list<CircuitoSISO*>* listar = m->getCircuitos();
    list<CircuitoSISO*>::iterator i = listar->begin();
    while (i != listar->end()) {
        cout  << (*i)->qualCircuito() << endl;
        i++;
    }
    } catch (invalid_argument *e) {
        cout << e->what() << endl;
        delete e;
    } catch (logic_error *e) {
        cout << e->what() << endl;
        delete e;
    }*/

}