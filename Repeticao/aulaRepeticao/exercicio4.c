/*
4- Faça um programa que leia um número inteiro >= 0 e
calcule o seu fatorial.
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int n, fat, i;
    do {
        printf("\nDigite um número inteiro positivo: ");
        scanf("%d", &n);
        if (n < 0){
            printf("\nO número precisa ser inteiro positivo!\n");
        }
    } while (n < 0);

    fat = n;
    for (i = n-1; i > 0; i-- )
    {
        fat = fat * i;
    }

    if (n == 0){
        fat = 1;
    }

    printf("%d! = %d\n", n, fat);
}