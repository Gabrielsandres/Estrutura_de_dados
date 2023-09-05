#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("DadosEntrada.csv", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char linha[1024];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token;
        token = strtok(linha, ",");

        while (token != NULL) {
            printf("Campo: %s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(arquivo);

    return 0;
}
