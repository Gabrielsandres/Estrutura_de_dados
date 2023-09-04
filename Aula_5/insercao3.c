    #include<stdio.h>

    void insercao (int V[], int N, int *C, int *S){

        *C = 1;
        *S = 0;

        for (int i = 1; i < N; i++){
            
            (*S)++;
            int chave = V[i];
            int j = i - 1;

            while (j >= 0 && V[j] > chave){
                (*C)++;
                (*S)++;
                V[j + 1] = V[j];
                j--;

            }

            (*S)++;
            V[j + 1] = chave;

        }
    }

    int main() {

            int Array[] = {64, 25, 12, 22, 11};
            int N = sizeof(Array)/sizeof(Array[0]);
            int comparacoes, trocas;

            insercao(Array, N, &comparacoes, &trocas);

            printf("Vetor ordenado: ");
            for (int i = 0; i < N; i++) printf("%d\t", Array[i]);

            printf("\nComparacoes: %d\nTrocas: %d",comparacoes, trocas);
            
            return 0;
        }