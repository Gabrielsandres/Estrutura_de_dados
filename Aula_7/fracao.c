#include<stdio.h>
#include "fracao.h"

// forma de utilização:
// Fracao X = criarFracao(3 , 9);
// Criar a fração 3/9 para ser atribuida a X

Fracao criarFuncao(int numerador, int denominador){
    Fracao f;
    f.numerador = numerador;
    f.denominador = denominador;
    return (f);
}

int mdc(int a, int b){

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
    
}

// forma de utilização:
// Fracao X = criarFracao(3 , 9);
// X = simplificarFracao(X);
// Simplificação da fração X = 3/9.

Fracao simplificarFracao(Fracao f){

    int gcd = mdc(f.numerador, f.denominador);
    f.numerador = f.numerador/gcd;
    f.denominador = f.denominador/gcd;

    return (f);
}

//Somar Fração

Fracao somarFracao(Fracao a, Fracao b){
    Fracao resultado;
    resultado.numerador = a.numerador * b.denominador + a.denominador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    resultado = simplificarFracao(resultado);
    return (resultado);
}

//Subtrair fracao

Fracao subtrairFracao (Fracao a, Fracao b){

    Fracao resultado;
    resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    resultado = simplificarFracao(resultado);
    return (resultado);
}

//Multiplicar fracao

Fracao multiplicarFracao (Fracao a, Fracao b){

    Fracao resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    resultado = simplificarFracao(resultado);
    return (resultado);
}

//Dividir fracao

Fracao dividirFracao (Fracao a, Fracao b){

    Fracao resultado;
    resultado.numerador = a.numerador * b.denominador;
    resultado.denominador = a.denominador * b.numerador;
    resultado = simplificarFracao(resultado);
    return (resultado);
}