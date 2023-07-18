#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

double funcao(double x){
    return (pow(x,2));
}


double derivadas(double x){
    double delta=0.0001;
    return (funcao(x+delta)-funcao(x))/delta;

}

double gradiente_descendente(){
    float taxa_aprendizado = 0.5;
    double x = rand();
    cout<<"valor inicial ="<<x<<"\n";
    double x_new;
    double erro = 99999;
    while(erro>=pow(10,-10)){
        x_new=x-taxa_aprendizado*derivadas(x);
        erro=abs(funcao(x_new)-funcao(x))/funcao(x);
        x=x_new;
    }
    return x;

}


int main(){
    double x_otimo;
    x_otimo=gradiente_descendente();
    cout<<"x otimo ="<<x_otimo<<"\n";
    cout<<"valor otimo ="<<funcao(x_otimo);
    return 0;
}