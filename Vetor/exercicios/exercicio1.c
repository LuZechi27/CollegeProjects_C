/*
- Faça um programa que preencha vetor com oito números
inteiros, calcule e mostre dois vetores resultantes. O
primeiro vetor deve conter os números positivos e o
segundo deve conter os números negativos. Atenção:
cada vetor terá no máximo oito posições, que podem
não ser completamente usadas. Não deve haver
posições vazias entre dois valores. 
*/
#include <stdio.h>
#define N 8

void fillVector(int vec[])
{
    int i;
    printf("Informe os valores do vetor: ");
    for (i = 0; i < N; i++)
        scanf("%d", &vec[i]);
}

void printVector(int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d | ", vec[i]);
    printf("\n");
}

void newVecs(int vec[],int size, int vecPos[],int vecNeg[],int *pos,int *neg)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (vec[i] >= 0)
        {
            vecPos[(*pos)] = vec[i];
            (*pos)++;
        }
        else {
            vecNeg[*neg] = vec[i];
            (*neg)++;
        }
    }
}

int main()
{
    int vector[N], vectorPos[N], vectorNeg[N], pos = 0, neg = 0;

    //preenche e printa o vetor
    fillVector(vector);
    printVector(vector, N);
    printf("\n");

    newVecs(vector, N, vectorPos, vectorNeg, &pos, &neg);
    
    //printa o vetor dos positivos
    printVector(vectorPos, pos);
    printf("\n");

    //printa o vetor dos negativos
    printVector(vectorNeg, neg);
    printf("\n");
    return 0;
}
