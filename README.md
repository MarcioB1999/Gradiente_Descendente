# Gradiente Descendente

## Algoritmo

O método gradiente consiste basicamente em um método iterativo que a partir de um ponto inicial $\textbf{x}^{0}=\left(x_{1}^{0},...,x_{n}^{0}\right) \in \mathbf{R}^{n}$, percorremos a direção do vetor gradiente sucessivamente de modo a obter o mínimo local de uma função $f\left(\textbf{x}\right)$.

<img height="180em" src="https://github.com/MarcioB1999/Gradiente_Descendente/blob/main/imgs/gradienteMetodo.png"/>

O funcionamento do algortimo pode-se ver na imagem anterior, retirada do artigo https://www.researchgate.net/publication/351361317_Ottimizzazione_di_flussi_esterni_ed_interni_mediante_metodi_CFD_adjoint_e_mesh_morphing, no qual o próximo ponto da iteração é dado pela seguinte equação,

$\textbf{x}^{k+1}=\textbf{x}^{k}-\alpha \bigtriangledown f\left(\text{x}^{k}\right)$

ou temos

$x_{i}^{k+1}=x_{i}^{k}-\alpha \frac{\partial}{\partial x_{i}}f\left(\textbf{x}^{i}\right),\forall i=1,...,n$

no qual $\alpha$ denomina-se taxa de aprendizado, e é exatamente o quanto que queremos percorrer na direção do vetor gradiente. 
## Critério de Parada
O critério de parada pode ser três, que são escolhidos através de um parâmetro, os critérios são

(1) $\mid\frac{f\left(\textbf{x}^{k+1}\right)-f\left(\textbf{x}^{k}\right)}{f\left(\textbf{x}^{k}\right)}\mid\leq\varepsilon$

(2) $\mid \mid x^{k+1}-x^{k}\mid \mid \leq\varepsilon$ 

(3) $\mid \mid \bigtriangledown f\left(\text{x}^{k+1}\right) \mid \mid \leq\varepsilon$

com $\varepsilon$ próximo de zero quanto o usuário desejar.

## Regra Wolfe

A regra wolfe se dar para aumentar o desempenho do método, ele se dar pela escolha do parâmetros $\alpha$, em vez de um valor fixo. Portanto, para cada iteração $k$ do algoritmo, se escolhe $\alpha_{k}$, de modo a satisfazer as desigualdades (1.1) e (1.2).

(1.1) $f\left(x^{k}-\alpha^{k}\bigtriangledown f\left(\text{x}^{k}\right)\right)\leq f\left(x^{k}\right)-\alpha_{k}\theta_{1}\mid \mid \bigtriangledown f\left(\text{x}^{k}\right)\mid \mid$

(1.2) $-\langle \bigtriangledown f\left(\text{x}^{k+1}\right),\bigtriangledown f\left(\text{x}^{k}\right)\rangle \geq -\theta_{2}\mid\mid \bigtriangledown f\left(\text{x}^{k}\right)\mid\mid $

OBS:Por enquanto o método não se dar bem com funções que crescem rapidamente. Oque pode tentar solucionar, será mudança no tipode dados, para uns mais altos, ou uma melhor escolha dos pontos iniciais, ou pelomenos que não sejam tão grandes.

## Código

Basicamente para se ter uma intância da classe, o construtor irá receber um objeto da classe função, https://github.com/MarcioB1999/Interpretador_funcao, e a quantidade de variáveis da função(em breve não será mais necessário). Para o usuário, apenas se tem acesso ao método Descida_Gradiente

### Descida_Gradiente (Double taxa_aprendizagem, Int parada ):
>####     Argumentos:
>>#####    Taxa_aprendizagem: O quanto se quer percorrer na direção do gradiente.
>>##### Parada: Número máximo de iterações.
>#### Retorno: Retorna um ponteiro double para o vetor $\textbf{x}^{k}=\min_{\textbf{x}} f\left(\textbf{x}\right)$ (Nesse caso tambem se refere a mínimos locais, não apenas mínimos globais).


## OBS:
ainda esta em construção 😀
mas praticamente quase la, ele sofre limitações pela classe função recebida como argumento.
