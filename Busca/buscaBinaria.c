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

int buscaSequencial(int *vec, int numero, int tamanho, int *comp)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (vec[i] == numero)
        {
            (*comp)++;
            return i;
        }
        (*comp)++;
    }
    return -1;
}

int buscaBinaria(int *vec, int inicio, int fim, int num, int *comp)
{
    int i = inicio;
    int j = fim;
    int meio = (inicio + fim) / 2;

    if (inicio > fim)
    {
        (*comp)++;
        return -1;
    }
    if (vec[meio] == num)
    {
        (*comp)++;
        return meio;
    }
    else
    {
        if (vec[meio] > num)
        {
            (*comp)++;
            return buscaBinaria(vec, inicio, meio - 1, num, comp);
        }
        else
        {
            return buscaBinaria(vec, meio + 1, fim, num, comp);
        }
    }
    return -1;
}

int main()
{
    srand(time(NULL));

    int *vector = (int *)malloc(500 * sizeof(int));
    int i, size = 500;

    for (i = 0; i < size; i++)
        *(vector + i) = rand() % 1000;

    printf("\nVetor Aleatório:\n");
    printVector(vector, size);

    mergeSort(vector, size);

    printf("\nVetor Aleatório Ordenado:\n");
    printVector(vector, size);

    int numero, compSequencial = 0, compBinaria = 0;
    int indiceSeq, indiceBin;

    printf("\nEscolha um numero a ser procurado no vetor: ");
    scanf("%d", &numero);

    indiceSeq = buscaSequencial(vector, numero, size, &compSequencial);
    printf("\nBusca Sequencial:\n");
    if (indiceSeq >= 0)
    {
        printf("Índice do número no vetor: %d\n", indiceSeq);
        printf("Número escolhido: %d\n", numero);
        printf("Numero encontrado: %d\n", vector[indiceSeq]);
        printf("Total de comparações: %d\n", compSequencial);
        printf("\n");
    }
    else
    {
        printf("Numero não encontrado no vetor!\n");
    }

    indiceBin = buscaBinaria(vector, 0, size - 1, numero, &compBinaria);
    printf("\nBusca Binária:\n");
    if (indiceBin >= 0)
    {
        printf("Índice do número no vetor: %d\n", indiceBin);
        printf("Número escolhido: %d\n", numero);
        printf("Numero encontrado: %d\n", vector[indiceBin]);
        printf("Total de comparações: %d\n", compBinaria);
        printf("\n");
    }
    else
    {
        printf("Numero não encontrado no vetor!\n");
    }
}