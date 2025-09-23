/*
6- Faça um programa que receba um numero N
fornecido pelo usuário e mostre os N termos da série a
seguir:
S = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m
Por fim, imprima a soma total da série.
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float m = 1, i, soma = 0;
    int n;
    do {
        printf("\nDigite um número inteiro: ");
        scanf("%d", &n);
        if (n <= 0){
            printf("\nO número precisa ser inteiro positivo.");
        }
    } while (n <= 0);

    for (i = 1; i <= n; i++) 
    {
        m = 2*i -1;
        soma += i/m;
        printf("O %.0f termo da série é %.0f/%.0f\n",i ,i ,m);
    }

    printf("\nA soma total da série é %.3f\n",soma);
}