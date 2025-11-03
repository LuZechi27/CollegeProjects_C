/*
Faça um programa em C que crie um vetor com 500números inteiros gerados aleatoriamente. Em seguida,
o programa deverá solicitar um valor do usuário a ser
buscado no vetor e verificar se o mesmo pertence ounão ao vetor, imprimindo a mensagem ao usuário.
Oprograma deverá implementar duas funções de buscano vetor: sequencial e binária.
Para realizar a buscabinária, você deverá criar o seu próprio algoritmo deordenação.
Obs: compare o número de comparações realizadas por
cada estratégia para encontrar o elemento procurado.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void merge(int *vec, int *temp, int inicio, int meio, int fim)
{
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim)
    {
        if (vec[i] <= vec[j])
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }

    while (i <= meio)
        temp[k++] = vec[i++];

    while (j <= fim)
        temp[k++] = vec[j++];

    for (i = inicio; i <= fim; i++)
        vec[i] = temp[i];
}

void mergeSortRec(int *vec, int *temp, int inicio, int fim)
{
    int meio = inicio + (fim - inicio) / 2;

    if (inicio < fim)
    {
        mergeSortRec(vec, temp, inicio, meio);
        mergeSortRec(vec, temp, meio + 1, fim);
        merge(vec, temp, inicio, meio, fim);
    }
}

void mergeSort(int *vec, int size)
{
    int *temp = (int *)malloc(size * sizeof(int));
    mergeSortRec(vec, temp, 0, size - 1);
    free(temp);
}

void printVector(int *vec, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d | ", *(vec + i));
    printf("\n");
}


int busca_insercao(int *vec, int inicio, int fim, int num)
{
    int meio = (inicio + fim) / 2;
    if (vec[meio] == num)
        return -1;
    if ((fim - inicio) <= 1)
        return inicio;
    if (vec[meio] < num)
        return busca_insercao(vec, meio + 1, fim, num);
    if (vec[meio] > num)
        return busca_insercao(vec, inicio, meio - 1, num);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *vector = (int *)malloc(50 * sizeof(int));
    int i, size = 50;

    for (i = 0; i < size; i++)
        *(vector + i) = rand() % 50;

    printf("\nVetor Aleatório:\n");
    printVector(vector, size);

    mergeSort(vector, size);

    printf("\nVetor Aleatório Ordenado:\n");
    printVector(vector, size);

    int numero;
    int indice;

    printf("\nEscolha um numero a ser procurado no vetor: ");
    scanf("%d", &numero);

    indice = busca_insercao(vector, 0, size - 1, numero);
    printf("\nBusca Binária:\n");
    if (indice >= 0)
    {
        printf("Índice do número no vetor: %d\n", indice);
        printf("Número escolhido: %d\n", numero);
        printf("Numero no indice: %d\n", vector[indice]);
        printf("Numero no ind. anterior: %d\n", vector[indice - 1]);
        printf("Numero no ind. posterior: %d\n", vector[indice + 1]);
        printf("\n");
    }
    else
    {
        printf("Numero já existe!\n");
    }
}
