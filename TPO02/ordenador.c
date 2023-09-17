#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(char *vetor[], int inicio, int fim, int *contComp, int *contTroca) {
    
    if (inicio < fim) {
        char *pivot = vetor[inicio];
        int esquerda = inicio;
        int direita = fim;

        while (esquerda < direita) {
            while (strcmp(vetor[esquerda], pivot) <= 0) {
                esquerda++;
                (*contComp)++;
            }
            while (strcmp(vetor[direita], pivot) > 0) {
                direita--;
                (*contComp)++;
            } 

            if (esquerda < direita) {
                swap(&vetor[esquerda], &vetor[direita]);
                (*contTroca)++;
            }
        }

        swap(&vetor[inicio], &vetor[direita]);
        (*contTroca)++;

        quickSort(vetor, inicio, direita - 1, contComp, contTroca);
        quickSort(vetor, direita + 1, fim, contComp, contTroca);
    }

}

int main() {

    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};
    int n = sizeof(arr) / sizeof(arr[0]);
    int contTroca = 0;
    int contComp = 0;

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%s, ", arr[i]);
    }

    quickSort(arr, 0, n - 1, &contComp, &contTroca);

    printf("\n\n");
    printf("Array ordenado em ordem crescente: ");
    for (int i = 0; i < n; i++) {
        printf("%s, ", arr[i]);
    }
    printf("\nNumero total de trocas: %d", contTroca);
    printf("\nNumero total de comparacoes: %d", contComp);

    return 0;
}
