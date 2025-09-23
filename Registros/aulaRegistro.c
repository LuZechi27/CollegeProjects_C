#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int idade;
    char sexo;
    char nome[40];
}Pessoa;

typedef char string[100];

void fillVector(Pessoa vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        puts("Digite o nome da pessoa:");
        fgets(vec[i].nome, sizeof(vec[i].nome), stdin);
        vec[i].nome[strcspn(vec[i].nome, "\n")] = '\0';
        puts("Digite o sexo da pessoa:");
        scanf(" %c", &vec[i].sexo);
        puts("Digite a idade da pessoa:");
        scanf("%d", &vec[i].idade);
    }
}

void printVector(Pessoa vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("\nNome %d: %s", i, vec[i].nome);
        printf("\nSexo %d:  %c", i, vec[i].sexo);
        printf("\nIdade %d; %d\n", i, vec[i].idade);
    }
}

int main()
{
    Pessoa vetPessoas[3];
    int size = 3;

    fillVector(vetPessoas, size);
    printVector(vetPessoas, size);

    return 0;
}