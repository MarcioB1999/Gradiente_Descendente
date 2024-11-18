#include "..\Header\gradienteDescendente.h"
#include<time.h>
#include <iostream>
#include <cmath>

using namespace std;



gradienteDescendente::gradienteDescendente(Funcao *Funcao) : n(Funcao->Get_dimensao()),func(Funcao){};


double * gradienteDescendente::Descida_Gradiente(int parada,
                                                 double taxa_aprendizagem_user,
                                                 double erro_user)
{
    double erro{99999}, taxa_aprendizagem {taxa_aprendizagem_user};
    double *ponto =(double*) calloc(this->n,sizeof(double));
    
    double *vetor_erro;

    double *gradiente;

    double *prox_ponto {(double*) calloc(this->n,sizeof(double))};


    int qtd = 0;
    while(erro>0.00001 && qtd < parada){
        
        qtd++;
        cout<<"iteracao = "<<qtd<<"\n";
        cout<<"ponto = ";
        printa_vetor(ponto,this->n);
        cout<<"valor da funcao = "<<this->func->Get_valor(ponto)<<"\n";
        gradiente = Gradiente(ponto,0.001);
        cout<<"gradiente = ";
        printa_vetor(gradiente,this->n);
        
        cout<<"taxa de aprendizagem = "<<taxa_aprendizagem<<"\n";
        
        for(int i=0;i<this->n;i++){
            prox_ponto[i] = ponto[i]-taxa_aprendizagem*gradiente[i];
        }

        erro = abs((this->func->Get_valor(prox_ponto)-this->func->Get_valor(ponto))/this->func->Get_valor(ponto));
        
        cout<<"erro = "<<erro<<"\n";
        cout<<"======================================= \n";
        for(int i = 0;i<this->n; i++){
            ponto[i] = prox_ponto[i];
        }

    };

    return prox_ponto;
}



double * gradienteDescendente::Gradiente(double *ponto,double delta){
    double *gradiente {(double*) malloc(this->n*sizeof(double))};
    
    double ponto_original;

    for(int i=0;i<this->n;i++){
        
        ponto_original = ponto[i];
        //cout<<"ponto = ";
        //printa_vetor(ponto,2);
        //cout<<"valor = "<<func->get_valor(ponto)<<"\n";

        ponto[i] += delta;
        //cout<<"ponto+delta = ";
        //printa_vetor(ponto,2);
        
        gradiente[i] = this->func->Get_valor(ponto);//com o delta

        //cout<<"valor do +delta = "<<func->get_valor(ponto)<<"\n";

        ponto[i] = ponto_original;

        gradiente[i] -= this->func->Get_valor(ponto);//sem o delta

        gradiente[i] /= delta;
    }

    return gradiente;
}


void gradienteDescendente::printa_vetor(double *v,int k){
    cout<<"(";
    for(int i=0;i<k-1;i++){
        cout<<v[i]<<",";
    }
    cout<<v[k-1]<<") \n";
};

float gradienteDescendente::ProdutoInterno(double vetor1[],double vetor2[]){
    double result = 0;
    for(int i=0;i<this->n;i++){
        //cout<<"v1 = "<<vetor1[i]<<"\n";
        result += vetor1[i]*vetor2[i];
    }
    return result;
}