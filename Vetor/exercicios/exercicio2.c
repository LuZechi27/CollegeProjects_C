/*
2- Faça um programa que preencha dois vetores A e B com dez
elementos numéricos cada um calcule e apresente um
vetor C resultante da intercalação deles.
*/
#include <stdio.h>
#define Tam 10

void fillVector(int vec[], int size)
{
    int i;
    printf("Informe os valores do vetor:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &vec[i]);
}

void interVecs(int vecC[], int vecA[], int vecB[], int size)
{
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        vecC[j++] = vecA[i];
        vecC[j++] = vecB[i];
    }
}

void printVector(int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d | ", vec[i]);
    printf("\n");
}

int main()
{
    int vectorA[Tam], vectorB[Tam], vectorC[2*Tam];

    //Preenche os vetores A e B
    printf("\nVetor A => ");
    fillVector(vectorA, Tam);
    printf("\nVetor B => ");
    fillVector(vectorB, Tam);

    //intercala os valores dos vetores
    interVecs(vectorC, vectorA, vectorB, Tam);
    printVector(vectorC, 2*Tam);

    return 0;
}