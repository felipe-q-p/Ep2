#include "Circuito.h"
#include "Amplificador.h"
#include "Sinal.h"
#include "Integrador.h"
#include "Somador.h"
#include "Derivador.h"
#include "ModuloRealimentado.h"
#include "math.h"
#include "CircuitoMISO.h"
#include "CircuitoSISO.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "PersistenciaDeModulo.h"

#include <string>
using namespace std;
#include <iostream>


int Simulink();
int qualEntrada();
double qualGanho();
int qualOperacao();
int oQueFazer();
Sinal* novoSinal();
CircuitoSISO* novaOperacao();
int querSalvar();
void SalvarCircuito();
string nomeDoArquivoEscrito();
string nomeDoArquivoLido();
void novaEstrutura(Sinal *sinalIN);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



void menu() {

    int i; // retorno do simulink
    double a; // ganho

    i = Simulink(); // faz a primeira pergunta



    // PRIMEIRA OPCAO DO SIMULINK (quando escolhe o piloto automatico)
    if (i == 1){
        Sinal* sinalIN = novoSinal();
        PersistenciaDeModulo* pers = new PersistenciaDeModulo(nomeDoArquivoLido());
        Modulo* moduloLido = pers -> lerDeArquivo();
        moduloLido -> imprimir();
        sinalIN = moduloLido -> processar(sinalIN);
        sinalIN -> imprimir("Resultado Final");
        if (querSalvar() == 1){
            PersistenciaDeModulo* pers2 = new PersistenciaDeModulo(nomeDoArquivoEscrito());
            pers2 -> salvarEmArquivo(moduloLido);
        }
        
    }


    // SEGUNDA OPCAO DO SIMULINK (quando escolhe as proprias opcoes)
    if (i == 2){

        /*
        cout<< endl;
        cout << "entrou certo"<< endl;
        */
        
        Sinal* sinalIN = novoSinal(); //cria um sinal de acordo com a preferencia (constante ou rampa etc) 
        novaEstrutura(sinalIN);
        delete(sinalIN);
    }

}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////




int Simulink(){
    int i; // inteiro para opçoes de simulação
    cout << "Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?" << endl;
    cout << "1) Circuito advindo de arquivo" << endl;
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: " ;

    cin >> i;
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int qualEntrada(){
    int j; // inteiro para opcoes de entrada
    

    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;
    cout << "Escolha: " ;

    cin >> j;
    return j;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int qualestrutura(){

    int estrutura; 
    cout << "Qual estrutura de operações voce deseja ter como base?" << endl;
    cout << "1) Operações em série não realimentadas" << endl;
    cout << "2) Operações em paralelo não realimentadas" << endl;
    cout << "3) Operações em série realimentadas" << endl;
    cout << "Escolha: " ;
    
    cin >> estrutura;
    return estrutura;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int qualOperacao(){

    int operacao; 
    cout << "Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl;
    cout << "2) Derivar" << endl;
    cout << "3) Integrar" << endl;
    cout << "Escolha: " ;
    
    cin >> operacao;
    return operacao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int oQueFazer(){

    int oQueFazer;
    cout << "O que voce quer fazer agora?" << endl;
    cout<< "1) Realizar mais uma operacao no resultado" << endl;
    cout << "2) Imprimir o resultado para terminar" << endl;
    cout << "Escolha: " ;
    
    cin >> oQueFazer;
    return oQueFazer;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sinal* novoSinal(){
    int i, j; // retornos do simulink e da entrada
    double a; // ganho

    j = qualEntrada();

        if (j == 1){
            
            double n = 0; // se necessario seu n
            cin >> n;

            double* sequencia = new double[60];
            for (int t=0; t<60; t++){
                sequencia[t] = 5+(3*cos(n*t*M_PI/8));
            }
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

           return  sinalIN;
        }



        if (j == 2){
            double C = 0; // se necessario é a contante 
            cout << "Qual o valor dessa constante?" << endl;
            cin >> C;
            // guardou a contante
            
            double* sequencia = new double[60];
            for (int t=0; t<60; t++){
                sequencia[t] = C;
            }
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

           return  sinalIN;
        }



        if (j == 3){
            double inc = 0; // se necessario é a inclinação
            cout << "Qual a inclinacao dessa rampa?" << endl;
            cin >> inc;
            // guardou a inclinacao

            double *sequencia = new double[60];
            for (int i = 0; i < 60; i++){
            sequencia[i] = sequencia[i-1] + inc;
        }
    
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

            return sinalIN;
        } 

        double* sequencia = new double[60]; // so pra ele nao dar warning (ele retorna um sinal zerado se nao escolherem nenhuma das 3 opcoes)
        for (int t=0; t<60; t++){
            sequencia[t] = 0;
        }
        Sinal* sinalIN = new Sinal(sequencia,60);
        return sinalIN;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

CircuitoSISO* novaOperacao(){
    int operacao; // qual operacao na simulacao do tipo 2
    double a; // ganho
    int Fazer; // como prosseguir depois de uma operacao efetuada

    operacao = qualOperacao();

    if (operacao == 1){
        a = qualGanho();
        Amplificador* amp = new Amplificador(a); // cria um aplificador para dazer a operacao
        return amp;
    }


    if (operacao == 2){
        Derivador* d = new Derivador();
        return d;
    }

    if (operacao == 3){
        Integrador* i = new Integrador();
        return i;
    }

    /*Fazer = oQueFazer(); // funcao para a pergunta final (fazer dnv ou terminar)

    if (Fazer == 1){
        novaOperacao(sinalIN);
    }

    if (Fazer == 2){
        sinalIN->imprimir("Resultado Final");
    }*/
}

void novaEstrutura(Sinal *sinalIN){
    int estrutura; // qual operacao na simulacao do tipo 2
    double a; // ganho
    int Fazer=1; // como prosseguir depois de uma operacao efetuada

    estrutura = qualestrutura();

    if (estrutura == 1){
        ModuloEmSerie* moduloEmSerie = new ModuloEmSerie();
        while (Fazer == 1){
        moduloEmSerie -> adicionar(novaOperacao());
        sinalIN = moduloEmSerie -> processar(sinalIN);
        Fazer = oQueFazer();
        }
    }

    if (estrutura == 2){
        ModuloEmParalelo* moduloEmParalelo = new ModuloEmParalelo();
        while (Fazer == 1){
        moduloEmParalelo -> adicionar(novaOperacao());
        sinalIN = moduloEmParalelo -> processar(sinalIN);
        Fazer = oQueFazer();
        }
    }

    if (estrutura == 3){
        
        ModuloRealimentado* moduloRealimentado = new ModuloRealimentado();
        while (Fazer == 1){
        moduloRealimentado -> adicionar(novaOperacao());
        sinalIN = moduloRealimentado -> processar(sinalIN);
        Fazer = oQueFazer();
        }   
    }

    


sinalIN->imprimir("Resultado Final");
}

double qualGanho(){
    double a; // double para ganho

    cout << "Qual o ganho do acelerador?" << endl;
    cin >> a;
    return a;
}

int querSalvar(){
    int querSalvar;
    cout << "Voce gostaria de salvar o circuito em um novo arquivo" << endl;
    cout<< "1) Sim" << endl;
    cout << "2) Não" << endl;
    cout << "Escolha: " ;
    
    cin >> querSalvar;
    return querSalvar;
}



string nomeDoArquivoEscrito(){
    string nomeDoArquivoEscrito;
    cout << "Qual nome do arquivo a ser escrito?" << endl;
    cout << "Nome: ";
    cin >> nomeDoArquivoEscrito;
    return nomeDoArquivoEscrito;
}

string nomeDoArquivoLido(){
    string nomeDoArquivoLido;
    cout << "Qual nome do arquivo a ser lido?" << endl;
    cout << "Nome: ";
    cin >> nomeDoArquivoLido;
    return nomeDoArquivoLido;
}

