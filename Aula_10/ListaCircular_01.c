#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int chave;
    struct Item *proximo;
} Item;

typedef struct ListaCircular {
    Item *cabeca;
    int tamanho;
} ListaCircular;

// Implementação da função ExibirLista
void exibirListaCircular(ListaCircular *lista) {
    printf("Lista: ");
    Item *atual = lista->cabeca;
    do {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    } while (atual != lista->cabeca);
    printf("\n");
}

ListaCircular *criarListaCircularVazia() {
    ListaCircular *novaLista = (ListaCircular *)malloc(sizeof(ListaCircular));
    if (novaLista == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

void adicionarElemento(ListaCircular *lista, Item *novoItem) {
    if (novoItem == NULL) {
        printf("Item inválido");
        return;
    }

    if (lista->cabeca == NULL) {
        novoItem->proximo = novoItem;
        lista->cabeca = novoItem;
    } else {
        novoItem->proximo = lista->cabeca;
        Item *atual = lista->cabeca;
        while (atual->proximo != lista->cabeca) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }

    lista->tamanho++;
}

void numeroDeOcorrencias(ListaCircular *lista, Item *temp){
    
}

int main() {
    ListaCircular *X = criarListaCircularVazia();
    Item *I1 = (Item *)malloc(sizeof(Item));
    Item *I2 = (Item *)malloc(sizeof(Item));
    Item *I3 = (Item *)malloc(sizeof(Item));
    Item *I4 = (Item *)malloc(sizeof(Item));
    I1->chave = 10;
    I2->chave = 20;
    I3->chave = 30;
    I4->chave = 40;
    adicionarElemento(X, I1);
    adicionarElemento(X, I2);
    adicionarElemento(X, I3);
    adicionarElemento(X, I4);
    printf("Tamanho da lista: %d\n", X->tamanho);

    Item *Temp = (Item *)malloc(sizeof(Item));
    Temp->chave = 15;

    int t = numeroDeOcorrencias(X, Temp);


    // Exibir a lista circular
    exibirListaCircular(X);

    return 0;
}
