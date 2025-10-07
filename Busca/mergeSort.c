#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

void merge(int *vector, int *temporary, int start, int midle, int end)
{
    int i = start;
    int j = midle + 1;
    int k = start;

    while (i <= midle && j <= end)
    {
        if (vector[i] <= vector[j])
            temporary[k++] = vector[i++];
        else
            temporary[k++] = vector[j++];
    }

    while (i <= midle)
        temporary[k++] = vector[i++];

    while (j <= end)
        temporary[k++] = vector[j++];

    for (i = start; i <= end; i++)
        vector[i] = temporary[i];
}

void mergeSortRec(int *vector, int *temporary, int start, int end)
{
    int midle = start + (end - start) / 2;

    if (start < end)
    {
        mergeSortRec(vector, temporary, start, midle);
        mergeSortRec(vector, temporary, midle + 1, end);
        merge(vector, temporary, start, midle, end);
    }
}

void mergeSort(int *vector, int size)
{
    int *temporary = (int *) malloc(size * sizeof(int));
    mergeSortRec(vector, temporary, 0, size - 1);
    free(temporary);
}

void printVector(int *vector, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d | ", *(vector + i));
    printf("\n");
}

int main()
{
    int vector[] = {84, 2, 15, -84, 45, 61, 8};
    int size = SIZE;

    printVector(vector, size);

    mergeSort(vector, size);

    printVector(vector, size);

    return 0;
}