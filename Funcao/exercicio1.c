/*
1- Faça uma função chamada calcularSerie() que
calcule e apresente os primeiros 8 termos da série a
seguir.
Soma = 100/0! + 99/1! + 98/2! + 97/3! + ...
A função deverá chamar outra função que receba um
inteiro >= 0 como parâmetro e retorne o seu fatorial,
para calcular cada termo da série. A função deverá
apresentar cada termo da série, calcular a soma total
dos termos e retornar a soma, para ser impressa pelo
programa principal.
*/
#include <stdio.h>
#include <locale.h>

double fatorial(long int f)
{
    if (f == 0 || f == 1)
        return 1;
    else
        return f * fatorial(f-1);
}

double calculaSerie(int termos)
{
    double soma, numerador;
    long int i;
    numerador = 100;
    soma = 0;

    printf("\nSérie: ");
    for (i = 0; i <= termos; i++)
    {
        printf("%.0f/%ld! + ", numerador, i);
        soma += numerador / fatorial(i);
        numerador--;
    }
    printf("...\n");
    return soma;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    double resultado;
    int termos = 8;

    resultado = calculaSerie(termos);
    printf("\nResultado = %.2f\n", resultado);
}