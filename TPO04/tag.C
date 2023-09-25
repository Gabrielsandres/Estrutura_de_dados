#include <stdio.h>
#include <stdlib.h>


void removeTags(char *text) {
    int inTag = 0; 
    int j = 0; 

    for (int i = 0; text[i]; i++) {
        if (text[i] == '<') {
            inTag = 1;
            continue;
        }
        if (text[i] == '>') {
            inTag = 0;
            continue;
        }
        if (!inTag) {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}


int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[1000];

    printf("Digite o nome do arquivo HTML de entrada: ");
    scanf("%s", inputFileName);

    
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Nao foi possivel abrir o arquivo de entrada.\n");
        return 1;
    }

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", outputFileName);

    
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        printf("Nao foi possivel criar o arquivo de saida.\n");
        fclose(inputFile);
        return 1;
    }

    
    while (fgets(line, sizeof(line), inputFile)) {
        removeTags(line);
        fputs(line, outputFile);
    }

    printf("As tags HTML foram removidas com sucesso.\n");

    
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
