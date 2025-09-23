#include <stdio.h>

// float somarRetorno(float n1, float n2)
// {
//     return n1 + n2;
// }

// void somarVoid(float n1, float n2)
// {
//     printf("Soma = %.2f\n",n1 + n2);
// }

// int main()
// {
//     float x, y, result;
//     x = 10; y = 5;
//     result = somarRetorno(x, y);
//     printf("Soma = %.2f\n", result);
//     somarVoid(x, y);
// }

void soma(int i, int j, int *k)
{
    *k = i + j;
}

int main()
{
    int n1, n2, s = 0;

    printf("N1 = ");
    scanf("%d", &n1);
    printf("N2 = ");
    scanf("%d", &n2);

    soma(n1, n2, &s);

    printf("Soma = %d\n", s);
}