/*
1) Faça um programa que leia 10 nomes, ordene-os de
forma crescente e mostre-os na tela.
*/
#include <stdio.h>
#include <string.h>
#define Max 20
#define MaxVec 6

void getNames(int size, char str[][Max])
{
    int i;
    for (i = 0; i < size; i++)
    {
        fgets(str[i], Max, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
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
    int size = MaxVec;
    char vectorStrings[size][Max];

    printf("\nInsira os %d nomes: ", size);
    getNames(size, vectorStrings);
    printVectorStrings(size, vectorStrings);

    printf("\nNomes ordenados :\n");
    sortVector(size, vectorStrings);
    printVectorStrings(size, vectorStrings);

    return 0;
}