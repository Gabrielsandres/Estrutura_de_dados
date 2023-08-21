#include <stdio.h>

int main() {
  
    int numeros[2][3][2] = {
        {{1, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}}
    };

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", numeros[i][j][k]);
            }
            printf("\n"); // Nova linha após cada linha de matriz
        }
        printf("\n"); // Espaço entre matrizes
    }

    return 0;
}
