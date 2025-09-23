/*
2- Crie um programa principal que implemente funções
para:
a) Receber por parâmetro um vetor de números
inteiros e um valor N indicando o seu tamanho e
preencher o vetor com valores fornecidos pelo
usuário.
b) Receber por parâmetro um vetor de números
inteiros e um valor N indicando o seu tamanho e
imprimir os elementos do vetor.
c) Receber um vetor de números inteiros e um valor
N indicando o seu tamanho e retornar a soma de
todos os elementos do vetor.
d) Receber por parâmetro um vetor de números
inteiros e seu tamanho e inverter a ordem dos
elementos do vetor.
*/
#include <stdio.h>
#include <locale.h>
#define N 5

void fillVector(int vec[], int size)
{
    int i;
    printf("Informe os valores inteiros para o vetor: ");
    for (i = 0; i < size; i++)
        scanf("%d", &vec[i]);
}

void printVector(int vec[], int size)
{
    int i;
    printf("Valores:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d | ", vec[i]);
    }
    printf("\n");
}

int somVector(int vec[], int size)
{
    int i, some = 0;
    for (i = 0; i < size; i++)
        some += vec[i];
    return some;
}

void invertVector(int vec[], int size)
{
    int buffer, i;
    for (i = 0; i < size - i; i++)
    {
        buffer = vec[i];
        vec[i] = vec[size - (i + 1)];
        vec[size - (i + 1)] = buffer;
    }
}

int main()
{
    //usa set locale
    setlocale(LC_ALL,"Portuguese");
    
    int vector[N], some;
    
    //preenche o vetor e printa
    fillVector(vector, N);
    printVector(vector, N);
    
    //soma os valores e printa
    some = somVector(vector, N);
    printf("\nSoma : %d\n", some);
    
    //inverte o vetor e printa
    invertVector(vector, N);
    printVector(vector, N);
    
    return 0;
}