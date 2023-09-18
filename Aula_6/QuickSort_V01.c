#include<stdio.h>
#include<stdlib.h>

void swap(int * A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;

    printf("%d %d\n", *A, *B);
}

int main(){
    int x = 10;
    int y = 15;

    swap(&x, &y);

    return 0;
}