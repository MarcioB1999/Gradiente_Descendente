#include "..\Interpretador_funcao\Header\Funcao.h"

using namespace std;

class gradienteDescendente{
    private:
    int n;
    Funcao *func;

    public:
    gradienteDescendente(Funcao *Funcao);


    double* Descida_Gradiente(int parada=100,
                              double taxa_aprendizagem_user=0.001,
                              double erro_user=0.00001);
    
    private:
    double *Gradiente(double *ponto,double delta = 0.001);

    void printa_vetor(double *v,int n);

    float ProdutoInterno(double vetor1[],double vetor2[]);
};