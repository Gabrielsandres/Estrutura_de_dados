#include <stdio.h>
#include <time.h> // Para utilizar a função clock()

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
    clock_t ti, tf;
    ti = clock();
    
    int arr[] = {5, 4, 3, 2, 1, 25, 55, 24, 33,785,9589,82828,45,27,511,6662,47848,11111,2852,331, 41,758};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    tf = clock();
    
    printf("Vetor ordenado: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    double tempo_gasto = ((double)(tf - ti)) / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %f segundos\n", tempo_gasto);

    return 0;
}
