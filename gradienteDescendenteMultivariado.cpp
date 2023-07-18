#include <stdlib.h>
#include <iostream>
#include "funcao.cpp"

using namespace std;

void printa_vetor(double *v,int n){
    cout<<"(";
    for(int i=0;i<n-1;i++){
        cout<<v[i]<<",";
    }
    cout<<v[n]<<") \n";
};


class gradiente_descendente{
    private:
    int n = 0;
    funcao *func;

    public:
    gradiente_descendente(funcao *Funcao,int qtd_variaveis){
        n = qtd_variaveis;
        func = Funcao;
       
    }


    double* Descida_Gradiente(double taxa_aprendizagem=0.2, int parada=100){
        double erro = 99999;
        double *ponto = (double*) malloc(n*sizeof(double));
        double *gradiente;
        for(int i=0;i<n;i++){
            ponto[i] = rand(); 
        }
        double *prox_ponto = (double*) calloc(n,sizeof(double));
        //cout<<"endereço = "<<prox_ponto[0]<<"\n";

        int qtd = 0;
        while(erro>0.001 && qtd < parada){
            
            qtd++;
            
            gradiente = Gradiente(ponto);
            //cout<<"ponto = ";
            //printa_vetor(ponto,n);
            //cout<<"gradiente = ";
            //printa_vetor(gradiente,n);
            
            for(int i=0;i<n;i++){
                prox_ponto[i] = ponto[i]-taxa_aprendizagem*gradiente[i];

            }
            cout<<"======================================= \n";
            erro = abs((func->get_valor(prox_ponto)-func->get_valor(ponto))/func->get_valor(ponto));
            for(int i = 0;i<n; i++){
                ponto[i] = prox_ponto[i];
            }

        };

        return prox_ponto;
    }
    
    private:
    double *Gradiente(double *ponto,double delta=0.1){
        double *gradiente = (double*) malloc(n*sizeof(double));
        
        double ponto_original;

        for(int i=0;i<n;i++){
            
            ponto_original = ponto[i];
            //cout<<"ponto = ";
            //printa_vetor(ponto,2);
            //cout<<"valor = "<<func->get_valor(ponto)<<"\n";

            ponto[i] += delta;
            //cout<<"ponto+delta = ";
            //printa_vetor(ponto,2);
            
            gradiente[i] = func->get_valor(ponto);//com o delta

            //cout<<"valor do +delta = "<<func->get_valor(ponto)<<"\n";
  
            ponto[i] = ponto_original;

            gradiente[i] -= func->get_valor(ponto);//sem o delta

            gradiente[i] /= delta;
        }

        return gradiente;
    }


};

int main(){
    
    
    funcao func("(1/0)");
    double v[] = {2,1};
    cout<<func.get_valor(v);//   y/x = 1/2
    //gradiente_descendente metodo(&func,2);
    
    //double *ponto_final = metodo.Descida_Gradiente(0.5,50);
    /*
    for(int i=0;i<2;i++){
        cout<<"x["<<i<<"] = "<<ponto_final[i]<<"\n";
    }
    */
    //cout<<"valor final = "<<func.get_valor(ponto_final);
  

    return 0;
}