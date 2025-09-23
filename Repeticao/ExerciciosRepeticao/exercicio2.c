/*
2. Faça um programa que imprima os 20 primeiros números primos.
*/
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int i, n, j, resto, primo;
    
    i = n = primo = 1;
    while (i <= 20)
    {
        for (j = n-1; j > 1; j--)
        {
            resto = n % j;
            if (!resto)
                primo = 0;
        }
        if (n == 1){
            primo = 0;
        }
        if (primo){
            if (i != 20){
                printf("%d, ", n);
                i++;
            } else {
                printf("%d.\n", n);
                i++;
            }
        } else {
            primo = 1;
        }
        n++;
    }
}