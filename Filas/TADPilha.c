#include <stdio.h>
#include <stdlib.h>

#define ERRO -1
#define SIM 1
#define NAO 0

typedef struct Item {
    int chave;
    struct Item* Proximo;
} Item;

typedef struct Pilha {
    int Tamanho;
    Item *Topo;
} Pilha;

// Função para criar uma pilha vazia.
Pilha *criarPilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: Falha ao alocar memoria para a pilha.\n");
        return NULL;
    }
    p->Tamanho = 0;
    p->Topo = NULL;
    return p;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return (p->Topo == NULL) ? SIM : NAO;
}

// Função para criar item da pilha
Item *criarItem(int x) {
    Item *novoItem = (Item *) malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("Erro: Falha ao alocar memoria para a pilha.\n");
        return NULL;
    }
    novoItem->chave = x;
    novoItem->Proximo = NULL;
    return novoItem;
}

// Inserindo novo item na pilha
void empilhar(Pilha *p, int chave) {
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->Topo;
    p->Topo = novoItem;
    p->Tamanho = p->Tamanho + 1;
}

// Retirar um elemento da pilha
int desempilhar(Pilha *p) {
    if (estaVazia(p) == SIM) {
        printf("ERRO: A pilha esta vazia!");
        return ERRO;
    }
    Item *temp = p->Topo;
    int chave = temp->chave;
    p->Topo = p->Topo->Proximo;
    free(temp);
    p->Tamanho = p->Tamanho - 1;
    return chave;
}

// Destruindo a pilha
void liberarPilha(Pilha *p) {
    while (!estaVazia(p)) {
        desempilhar(p);
    }
    free(p);
}

int main() {
    Pilha *p = criarPilha();
    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);
    empilhar(p, 20);
    printf("Desempilhando...\n");
    while (!estaVazia(p)) {
        printf("Chave: %d\n", desempilhar(p));
    }
    liberarPilha(p);
    return 0;
}
