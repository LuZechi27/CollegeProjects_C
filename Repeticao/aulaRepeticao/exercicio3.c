/*
3- Faça um programa para mostrar a tabuada dos
números de 1 a 10.
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, j, p;

    for (i = 1; i <= 10; i++ ) {
        printf("\n");
        for (j = 1; j <= 10; j++)
        {
            p = i*j;
            printf("%d x %d = %d\n", i, j, p);
        }
    }
}