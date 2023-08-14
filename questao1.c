//Crie um programa que declare um array de inteiros com 6 elementos e preencha-o com valores digitados pelo usuário. Em seguida, calcule e exiba a média dos valores pressentes no array;

#include <stdio.h>

int *lerVetor(int T) {
  int *vetor = malloc(T * sizeof(int));
  for (int i = 0; i < T; i++){
    printf("Posicao %d: ", i);
    scanf("%d", &vetor[i]);
  }
  return vetor;
}

float calcularMedia(int vetor[], int T) {

 float media = 0;
  for (int i = 0; i < T; i++){
    media +=vetor[i];
  }
  media = media / T;

  return (media);
  
}

int main(void) {

  int *vetor = lerVetor(6);
  printf("%.2f", calcularMedia(vetor, 6));
  
  return 0;
}