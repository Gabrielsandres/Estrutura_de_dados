#include <stdio.h>
#include <stdlib.h>

int main() {
 
    FILE *f1, *f2;
    int x;

    f1 = fopen("entrada.txt", "r");
    f2 = fopen("saida.bin", "wb"); 

    if (f1 == NULL || f2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    if (fscanf(f1, "%d", &x) != 1) { // Verifique o retorno de fscanf
        printf("Erro ao ler o valor do arquivo.\n");
        exit(1);
    }
    
    fwrite(&x, sizeof(int), 1, f2); // Escreva o valor no arquivo de saída

    fclose(f1);
    fclose(f2);
    return 0;
}
