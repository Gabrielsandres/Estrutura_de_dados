#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *entrada;
    FILE *saida;
    char linha[100]; 

    // Abra o arquivo CSV para leitura
    entrada = fopen("DadosEntrada.csv", "r");
    saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL) {
        perror("Erro ao abrir DadosEntrada");
        return 1;
    }

    if (saida == NULL) {
        perror("Erro ao abrir SituacaoFinal");
        return 1;
    }

    char nomes[100][50];
    char telefones[100][20];
    char cursos[100][50];
    float nota1[100];
    float nota2[100];
    float media[100];
    char situacao[100][10];
    int i = 0;

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        
        if (sscanf(linha, "%49[^,],%19[^,],%49[^,],%f,%f", nomes[i], telefones[i], cursos[i], &nota1[i], &nota2[i]) == 5) {
            media[i] = (nota1[i] + nota2[i]) / 2;
            if (media[i] >= 7) {
                strcpy(situacao[i], "Aprovado");
            } else {
                strcpy(situacao[i], "Reprovado");
            }
            i++;
        }
    }

    fprintf(saida, "Nome,Curso,Media,Situacao\n");

    for (int j = 0; j < i; j++) {   
        fprintf(saida, "%s,  %s,  %.2f, %s\n", nomes[j], cursos[j], media[j], situacao[j]);
    }
    
    // Feche os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}
