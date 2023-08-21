#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
 
    FILE *arquivo;

    arquivo = fopen("saida.txt", "a");

    if (arquivo == NULL){
        printf("Erro ao exibir o arquivo.\n");
        exit(1);
    }

    const char *mensagem = "O anterior gerou um erro, a string foi inserida na mesma linha!\n";
    fputs(mensagem, arquivo);

    fclose(arquivo);
    return 0;
}