/*
1. Em geometria analítica, dois vetores podem ser definidos como a=<a1,a2,a3> e
b=<b1,b2,b3>. Escreva um programa que leia dois vetores (a e b) de três posições
cada e efetue o produto escalar entre eles. O produto escalar é obtido por ab =
a1b1+a2b2+a3b3.
*/
#include <stdio.h>

void fillVector(int size, int vec[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &vec[i]);
    }
}

long int product(int size, int vecA[], int vecB[])
{
    int i;
    long int prod = 0;
    for (i = 0; i < size; i++)
    {
        prod += vecA[i] * vecB[i];
    }
    return prod;
}

int main()
{
    int size;

    printf("Informe o tamanho dos vetores: ");
    scanf("%d", &size);

    int vectorA[size], vectorB[size];
    long int product_;

    printf("Preencha o vetor A: ");
    fillVector(size, vectorA);
    printf("Preencha o vetor B: ");
    fillVector(size, vectorB);

    product_ = product(size, vectorA, vectorB);

    printf("\nO produto escalar entre os vetores é:");
    printf(" %ld", product_);
    printf("\n");

    return 0;
}