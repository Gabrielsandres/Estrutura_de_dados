#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int chave;
    struct Item *proximo;
} Item;

typedef struct Lista {
    Item *cabeca;
    int tamanho;
} Lista;

// Função para exibir todos os elementos da lista

void exibirLista(Lista *lista) {
    printf("Lista: ");
    Item *atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para criar uma lista vazia

Lista *criarListaVazia() {
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    if (novaLista == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

// Função para inserir elemento na lista

void inserirNaPosicao(Lista *lista, int posicao, Item *item) {
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida para inserção.\n");
        return;
    }
    if (posicao == 0) {
        item->proximo = lista->cabeca;
        lista->cabeca = item;
    } else {
        Item *anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        item->proximo = anterior->proximo;
        anterior->proximo = item;
    }
    lista->tamanho++;
}

// Função para excluir o i-ésimo elemento da lista

void removerDaPosicao(Lista *lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida para remoção.\n");
        return;
    }

    if (posicao == 0) {
        Item *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        free(temp);
    } else {
        Item *anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        Item *temp = anterior->proximo;
        anterior->proximo = temp->proximo;
        free(temp);
    }
    lista->tamanho--;
}

// Função para determinar o tamanho da lista

int retornarTamanhoLista(Lista *lista) {
    return (lista->tamanho);
}

// Função para exibir todos os elementos da lista

int determinarMaiorValor(Lista *lista) {
    if (lista->cabeca == NULL) {
        printf("A lista está vazia.\n");
        return -1; // Retorne um valor de erro ou defina um comportamento apropriado.
    }

    Item *atual = lista->cabeca;
    int Maior = atual->chave;
    while (atual != NULL) {
        if (Maior < atual->chave) {
            Maior = atual->chave;
        }
        atual = atual->proximo;
    }
    return (Maior);
}

float calcularMedia(Lista *lista) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia.\n");
        return 0.0; // Ou defina um comportamento apropriado.
    }

    Item *atual = lista->cabeca;
    int Soma = 0;
    while (atual != NULL) {
        Soma += atual->chave;
        atual = atual->proximo;
    }

    float Media = (float)Soma / lista->tamanho;
    return Media;
}

int main() {
    Lista *X = criarListaVazia();

    Item *item1 = (Item *)malloc(sizeof(Item));
    item1->chave = 10;
    inserirNaPosicao(X, 0, item1);

    Item *item2 = (Item *)malloc(sizeof(Item));
    item2->chave = 20;
    inserirNaPosicao(X, 1, item2);

    Item *item3 = (Item *)malloc(sizeof(Item));
    item3->chave = 30;
    inserirNaPosicao(X, 0, item3);

    Item *item4 = (Item *)malloc(sizeof(Item));
    item4->chave = 40;
    inserirNaPosicao(X, 2, item4);

    exibirLista(X);
    printf("Maior: %d\n", determinarMaiorValor(X));
    
    printf("A media eh: %.2f\n", calcularMedia(X)); 

    return 0;
}
