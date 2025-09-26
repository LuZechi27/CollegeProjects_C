/*
Pratique a declaração e a utilização de
ponteiros para referenciar os elementos de
um vetor.
– defina um vetor de 10 elementos inteiros
– defina um ponteiro para inteiro
– preencha o vetor usando o ponteiro definido para referenciar cada posição do vetor
– imprima os elementos do vetor usando o ponteiro
*/
#include <stdio.h>

int main()
{
    int vector[10], *p = vector;
    int i;
    puts("Digite os valores do vetor:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", p + i);

    p = vector;
    for (i = 0; i < 10; i++)
        printf("%d | ",*(p + i));

    return 0;
}