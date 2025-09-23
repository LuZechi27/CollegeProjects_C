#include <stdio.h>
#include <string.h>

void mainTeste1()
{
    int i;
    char nomes[5][40];
    printf("Entre com os nomes ");
    for (i = 0; i < 5; i++)
    {
        fgets(nomes[i], 40, stdin);
        nomes[i][strcspn(nomes[i], "\n")];
    }
    printf("\nImprimindo os elementos da matriz: ");
    for (i = 0; i < 5; i++)
    {
        puts(nomes[i]);
    }
}

void mainTeste2()
{
    int i, j;
    char nomes[5][3][40];
    printf("Entre com os nomes: ");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            fgets(nomes[i][j], 40, stdin);
        }
    }
    printf("Imprimindo os nomes:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            puts(nomes[i][j]);
        }
    }
}

int main()
{
    mainTeste2();
}