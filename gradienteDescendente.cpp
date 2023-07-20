#include "C:\Users\marcio\Documents\Interpretador_funcao\funcao.cpp"
#include<time.h>

using namespace std;

void printa_vetor(double *v,int n){
    cout<<"(";
    for(int i=0;i<n-1;i++){
        cout<<v[i]<<",";
    }
    cout<<v[n-1]<<") \n";
};


class GradienteDescendente{
    private:
    int n = 0;
    Funcao *func;

    public:
    GradienteDescendente(Funcao *Funcao,int qtd_variaveis){
        n = qtd_variaveis;
        func = Funcao;
       
    }


    double* Descida_Gradiente(double taxa_aprendizagem=0.2, int parada=100){
        double erro = 99999;
        double *ponto = (double*) malloc(n*sizeof(double));
        double *gradiente;
        srand(time(NULL));

        for(int i=0;i<n;i++){
            ponto[i] = rand(); 
        }
        double *prox_ponto = (double*) calloc(n,sizeof(double));
        //cout<<"endereço = "<<prox_ponto[0]<<"\n";

        int qtd = 0;
        while(erro>0.001 && qtd < parada){
            
            qtd++;
            cout<<"iteracao = "<<qtd<<"\n";
            cout<<"valor da funcao = "<<func->get_valor(ponto)<<"\n";
            gradiente = Gradiente(ponto);
            cout<<"ponto = ";
            printa_vetor(ponto,n);
            cout<<"gradiente = ";
            printa_vetor(gradiente,n);
            
            for(int i=0;i<n;i++){
                prox_ponto[i] = ponto[i]-taxa_aprendizagem*gradiente[i];

            }
            erro = abs((func->get_valor(prox_ponto)-func->get_valor(ponto))/func->get_valor(ponto));
            cout<<"erro = "<<erro<<"\n";
            cout<<"======================================= \n";
            for(int i = 0;i<n; i++){
                ponto[i] = prox_ponto[i];
            }

        };

        return prox_ponto;
    }
    
    private:
    double *Gradiente(double *ponto,double delta=0.001){
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
