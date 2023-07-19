#include "gradienteDescendente.cpp"

using namespace std;
int main(){
    
    
    Funcao func("((x-y)^2)");

    double v[] = {2,15};
    cout<<func.get_valor(v)<<"\n";
    GradienteDescendente metodo(&func,2);

    double *ponto_final = metodo.Descida_Gradiente(0.3,500);

    for(int i=0;i<2;i++){
        cout<<"x["<<i<<"] = "<<ponto_final[i]<<"\n";
    }

    cout<<"valor final = "<<func.get_valor(ponto_final);

    return 0;
}