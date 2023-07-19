#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include"funcoes_aux.cpp";
using namespace std;

class Funcao{
    public:
    No_lista *variaveis;
    char *expressao;
    No *raiz;

    public:
    Funcao(char *expr,No_lista *var=nullptr){
        variaveis = var;
        raiz = NULL;
        expressao = expr;
    }


    double get_valor(double *vetor = NULL){
        if(raiz == NULL){

            raiz = (No*)malloc(sizeof(No));
            interpretador(expressao,raiz);
        }
        
        return func(raiz, vetor);
    }

    private:
    double func(No *no, double *vetor){

        if(no->operacao[0] == '-'){
            return func(no->prox_esq,vetor)-func(no->prox_dir,vetor);
        }
        if(no->operacao[0] == '+'){
            return func(no->prox_esq,vetor)+func(no->prox_dir,vetor);
        }
        if(no->operacao[0] == '/'){
            return func(no->prox_esq,vetor)/func(no->prox_dir,vetor);
        }
        if(no->operacao[0] == '*'){
            return func(no->prox_esq,vetor)*func(no->prox_dir,vetor);
        }
        if(no->operacao[0] == '^'){
            return pow(func(no->prox_esq,vetor),func(no->prox_dir,vetor));
        }
        if(no->operacao[0] == '$'){
            return vetor[stoi(&(no->operacao[1]))];
        }

        return stoi(&(no->operacao[0]));
    }

    //vai interpretar e criar a arvore da expressao
    char* interpretador(char *expr, No *no_anterior){
 
        char *string_back_esq;
        No no;

        //lado esquerdo
        if(expr[0] == '('){
            //verificando se o caractere de agora associado ao no_anterior
            //é o começo de uma expressão ou apenas uma base,
            //caso seja, necessita dois filhos

            no_anterior->prox_esq = (No*) malloc(sizeof(No));
            
            no_anterior->prox_esq[0] = no;
            

            string_back_esq = interpretador(&expr[1],no_anterior->prox_esq);
            no_anterior->operacao = string_back_esq;
            /*
            indo pro lado direito da expressão
            */

            no_anterior->prox_dir = (No*) malloc(sizeof(No));

            no_anterior->prox_dir[0] = no;

            /*
            voltou assim +b)+z) contudo pego apenas b)+z)
            pois estou tirando a operação da propria recursao
            */

            return &interpretador(&string_back_esq[1],no_anterior->prox_dir)[1];

        }else{
            //caso base
            char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                             'n','o','p','q','r','s','v','u','t','w','x','y','z'};
            if(busca(letras,expr[0],26)){
                //quer dizer que o elemento representa uma variavel

                if(variaveis == nullptr){
   
                    variaveis = (No_lista*)malloc(sizeof(No_lista));

                    No_lista new_no_lista;
                    variaveis[0] = new_no_lista;

                    variaveis->caractere = expr[0];

                    char *point = (char*)malloc(2*sizeof(char*));
                    char caractere[] = "$0";
                    

                    point[0] = caractere[0];
                    point[0] = caractere[1];

                    no_anterior->operacao = point;

                    return &expr[1];
                }else{
                    No_lista *list;
                    No_lista *list_past;

                    list = variaveis;
                    int qtd = 0;
                    while(list != nullptr){//vejo se a variavel ja esta na lista

                        if(list->caractere == expr[0]){

                            //retornar o qtd do caractere com $
                            string string_return = "$"+to_string(qtd);
                            char *char_op = (char*)malloc(string_return.length()*sizeof(char));
                            for(int i=0;i<string_return.length();i++){
                                char_op[i] = string_return[i];
                            }
                            no_anterior->operacao = char_op;
                            return &expr[1];
                        }
                        list_past = list;
                        list = list_past->prox;
                        qtd++;
                    }
                    //n esta na lista

                    No_lista *aux = (No_lista*)malloc(sizeof(No_lista));
                    No_lista new_no_lista;
                    *(aux) = new_no_lista;

                    list_past->prox = aux;
                    aux->caractere = expr[0];
                    //retornar o qtd+1 do caractere com $
                    string string_return = "$"+to_string(qtd);
                    char *char_op = (char*)malloc(string_return.length()*sizeof(char));
                    for(int i=0;i<string_return.length();i++){
                        char_op[i] = string_return[i];
                    }
                    no_anterior->operacao = char_op;
                    return &expr[1];

                
                }

                return &expr[1];
            }//se n, ele é um numeo e temos que saber o tamanho dele
            char operacoes[] = {'-','+','/','*','^'};
            int qtd = -1;
            do{
                qtd++;
            }while(!busca(operacoes,expr[qtd],5) && expr[qtd]!=')' );
            char *op = (char*)malloc((qtd+1)*sizeof(char));
            for(int i = 0; i<=qtd; i++){
                op[i] = expr[i];
            }
            no_anterior->operacao = op;

            return &expr[qtd];
        }
        
    }

};


