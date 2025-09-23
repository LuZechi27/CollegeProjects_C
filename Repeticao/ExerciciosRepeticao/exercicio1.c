/*
1. Elabore um programa que efetue a soma de todos os números ímpares que são
múltiplos de 3 e que se encontram no intervalo de 1 a 500.
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int soma = 0, i;

    for (i = 3; i <= 500; i+=3)
    {
        if (i % 2 != 0){
            soma += i;
        }
    }
    printf("\n%d\n", soma);
}