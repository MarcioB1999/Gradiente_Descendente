# Gradiente Descendente

O método gradiente consiste basicamente que a partir de um ponto $x^{0}=\left(x_{1},...,x_{n}\right)$

<img height="180em" src="https://github.com/MarcioB1999/Gradiente_Descendente/blob/main/imgs/gradienteMetodo.png"/>

## OBS:
ainda esta em construção :)\
mas praticamente quase la
por enquanto a estrutura pra representar funcoes a partir de expressoes,
reconhece apenas operações simples. Ja se tem o algoritmo do gradiente funcionando(n testei com reconhecimento de variaveis). Agora é a parte
de fazer o algoritmo d funcao reconhecer funcoes mais complexas como 
\
ln(x)\
tg(x)\
e assim por diante ...\
ele reconhece oque é variavel e constantes da expressão, contudo não implementei para receber prioridade no reconhecimento de variaveis(mas é so receber um vetor). 
Por enquanto a prioridade é quem vem primeiro na expressão. Por exemplo (y+x) e o vetor {1,2}, o um irá representar o y e dois irá representar o x.(infelizmente ainda nao reconhece coisas como 0.5, contudo é reconhecido se colocar como (1/2))
