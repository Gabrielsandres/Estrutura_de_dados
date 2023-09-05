#include<stdio.h>
#include <stdlib.h>

void main(){

    FILE *arquivo;
    arquivo = fopen("DadosEntrada.csv", "r");

    if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
    }

    char linha[1024];
    char delim = ',';

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char *token = strtok(linha, delim);

        while (token != NULL) {

            printf("Token: %s\n", token);
            token = strtok(NULL, delim);
        }
    }
    

    

    fclose(arquivo);

}