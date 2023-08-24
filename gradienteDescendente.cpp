#include "C:\Users\marcio\Documents\Codigos\Interpretador_funcao\funcao.cpp"
#include<time.h>

using namespace std;

class GradienteDescendente{
    private:
    int n = 0;
    Funcao *func;

    public:
    GradienteDescendente(Funcao *Funcao,int qtd_variaveis){
        n = qtd_variaveis;
        func = Funcao;
       
    }


    double* Descida_Gradiente(int parada=100,int type_error=1,double alpha=0){
        double erro = 99999,taxa_aprendizagem;
        double *ponto = (double*) malloc(n*sizeof(double));
        
        double *vetor_erro;
        if(type_error == 2){
            vetor_erro = (double*) malloc(n*sizeof(double));
        }
        double *gradiente;
        srand(time(NULL));


        for(int i=0;i<n;i++){
            ponto[i] = rand(); 
        }

        double *prox_ponto = (double*) calloc(n,sizeof(double));


        int qtd = 0;
        cout<<"chegou aqui";
        while(erro>0.001 && qtd < parada){
            
            qtd++;
            cout<<"iteracao = "<<qtd<<"\n";
            cout<<"ponto = ";
            printa_vetor(ponto,n);
            cout<<"valor da funcao = "<<func->Get_valor(ponto)<<"\n";
            gradiente = Gradiente(ponto);
            cout<<"gradiente = ";
            printa_vetor(gradiente,n);
            if(alpha!=0){
                taxa_aprendizagem = alpha;
            }else{
                taxa_aprendizagem = Wolfe(0.2,0.5,ponto,gradiente);
            }
            
            cout<<"taxa de aprendizagem = "<<taxa_aprendizagem<<"\n";
            
            for(int i=0;i<n;i++){
                prox_ponto[i] = ponto[i]-taxa_aprendizagem*gradiente[i];
                if(type_error == 2){
                    vetor_erro[i] = prox_ponto[i]-ponto[i];
                }
            }
            if(type_error == 1){
                erro = abs((func->Get_valor(prox_ponto)-func->Get_valor(ponto))/func->Get_valor(ponto));
            }else{
                if(type_error == 2){
                    erro = sqrt(ProdutoInterno(vetor_erro,vetor_erro));
                }else{
                    erro = sqrt(ProdutoInterno(gradiente,gradiente));
                }
            }
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
            
            gradiente[i] = func->Get_valor(ponto);//com o delta

            //cout<<"valor do +delta = "<<func->get_valor(ponto)<<"\n";
  
            ponto[i] = ponto_original;

            gradiente[i] -= func->Get_valor(ponto);//sem o delta

            gradiente[i] /= delta;
        }

        return gradiente;
    }

    float Wolfe(double theta1,double tetha2,double *x,double *gradiente){
        double alpha_inf=0, alpha_sup=0, alpha=0.5,erro = 0.0001;
        double *new_x = (double*) malloc(n*sizeof(double));

        double deriv_di = -ProdutoInterno(gradiente,gradiente);//<f'(x),d>

        srand(time(NULL));
        //int q=0;
        while(true){
            //q++;

            for(int i=0;i<n;i++){//semi reta x+alpha.d
                new_x[i] = x[i]-alpha*gradiente[i];
            }
            /*
            cout<<"alpha = "<<alpha<<"\n";
            cout<<"vetor = ";
            printa_vetor(new_x,n);

            cout<<func->Get_valor(new_x)<<"<="<<func->Get_valor(x)+alpha*theta1*deriv_di<<", \n";
            if(func->Get_valor(new_x)<=func->Get_valor(x)+alpha*theta1*deriv_di){
                cout<<"Verdadeiro \n";
            }else{
                cout<<"Falso \n";
            }
            
            cout<<"new gradiente = ";
            printa_vetor(Gradiente(new_x),n);
            cout<<"gradiente = ";
            printa_vetor(gradiente,n);
            cout<<-ProdutoInterno(Gradiente(new_x),gradiente)<<">="<<tetha2*deriv_di<<", \n";
            if(-ProdutoInterno(Gradiente(new_x),gradiente) >= tetha2*deriv_di){
                cout<<"Verdadeiro \n";
            }else{
                cout<<"Falso \n";
            }
            */
            if(func->Get_valor(new_x)-(func->Get_valor(x)+alpha*theta1*deriv_di) <= erro
                &&
             -ProdutoInterno(Gradiente(new_x),gradiente)-tetha2*deriv_di >=  -erro){
                return alpha;
            }
            if(func->Get_valor(new_x) > func->Get_valor(x)+alpha*theta1*deriv_di){
                alpha_sup = alpha;
            }else{
                alpha_inf = alpha;
            }
            //cout<<"("<<alpha_inf<<","<<alpha_sup<<")\n";

            if(alpha_sup == 0){
                
                alpha = random(alpha_inf);
                
                //escolher nv alpha maior q inf
            }else{
                alpha = random(alpha_inf,alpha_sup);
            }

            //cout<<"...................................................................\n";
        }
        //return 0.01;

    }

    void printa_vetor(double *v,int n){
        cout<<"(";
        for(int i=0;i<n-1;i++){
            cout<<v[i]<<",";
        }
        cout<<v[n-1]<<") \n";
    };

    float ProdutoInterno(double vetor1[],double vetor2[]){
        double result = 0;
        for(int i=0;i<n;i++){
            //cout<<"v1 = "<<vetor1[i]<<"\n";
            result += vetor1[i]*vetor2[i];
        }
        return result;
    }

    double random(double min,double max=1){
        double random_MinMax, random, comprimento = max-min;
        random = rand()%100;
        random_MinMax = (random/100)*comprimento*(1-0.0001);
        //cout<<"r = "<<random_MinMax<<"\n";
        return min+random_MinMax+comprimento*0.01;
    }
};
