#include <stdio.h>
#include <stdlib.h>

#include "fracao.h"


int main () {
    
    Fracao f1 = criarFuncao(1 , 2);
    Fracao f2 = criarFuncao(3 , 4);

    Fracao soma = somarFracao(f1,f2);
    Fracao subtracao = subtrairFracao(f1,f2);
    Fracao multiplicacao = multiplicarFracao(f1,f2);
    Fracao divisao = dividirFracao(f1,f2);

    printf("\nPrimeira funcao: %d/%d: ", f1.numerador, f1.denominador);
    printf("\nSegunda funcao: %d/%d: ", f2.numerador, f2.denominador);
    printf("\nSoma: %d/%d: ", soma.numerador, soma.denominador);
    printf("\nSubtracao: %d/%d: ", subtracao.numerador, subtracao.denominador);
    printf("\nMultiplicacao: %d/%d: ", multiplicacao.numerador, multiplicacao.denominador);
    printf("\nDivisao: %d/%d: ", divisao.numerador, divisao.denominador);

    return 0;








    
}

