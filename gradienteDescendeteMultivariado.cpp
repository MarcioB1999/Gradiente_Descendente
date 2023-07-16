#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;


struct No{
    char *operacao;
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
        cout<<no->operacao;
        if(no->operacao == "-"){
            return func(no->prox_esq)-func(no->prox_dir);
        }
        if(no->operacao == "+"){
            return func(no->prox_esq)+func(no->prox_dir);
        }
        if(no->operacao == "/"){
            return func(no->prox_esq)/func(no->prox_dir);
        }
        if(no->operacao == "*"){
            return func(no->prox_esq)*func(no->prox_dir);
        }

        return var[stoi(no->operacao)];
    }
};




char* interpretador(char *expr, No *no_anterior){


    char *string_back_esq;
    char *string_back_dir;
    //lado esquerdo
    if(expr[1] != '('){ 
        //na pratica e na teoria ja existe um no pra representar o primeiro
        //parentese, que é o no de entrada, por isso verifica o segundo termo da string
        //verificando a necessidade um no filho

        //cout<<"lado esquerdo \n";
        No no_esq;
        no_anterior->prox_esq = &no_esq;


        char *prox_expr = &expr[1];
        

        string_back_esq = &interpretador(prox_expr,&no_esq)[1];//voltou assim a)+(b))+(z))


        if(string_back_esq[0]=='\0'){
            return NULL;
        }
        no_anterior->operacao = &string_back_esq[0];

        if(string_back_esq[0] != ')'){//caso onde se tem lado direito

            No no_dir;
            no_anterior->prox_dir = &no_dir;


            char *string_dir = &string_back_esq[2];
    
            string_back_dir = interpretador(string_dir,&no_dir);


            

            return &string_back_dir[1];;

        }else{//caso no qual a subarvore esquerda n tem lado direito
            //cout<<"n tem lado direito \n";
            if(expr[1] != ')'){
                no_anterior->operacao = &string_back_esq[1];
            }

            return &string_back_esq[1];
        }

    }else{
        //caso base
        no_anterior->operacao = &expr[0];
        cout<<"retorno = "<<&expr[1]<<"\n";
        return &expr[1];
    }
    
}


int main(){

    
    char expressao[] = "(0)+(1)";
    No raiz;
   

    if(*interpretador(expressao,&raiz)=='\0'){
        cout<<"deu certo, eu acho \n";
    }


    funcao func;
    func.vetorVar(2);
    func.var[0] = 1;
    func.var[1] = 2;
    cout<<*(raiz.operacao)<<"\n";
    No *filho_dir = raiz.prox_dir;
    cout<<ilho_dir->operacao<<"\n";
    //cout<<"valor inicial ="<<func.func(&raiz)<<"\n";
    

    return 0;
}



