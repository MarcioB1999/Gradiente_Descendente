#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;


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
    char *string_back_esq;
    char *string_back_dir;
    //lado esquerdo
    if(expr[0] == '('){
        //verificando se o caractere de agora associado ao no_anterior
        //é o começo de uma expressão ou apenas uma base,
        //caso seja, necessita dois filhos

        no_anterior->prox_esq = (No*) malloc(sizeof(No));


        char *prox_expr = &expr[1];
        

        string_back_esq = interpretador(prox_expr,no_anterior->prox_esq);
        no_anterior->operacao = string_back_esq[0];
        /*
        indo pro lado direito da expressão
        */

        no_anterior->prox_dir = (No*) malloc(sizeof(No));;

        /*
        voltou assim +b)+z) contudo pego apenas b)+z)
        pois estou tirando a operação da propria recursao
        */
        char *string_dir = &string_back_esq[1];
    
        string_back_dir = interpretador(string_dir,no_anterior->prox_dir);


        return &string_back_dir[1];

    }else{
        //caso base

        no_anterior->operacao = expr[0];


        return &expr[1];
    }
    
}



int main(){

    
    char *expressao = "(0*(1+2))";
    No raiz;
    interpretador(expressao,&raiz);
    funcao func;
    func.vetorVar(2);
    func.var[0] = 2;
    func.var[1] = 1;
    func.var[2] = 3;


    cout<<"valor da expressao ="<<func.func(&raiz)<<"\n";
    
    return 0;
}



