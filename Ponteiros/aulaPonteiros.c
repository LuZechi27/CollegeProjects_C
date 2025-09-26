#include <stdio.h>

// int strlen(char *s)
// {
//     char *p = s;
//     while (*s != '\0')
//         s++;
//     return (int)(s - p);
// }

int main()
{
    // int a = 10;
    // int *b;
    // printf("Conteudo de a: %d\n", a);
    // printf("Endereco de a: %d\n", &a);
    // b = &a;
    // printf("Conteudo de b: %d\n", b);
    // printf("Conteudo de a: %d\n", *b);
    // *b = 15; // atribuicao indireta
    // printf("Conteudo de a: %d\n", a);
    // printf("Conteudo de a: %d\n", *b);
    // printf("Conteudo de a: %d\n", *(&a));

    // int x = 77, *p;
    // p = &x;

    // printf("Valor de i: %d\n", x);
    // *p = 27;
    // printf("Novo valor: %d\n", x);

    // int var = 20, *pv;
    // pv = &var;

    // *pv = *pv / 5;

    // printf("%d\n", var);

    // int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int i, *pv = &vet[9];

    // for (i = 0; i < 10; i++)
    // {
    //     printf("%d | ", *pv);
    //     pv--;
    // }

    // int mat[2][3] = {{1,2,3},{4,5,6}};
    // int i, *p = &mat[0][0];

    // for (i = 0; i < 6; i++)
    // {
    //     printf("%d | ", *p);
    //     p++;
    // }

    // int vet[6] = {1,2,3,4,5,6};
    // int i;

    // for (i = 0; i < 6; i++)
    // {
    //     printf("%d | ", *(vet+i));
    // }

    // int i;
    // char *p;
    // char frase[] = {"Aprendendo a usar ponteiros!"};
    // /*acessando os elementos do vetor diretamente pelo
    // nome*/
    // for (i = 0; frase[i] != '\0'; i++)
    //     putchar(frase[i]);
    // /*acessando os elementos do vetor indiretamente por
    // meio de ponteiro*/
    // for (p = frase; *p != '\0'; p++)
    //     putchar(*p);

    // char nome[100];
    // printf("Digite uma string :");
    // gets(nome);
    // printf("\nTamanho da string : % d", strlen(nome));

    return 0;
}