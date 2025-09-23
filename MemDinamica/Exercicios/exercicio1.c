/*
1- Faça uma função que receba um valor n e crie
dinamicamente um vetor de n elementos inteiros e
retorne um ponteiro. Em seguida, crie uma função que
receba um ponteiro para um vetor e um valor n e
imprima os n elementos desse vetor. Construa
também uma função que receba um ponteiro para um
vetor e libere esta área de memória. Por fim, crie uma
função principal que leia um valor n e chame a função de
alocação de memória. Depois, a função principal deve ler
os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor
criado e, finalmente, liberar a memória alocada através da
função criada para liberação.
*/
#include <stdio.h>
#include <stdlib.h>

int *createVectorDyn(unsigned int n)
{
    int i, *p;
    p = (int *) malloc(n * sizeof(int));
    if (p != NULL)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &p[i]);
    }
    return p;
}

void printVectorDyn(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d | ", vec[i]);
    printf("\n");
}

void freeVector(int vec[])
{
    free(vec);
}

int main()
{
    int n, *vector;
    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &n);
    printf("Informe os elementos do vetor: ");
    vector = (int *) createVectorDyn(n);
    if (vector != NULL)
    {
        printf("\n");
        printVectorDyn(vector, n);
    } else
    {
        printf("Erro ao alocar memoria.\n");
    }
    freeVector(vector);
    return 0;
}
