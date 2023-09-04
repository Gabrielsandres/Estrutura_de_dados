#include<stdio.h>

/*{5, 3, 2 }*/


/*Crescente*/
void insercao (int V[], int N){

    for (int i = 1; i < N; i++){
        
        int chave = V[i];
        int j = i - 1;

        while (j >= 0 && V[j] > chave){
            
            V[j + 1] = V[j];
            j--;

        }

        V[j + 1] = chave;

    }
}

int main() {

        int Array[] = {64, 25, 12, 11, 17};
        int N = sizeof(Array)/sizeof(Array[0]);

        insercao(Array, N);

        printf("Vetor ordenado: ");
        for (int i = 0; i < N; i++) printf("%d\t", Array[i]);

        
        return 0;
    }