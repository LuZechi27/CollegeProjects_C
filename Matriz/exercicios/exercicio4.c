/*
4- Faça um programa que crie uma matriz A de
tamanho n x n de valores inteiros informados pelo
usuário. O programa deverá verificar se A é uma matriz
identidade e imprimir uma mensagem informando o
usuário. Considere que a matriz identidade possui
todos os elementos da diagonal principal iguais a 1 e
os demais elementos iguais a 0, como no exemplo:
*/
#include <stdio.h>

void fillMatrix(int size, int mat[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("m(%d , %d) = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int size, int mat[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf(" %d |", mat[i][j]);
        }
        printf("\n");
    }
}

int isIdentity(int size, int mat[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0 ; j < size; j++)
        {
            if ((i == j && mat[i][j] != 1)||( i != j && mat[i][j] != 0))
                return 0;
        }
    }
    return 1;
}

int main()
{
    int size;

    printf("Informe o tamanho da matriz: ");
    scanf("%d", &size);

    int matrix[size][size];

    printf("Preencha a matriz\n");
    fillMatrix(size, matrix);
    printf("\n");
    printMatrix(size, matrix);
    printf("\n");
    if (isIdentity(size, matrix))
    {
        printf("A matriz é identidade!\n");
    } else {
        printf("A matriz não é identidade!\n");
    }
    return 0;
}