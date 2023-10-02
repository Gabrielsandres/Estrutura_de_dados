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

void inserirElemento(Lista *X, Item Elemento){

    if (X->Tamanho >= X->Capacidade)
    {
        printf("Erro: a lista está cheia!\n");
        return;
    }

    X->array[X->Tamanho] = Elemento;
    X->Tamanho++;
}

void removerElemento(Lista *X, int indice){

    if (indice < 0 || indice > X->Tamanho)
    {
        printf("Indice foras dos limites!\n");
        return;
    }

    for (int i = indice; i < X->Tamanho; i++)
    {
        X->array[i] = X->array[i+1];
    }

    X->Tamanho--;
}

void localizarElemento(Lista *lista, int indice){
    if (indice < 0 || indice >= lista->Tamanho)
    {
        printf("erro ao localizar elemento!");
        return;
    }
    
}

void imprimirLsta(Lista *X){
    for (int i = 0; i < X->Tamanho; i++)
    {
        printf("%d ", X->array[i]);
    }
    
}

int main(){

    int capacidade = 20;
    Lista *lista = criarLista(capacidade);

    inserirElemento(lista, (Item){1});
    
    inserirElemento(lista, (Item){7});
    
    inserirElemento(lista, (Item){13});
    
    inserirElemento(lista, (Item){-1});
    
    inserirElemento(lista, (Item){10});

    printf("\nTamanho: %d", lista->Tamanho);
    imprimirLsta(lista);
    removerElemento(lista, 3);

    printf("\nTamanho: %d", lista->Tamanho);
    imprimirLsta(lista);

}


