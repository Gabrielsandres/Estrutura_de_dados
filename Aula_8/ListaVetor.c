#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int chave;
} Item;

typedef struct 
{
    Item *array;
    int Tamanho;
    int Capacidade;

} Lista;

Lista *criarLista(int Capacidade) {
    Lista *X = (Lista*) malloc(sizeof(Lista));

    if (X == NULL)
    {
        perror("Erro ao alocar memória para a lista");
        exit(1);
    }
    X->array = (Item *) malloc(Capacidade * sizeof(Item));
    if (X->array == NULL)
    {
        perror("Erro ao alocar memória para os itens da lista");
        free(X);
        exit(1);
    }
    
    X->Capacidade = Capacidade;
    X->Tamanho = 0;

    return X;
}

int main(){

    int capacidade = 10;
    Lista* lista = criarLista(capacidade);

    printf("Memoria alocada: %d", sizeof(lista));

    free(lista->array);
    free(lista);


    return 0;
}
