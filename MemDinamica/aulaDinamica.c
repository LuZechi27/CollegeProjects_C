#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} data;

int main()
{
    //structs
    // data *d;
    // d = (data *) malloc(sizeof(data));
    // d -> dia = 31;
    // d -> mes = 12;
    // d -> ano = 2022;

    // printf("%d\n%d\n%d\n", d->dia, d->mes, d->ano);
    // free(d);

    // char *ptr;
    // ptr = (char *) malloc(1);
    // scanf("%c", ptr);
    // printf("%c\n", *ptr);
    // free(ptr);

    // //vetores 1d
    // int *v, n, i;
    // printf("Informe o valor de N: ");
    // scanf("%d", &n);
    // v = (int *) malloc(n * sizeof(int));
    // if (v != NULL)
    // {
    //     for (i = 0; i < n; i++)
    //         scanf("%d", &v[i]);
    //     for (i = n; i > 0; i--)
    //         printf("%d | ", v[i-1]);
    //     free(v);
    //     printf("\n");
    // }

    // int *p, n, i;

    // printf("Quantos numeros deseja no vetor?\n");
    // scanf("%d", &n);

    // p = (int *) calloc(n , sizeof(int));

    // if (!p)
    // {
    //     printf("Erro: Memoria insuficiente!");
    //     exit(0);
    // }
    // for (i = 0; i < n; i++)
    // {
    //     p[i] = i*i;
    //     printf("Elemento da posiçao %d = %d\n", i, p[i]);
    // }
    // free(p);

    // int *p, n1, n2, i;
    // printf("Quantos números deseja no vetor?\n");
    // scanf("%d", &n1);
    
    // p = (int *) malloc(n1 * sizeof(int));
    // /* Aloca
    // espaço para armazenar n
    // números inteiros.*/
        
    // if (!p)
    // { 
    //     printf ("Erro: Memoria Insuficiente !");
    //     exit(0);
    // }

    // for (i = 0; i < n1; i++)
    // {
    //     p[i] = i*i;
    //     printf("%d\n", p[i]);
    // }
    // /* O tamanho de p deve ser
    // modificado, por algum
    // motivo */
    // printf("Quantos números deseja no vetor?\n");
    // scanf("%d", &n2);

    // p = (int *) realloc(p, n2 * sizeof(int));

    // for (i = 0; i < n2; i++)
    // {
    //     if (i >= n1)
    //         p[i] = n2 * i * (i - 6);
    //     printf("%d\n", p[i]);
    // }
    // free(p);
}
