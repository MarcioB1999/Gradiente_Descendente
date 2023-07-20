# Gradiente Descendente

## Algoritmo

O método gradiente consiste basicamente que a partir de um ponto $\textbf{x}^{0}=\left(x_{1}^{0},...,x_{n}^{0}\right) \in \mathbf{R}^{n}$, percorremos a direção do vetor gradiente sucessivamente de modo a obter o mínimo local de uma função $f\left(\textbf{x}\right)$.

<img height="180em" src="https://github.com/MarcioB1999/Gradiente_Descendente/blob/main/imgs/gradienteMetodo.png"/>

O funcionamento do algortimo pode-se ver na imagem anterior, retirada do artigo https://www.researchgate.net/publication/351361317_Ottimizzazione_di_flussi_esterni_ed_interni_mediante_metodi_CFD_adjoint_e_mesh_morphing, no qual o próximo ponto da iteração é dado pela seguinte equação,

$\textbf{x}^{k}=\textbf{x}^{k-1}-\alpha \bigtriangledown f\left(\text{x}^{k-1}\right)$

ou temos

$x_{i}^{k+1}=x_{i}^{k}-\alpha \frac{\partial}{\partial x_{i}}f\left(\textbf{x}^{i}\right),\forall i=1,...,n$

no qual $\alpha$ denomina-se taxa de aprendizado, e é exatamente o quanto que queremos percorrer na direção do vetor gradiente. O critério de parada é quando o valor de 

$\mid\frac{f\left(\textbf{x}^{k+1}\right)-f\left(\textbf{x}^{k}\right)}{f\left(\textbf{x}^{k}\right)}\mid\geq\lambda$

com $\lambda$ próximo de zero quanto o usuário desejar.

## Código

Basicamente para se ter uma intância da classe, o construtor irá receber um objeto da classe função, link do repositório, e a quantidade de variáveis da função(em breve não será mais necessário). Para o usuário, apenas se tem acesso ao método Descida_Gradiente

### Descida_Gradiente (Double taxa_aprendizagem, Int parada ):
>####     Argumentos:
>>#####    Taxa_aprendizagem: O quanto se quer percorrer na direção do gradiente.
>>##### Parada: Funciona como parada precoce, o número máximo de iterações.
>#### Retorno: Retorna um ponteiro double para o vetor $\textbf{x}^{k}=\min_{\textbf{x}} \phi \left(f\left(\textbf{x}\right)\right)$ (Nesse caso $\phi$ se refere ao método de gradiente descendente).


## OBS:
ainda esta em construção 😀
mas praticamente quase la, ele sofre limitações pela classe função recebida como argumento.
