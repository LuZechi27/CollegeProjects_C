/*
3- Crie um programa que preencha uma matriz 3x3 de
números inteiros e verifique se a matriz é simétrica.
A matriz será simétrica se e somente se todo
elemento A[i,j] = A[j,i]
*/
#include <stdio.h>

void fillMatrix(int mat[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("m(%d , %d) = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int isSymetric(int mat[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (mat[i][j] != mat[j][i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int matrix[3][3];

    fillMatrix(matrix);
    if(isSymetric(matrix)) {
        printf("A matriz é simétrica!\n");
    } else {
        printf("A matriz não é simétrica!\n");
    }
    return 0;
}
