/*
2- Faça um programa que receba um número inteiro
maior que 1 e verifique se o número é primo.
Considere que um número primo é divisível apenas por
1 e por ele mesmo.
Obs: Faça três versões do programa, uma para
cada estrutura de repetição (for, while e do-
while).
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, i, resto;
    int primo = 1;
    printf("\nDigite um número: ");
    scanf("%d", &num);
    
    if (num){
        i = num - 1;
        while (i > 1)
        {
            resto = num % i;
            if (!resto)
                primo = 0;
            i--;
        }
        if (primo){
            printf("\nO número é primo!\n");
        }
        else {
            printf("\nO número não é primo!\n");
        }
    }
    printf("Fim.\n");
}