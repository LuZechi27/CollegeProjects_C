/*
2) Altere o programa 1) para imprimir todos os nomes
que contenham uma letra qualquer fornecida pelo
usuário.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 20

void getNames(int size, char str[][Max])
{
    int i;
    for (i = 0; i < size; i++)
    {
        fgets(str[i], Max, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
}

int filterVector(int size, char str[][Max], char strFilt[][Max], char let)
{
    int i, j, sizeFiltered = 0, flag;
    for (i = 0; i < size; i++)
    {
        flag = 0;
        for (j = 0;str[i][j] != '\0' && !flag; j++)
        {
            if (str[i][j] == let)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            strcpy(strFilt[sizeFiltered], str[i]);
            sizeFiltered++;
        }
    }
    return sizeFiltered;
}

void sortVector(int size, char str[][Max])
{
    int flag, i, comp;
    char buffer[Max];
    flag = 1;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < size - 1; i++)
        {
            comp = strcmp(str[i], str[i+1]);
            if (comp > 0)
            {
                strcpy(buffer, str[i]);
                strcpy(str[i], str[i+1]);
                strcpy(str[i+1], buffer);
                flag = 1;
            }
        }
    }
}

void printVectorStrings(int size, char str[][Max])
{
    int i;
    for (i = 0; i < size; i++)
    {
        puts(str[i]);
    }
    puts("\n");
}

int main()
{
    int size = 10, sizeFiltered;
    char vectorStrings[size][Max], vectorFiltered[size][Max], letter;

    printf("\nInsira os %d nomes: ", size);
    getNames(size, vectorStrings);
    
    printf("Informe uma letra minúscula: ");
    scanf("%c", &letter);

    sizeFiltered = filterVector(size, vectorStrings, vectorFiltered, letter);

    printf("\nNomes ordenados com a letra %c:\n", letter);
    sortVector(sizeFiltered, vectorFiltered);
    printVectorStrings(sizeFiltered, vectorFiltered);

    return 0;
}