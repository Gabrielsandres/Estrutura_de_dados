#include <stdio.h>

struct Pessoa{
  char nome[20];
  int idade;
};

void imprimirPessoa(struct Pessoa P) {
  printf("%s\t%d\n", P.nome, P.idade);
}

void modificarPessoa(struct Pessoa *P) {
  P->idade = P->idade + 1;
}

int main(void) {

  struct Pessoa X = {"Joao", 19};
  
  modificarPessoa(&X);
  imprimirPessoa(X);
    
  return 0;
}