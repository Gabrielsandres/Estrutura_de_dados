#include <stdio.h>

void exibirArray (int array[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int main(void) {
  int meuArray[5] = {3, 7, 4, 1, 0};
  int tamanho = sizeof(meuArray)/sizeof(meuArray[0]);
  exibirArray(meuArray, tamanho);
  
  return 0;
}