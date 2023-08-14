#include <stdio.h>

struct Pessoa {
    char nome[20];
    int idade;
    float altura;
  };

int main(void) {
  struct Pessoa X;

  strcpy(X.nome, "Mario");
  X.idade = 25;
  X.altura = 1.75;
  
  // Impressões

  printf("Nome: %s\n", X.nome);
  printf("Idade: %d\n", X.idade);
  printf("Altura: %.2f\n", X.altura);
  
  return 0;
}