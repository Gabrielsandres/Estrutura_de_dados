#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
 
    FILE *arquivo;
    int x;

    arquivo = fopen("entrada.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fscanf(arquivo, "%d", &x) != EOF){
        printf("%d\n", x);
    }
    
    fclose(arquivo);
    return 0;
}