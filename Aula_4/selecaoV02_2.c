#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h> // Para utilizar a função time()

#define ARRAY_SIZE 1000

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int n = sizeof(arr) / sizeof(arr[0]);
    struct timeval ti, tf;
    double tempo;

    srand(time(NULL)); // Correção: troque tme por time

    printf("Vetor desordenado: "); // Correção: Adicione ; no final

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand(); // Gera um número aleatório
        printf("%d\t", arr[i]);
    }

    gettimeofday(&ti, NULL);
    selectionSort(arr, n);
    gettimeofday(&tf, NULL);

    tempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec) / 1000000.0;

    printf("\n\n\nVetor ordenado: "); // Correção: Adicione \n para quebra de linha

    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n\nTempo gasto em segundos: %f\n", tempo);

    return 0;
}
