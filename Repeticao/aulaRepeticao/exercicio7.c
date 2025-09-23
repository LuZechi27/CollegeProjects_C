/*
7- Faça um programa que mostre os 8 primeiros termos
da sequência de Fibonacci.
Ex: 0, 1, 1, 2, 3, 5, 8,13, 21,34, 55...
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, termoAnt1 = 0, termo, termoAnt2 = 1;
    printf("\n0, ");
    for (i = 0; i <= 8; i++ ) 
    {
        termo = termoAnt1 + termoAnt2;
        printf("%d, ",termo);
        termoAnt2 = termoAnt1;
        termoAnt1 = termo;
    }
    printf("\n");
}