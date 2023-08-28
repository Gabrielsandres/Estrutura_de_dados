#include <stdio.h>
#include <sys/time.h> 

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
    struct timeval ti, tf;
    double tempo;
    
    int arr[] = {64, 25, 12, 22, 11, 10, 9, 17, 0, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    gettimeofday(&ti, NULL);
    selectionSort(arr, n);
    gettimeofday(&tf, NULL);

    tempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec) / 1000000.0;
    
    printf("Vetor ordenado: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    printf("\nTempo gasto em segundos: %f\n", tempo);

    return 0;
}
