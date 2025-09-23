/*
5- Faça um programa que crie uma matriz A de
dimensão m x n e outra matriz B de dimensão n x p.
O programa deverá calcular e apresentar a
multiplicação de A por B
*/
#include <stdio.h>

void fillMatrix(int row, int col, int mat[][col])
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("m(%d , %d) = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int row, int col, int mat[][col])
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf(" %d |", mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(int row_1, int col_1, int row_2, int col_2, int matA[][col_1], int matB[][col_2], int matC[][col_2])
{
    int i, j, k, value;
    if (col_1 == row_2)
    {
        for (i = 0; i < row_1; i++)
        {
            for (j = 0; j < col_2; j++)
            {
                value = 0;
                for (k = 0; k < col_1; k++)
                {
                    value += matA[i][k] * matB[k][j];
                }
                matC[i][j] = value;
            }
        }
    }
}

int main()
{
    int sizeRowA, sizeColA, sizeRowB, sizeColB;

    printf("\nInforme a quantidade de linhas da matriz A: ");
    scanf("%d", &sizeRowA);
    printf("\nInforme a quantidade de colunas da matriz A: ");
    scanf("%d", &sizeColA);
    printf("\nInforme a quantidade de linhas da matriz B: ");
    scanf("%d", &sizeRowB);
    printf("\nInforme a quantidade de colunas da matriz B: ");
    scanf("%d", &sizeColB);

    int matrixA[sizeRowA][sizeColA], matrixB[sizeRowB][sizeColB];
    int matrixC[sizeRowA][sizeColB];

    if(sizeColA != sizeRowB)
    {
        printf("As matrizes não são multiplicáveis!");
    } else {
        printf("\nPreencha a matriz A:");
        fillMatrix(sizeRowA, sizeColA, matrixA);
        printMatrix(sizeRowA, sizeColA, matrixA);

        printf("\nPreencha a matriz B:");
        fillMatrix(sizeRowB, sizeColB, matrixB);
        printMatrix(sizeRowB, sizeColB, matrixB);

        multiply(sizeRowA, sizeColA, sizeRowB, sizeColB, matrixA, matrixB, matrixC);
        printf("\nMatriz retultante:\n");
        printMatrix(sizeRowA, sizeColB, matrixC);
    }
    return 0;
}