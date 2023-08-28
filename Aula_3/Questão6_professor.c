#include<stdio.h>
#include<stdlib>
#include<string.h>

/*Arroz 2 5.50
Feijão 3 3.00
Carne 1 15.75
Leite 4 2.50*/

int main(){

    FILE *arquivo;

    int quantidade;
    int contador;
    char produto[50];
    float total = 0;
    float preco;
    float subtotal;

    arquivo = fopen("lista_compra.txt");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while( fscanf(arquivo, "%s %d %f", produto, &quantidade, &preco) != EOF){
        contador++;
        subtotal = quantidade * preco;
    }
}