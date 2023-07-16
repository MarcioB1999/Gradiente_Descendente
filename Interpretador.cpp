#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

/*
Tudo parece esta indo MT bem, contudo, n consegue manter os ponteiros apontados para os lugares corretos
Pois como não estava imaginando no começo, por n programar em c++ a mt tempo, ao sair da funcao e ele desalocar
as memorias das variaveis criadas por ela, os ponteiros apontados antes mudam
*/

struct No{
    char operacao;
    No *prox_dir;
    No *prox_esq;

    No(){
        prox_dir = NULL;
        prox_esq = NULL;
    }
};


struct funcao{

    double *var;
    int n;

    funcao(){
        var = NULL;
        n = 0;
    }

    void vetorVar(int size){
        var = (double*) malloc(size*sizeof(double));
        n = size;
    }

    double func(No *no){
 
        if(no->operacao == '-'){
            return func(no->prox_esq)-func(no->prox_dir);
        }
        if(no->operacao == '+'){
            return func(no->prox_esq)+func(no->prox_dir);
        }
        if(no->operacao == '/'){
            return func(no->prox_esq)/func(no->prox_dir);
        }
        if(no->operacao == '*'){
            return func(no->prox_esq)*func(no->prox_dir);
        }

        return var[stoi(&(no->operacao))];
    }
};




char* interpretador(char *expr, No *no_anterior){
    cout<<"no pai = "<<no_anterior<<"\n";
    char *string_back_esq;
    char *string_back_dir;
    //lado esquerdo
    if(expr[0] == '('){
        //verificando se o caractere de agora associado ao no_anterior
        //é o começo de uma expressão ou apenas uma base,
        //caso seja, necessita dois filhos

        //cout<<"lado esquerdo \n";
        No no_esq;
        no_anterior->prox_esq = &no_esq;
        cout<<"no esquerdo e = "<<&no_esq<<"\n";
        cout<<"filho esquerdo do pai "<<no_anterior<<" e = "<<no_anterior->prox_esq<<"\n";


        char *prox_expr = &expr[1];
        

        string_back_esq = interpretador(prox_expr,&no_esq);
        no_anterior->operacao = string_back_esq[0];
        /*
        indo pro lado direito da expressão
        */

        No no_dir;
        no_anterior->prox_dir = &no_dir;

        /*
        voltou assim +b)+z) contudo pego apenas b)+z)
        pois estou tirando a operação da propria recursao
        */
        char *string_dir = &string_back_esq[1];
    
        string_back_dir = interpretador(string_dir,&no_dir);


        return &string_back_dir[1];

    }else{
        //caso base
        cout<<"caso base \n";
        no_anterior->operacao = expr[0];


        return &expr[1];
    }
    
}



int main(){

    
    char *expressao = "(x+y)";
    No raiz;
   

    if(*interpretador(expressao,&raiz)=='\0'){
        cout<<"deu certo, eu acho \n";
    }

    funcao func;
    func.vetorVar(2);
    func.var[0] = 1;


    //cout<<"valor inicial ="<<func.func(&raiz)<<"\n";
    
    return 0;
}



