#ifndef FRACAO_H
#define FRACAO_H

typedef struct 
{
    int numerador;
    int denominador;

} Fracao;

Fracao criarFuncao(int numerador, int denominador);

Fracao simplificarFracao(Fracao f);

Fracao somarFracao(Fracao a, Fracao b);

Fracao subtrairFracao(Fracao a, Fracao b);

Fracao multiplicarFracao (Fracao a, Fracao b);

Fracao dividirFracao (Fracao a, Fracao b);

int mdc (int a, int b);

#endif

