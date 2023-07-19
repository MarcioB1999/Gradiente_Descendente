struct No{
    char *operacao;
    No *prox_dir;
    No *prox_esq;

    No(){
        operacao = nullptr;
        prox_dir = nullptr;
        prox_esq = nullptr;
    }
};

struct No_lista{
    char caractere;
    No_lista *prox;

    No_lista(){
        prox = nullptr;
        caractere = 'v';
    }
};

bool busca(char vetor[],char elemento, int tam){

    //26
    for(int i = 0; i<tam; i++){
   
        if(vetor[i] == elemento){
            return true;
        }
    }

    return false;
}
