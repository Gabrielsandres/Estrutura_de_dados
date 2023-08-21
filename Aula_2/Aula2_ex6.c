#include <stdio.h>

int *criarArray(int tamanho) {
    int *array = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
        array[i] = i + 1;
    return array;
}

int main(){
    
    int tamanho = 20;
    int *meuArrey = criarArray(tamanho);
    for (int i = 0; i < tamanho; i++) printf("%d\t", meuArrey[i]);
    free(meuArrey);

    return 0;
}