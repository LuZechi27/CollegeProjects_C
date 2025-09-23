#include <stdio.h>
# define max 5

int main()
{
    int vet[max], i;
    char nome[40];

    printf("Digite os valores do vetor: ");
    for (i = 0; i < max; i++)
        scanf("%d", &vet[i]);

    for (i = 0; i < max; i++)
        printf("%d | ", vet[i]);

    printf("\nEntre com o nome: ");
    scanf("%s", nome);
    printf("Nome : %s\n", nome);
}