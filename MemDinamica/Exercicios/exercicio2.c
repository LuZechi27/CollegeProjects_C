/*
2- Construa uma função que receba dois
parâmetros m e n, aloque uma matriz de ordem
m x n e retorne um ponteiro para a matriz
alocada em tempo de execução. Crie ainda
outra função que receba por parâmetro um
ponteiro para matriz e libere a área de
memória alocada. Finalmente, crie um
programa (main) que teste/use as duas
funções criadas.
*/
#include <stdio.h>
#include <stdlib.h>

int *createMatrix(int m, int n)
{
    int i, j, *p;
    p = (int *) malloc(m * n * sizeof(int));
    if (p != NULL)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &p[i*n+j]);
            }
        }
    }
    return p;
}

void freeMatrix(int *mat)
{
    free(mat);
}

int main()
{
    int *matrix, m, n, i, j;
    printf("informe a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("informe a quantidade de colunas da matriz: ");
    scanf("%d", &n);

    matrix = (int *) createMatrix(m, n);

    if (matrix != NULL)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d | ", matrix[i*n+j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    freeMatrix(matrix);
    return 0;
}