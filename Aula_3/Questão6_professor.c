#include<stdio.h>
#include<stdlib>
#include<string.h>

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