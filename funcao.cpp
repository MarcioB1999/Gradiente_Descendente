#include <math.h>
#include <stdlib.h>
#include <iostream>
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


class Funcao{
    public:

    char *expressao;
    No *raiz;
    int n;

    public:
    Funcao(char *expr){
        raiz = NULL;
        expressao = expr;
    }


    double get_valor(double *vetor){
        if(raiz == NULL){
            raiz = (No*)malloc(sizeof(No*));
            interpretador(expressao,raiz);
        }
        
        return func(raiz, vetor);
    }

    private:
    double func(No *no, double *vetor){

        if(no->operacao == '-'){
            return func(no->prox_esq,vetor)-func(no->prox_dir,vetor);
        }
        if(no->operacao == '+'){
            return func(no->prox_esq,vetor)+func(no->prox_dir,vetor);
        }
        if(no->operacao == '/'){
            return func(no->prox_esq,vetor)/func(no->prox_dir,vetor);
        }
        if(no->operacao == '*'){
            return func(no->prox_esq,vetor)*func(no->prox_dir,vetor);
        }

        return vetor[stoi(&(no->operacao))];
    }

    //vai interpretar e criar a arvore da expressao
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

            no_anterior->prox_dir = (No*) malloc(sizeof(No));

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

};

