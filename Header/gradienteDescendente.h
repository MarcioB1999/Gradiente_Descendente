#include "..\Interpretador_funcao\Header\Funcao.h"

using namespace std;

class gradienteDescendente{
    private:
    int n = 0;
    Funcao *func;

    public:
    gradienteDescendente(Funcao *Funcao,int qtd_variaveis);


    double* Descida_Gradiente(int parada=100,double alpha=0.001);
    
    private:
    double *Gradiente(double *ponto,double delta = 0.001);

    void printa_vetor(double *v,int n);

    float ProdutoInterno(double vetor1[],double vetor2[]);
};