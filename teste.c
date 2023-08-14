#include <stdio.h>

int main () {
    int matriz [2] [3] = {1, 2, 3, 4, 5, 6}; 

    for (int l = 0; l < 2; l++ ){
        printf("\n");
        for(int c = 0; c < 3; c++){
            printf("%d ", matriz[l][c]);
        }
    }
    return 0;
}