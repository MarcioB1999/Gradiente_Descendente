#include "..\Header\gradienteDescendente.h"
#include <iostream>
//g++ Source\\main_teste.cpp Source\\gradienteDescendente.cpp Interpretador_funcao\\Source\\Funcao.cpp Interpretador_funcao\\Source\\Lista.cpp Interpretador_funcao\\Source\\Arvore_bin.cpp Interpretador_funcao\\Source\\No.cpp Interpretador_funcao\\Source\\Elemento.cpp -o teste.exe

using namespace std;
int main(){
    //char expressao[] {"((((x-5)^2)+((y-3)^2))+((z-2)^2))"};
    char expressao[] {"(((((((1.5-a)-(b*2))^2)+(((2-a)-(b*2.2))^2))+(((3.5-a)-(b*2.9))^2))+(((1.7-a)-(b*1.6))^2))+(((4-a)-(b*4.3))^2))"};
    //A função acima representa o minimo quadrados de uma 
    //regressão linear para os pontos {(1.5,2) (2,2.2) (3.5,2.9) (1.7,1.6) (4,4.3)}
    //ou seja o problema de otimização é o de treinamento para uma regressão linear simples
    lista variaveis_ordem;
    variaveis_ordem.Add('a');
    variaveis_ordem.Add('b');
    
    
    Funcao func(expressao);
    func.Interpretar();
    int n {func.Get_dimensao()};

    gradienteDescendente metodo(&func);

    double *ponto_final = metodo.Descida_Gradiente(500,0.01);

    for(int i=0;i<n;i++){
        cout<<"x["<<i<<"] = "<<ponto_final[i]<<'\n';
    }

    cout<<"valor final = "<<func.Get_valor(ponto_final)<<'\n';

    double v[] = {-0.0311111,0.98888888};

    cout<<"otimo = "<<func.Get_valor(v)<<'\n';

    system("pause");

    return 0;
}