    /*Adicionar medição de tempo via função clock() ou gettimeofday()*/
    
    #include<stdio.h>
    #include <sys/time.h> 

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

            struct timeval ti, tf;
            double tempo;

            int Array[] = {64, 25, 12, 22, 11, 56, 27, 89, 14, 73, 42, 56, 27, 89, 14, 73, 42, 68, 5, 91, 33, 60, 18, 70, 3, 37, 82, 51, 10, 69, 25, 78, 45, 8, 64, 19, 92, 49, 23, 71, 35, 87, 12, 57, 31, 74, 41, 66, 2, 36, 83, 53, 16, 75, 47, 9, 61, 28, 88, 55, 21, 77, 44, 7, 63, 30, 86, 50, 85, 39, 6, 72, 17, 58, 32, 76, 48, 95, 11, 67, 22, 90, 52, 24, 80, 43, 65, 38, 96, 15, 62, 29, 84, 54, 20, 81, 46, 59, 34, 97, 1, 79, 4, 93, 40, 98, 13, 99, 94, 26, 66,  68, 5, 91, 33, 60, 18, 70, 3, 37, 82, 51, 10, 69, 25, 78, 45, 8, 64, 19, 92, 49, 23, 71, 35, 87, 12, 57, 31, 74, 41, 66, 2, 36, 83, 53, 16, 75, 47, 9, 61, 28, 88, 55, 21, 77, 44, 7, 63, 30, 86, 50, 85, 39, 6, 72, 17, 58, 32, 76, 48, 95, 11, 67, 22, 90, 52, 24, 80, 43, 65, 38, 96, 15, 62, 29, 84, 54, 20, 81, 46, 59, 34, 97, 1, 79, 4, 93, 40, 98, 13, 99, 94, 26, 66};
            int N = sizeof(Array)/sizeof(Array[0]);
            int comparacoes, trocas;

            gettimeofday(&ti, NULL);
            insercao(Array, N, &comparacoes, &trocas);
            gettimeofday(&tf, NULL);

            tempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec) / 1000000.0;

            printf("Vetor ordenado: ");
            for (int i = 0; i < N; i++) printf("%d\t", Array[i]);

            printf("\nComparacoes: %d\nTrocas: %d",comparacoes, trocas);

            printf("\nTempo gasto em segundos: %f\n", tempo);
            
            return 0;
        }