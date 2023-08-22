#include "gradienteDescendente.cpp"

using namespace std;
int main(){
    //((x^2)*y)
    double v[]={3,2};
    //(((((x-3)^2)+((y-3)^2))*(((x-1)^2)+((y-2)^2)))*(z^2)) função q dar erro

    Funcao func("(x^6)");
    int n=1;

    GradienteDescendente metodo(&func,n);

    double *ponto_final = metodo.Descida_Gradiente(50,3);

    for(int i=0;i<n;i++){
        cout<<"x["<<i<<"] = "<<ponto_final[i]<<"\n";
    }

    cout<<"valor final = "<<func.Get_valor(ponto_final);

    return 0;
}