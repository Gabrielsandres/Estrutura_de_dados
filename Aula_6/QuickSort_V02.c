#include<stdio.h>
#include<stdlib.h>

void swap(int * A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;

}

int Participacao(int Vetor[], int inf, int sup){

    int Pivot = Vetor[sup];
    int i = inf - 1;

    for ( j = inf; j <= sup; j++)
    {
        if (Vetor[j] <= Pivot)
        {
            i++;
            swap(&Vetor[i], &Vetor[j]);
        }
    }
    
    swap(&Vetor[i + 1], &Vetor[sup]);
    return(i + 1);
}

int main(){
    int x[] = {3, 6, 4, 5, 1, 7, 2};

    for (int i = 0; i <= 6; i++)
    {
        printf("%d ", x[i]);
    }
    
    int t = Participacao(x, 0, 6);
    
    printf("\n");
    for (i = 0; i <= 6; i++)
    {
        printf("%d ", x[i]);
    }
    
 }