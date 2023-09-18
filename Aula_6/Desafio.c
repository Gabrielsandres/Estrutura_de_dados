/*
1- Cria um array de 1000 posições e calcular o tempo
2- Cria um array de 10000 posições e calcular o tempo
3- Cria um array de 100000 posições e calcular o tempo
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>  

#define tamanho 1000



int main() {
    int arr[ARRAY_SIZE];
    int n = sizeof(arr) / sizeof(arr[0]);
    struct timeval ti, tf;
    double tempo;

    srand(time(NULL)); /

    printf("Vetor desordenado: "); 

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand(); 
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
