/*Escreva um programa que leia um arquivo texto contendo uma lista de compras em que cada linha possui o nome
do produto, a quantidade e o valor unitário de cada item para, em seguida, informar o valor total da compra.*/

#include<stdio.h>
#include<stdlib>

int main(){
    FILE *arquivo;

    arquivo = fopen("lista_compra.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[100];

    while (fgets())
    {
        /* code */
    }
    
}