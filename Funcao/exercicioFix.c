/*
Crie um programa para resolver equações do 2 o grau. Faça
uma função para calcular o delta, uma função para calcular
uma raíz real e outra função para calcular duas raízes
reais. Considere: ax2 + bx + c = 0 Obs: a deve ser diferente
de 0
delta = b 2 - 4 * a * c
Se delta < 0, não existe raiz real
Se delta = 0, existe uma raiz real:
x = (-b) / (2 * a)
Se delta > 0, existem duas raízes reais:
x1 = (- b + raiz quadrada de delta) / (2 * a)
x2 = (- b - raiz quadrada de delta) / (2 * a)
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>

float Raiz1(float a, float b)
{
    return ( -b ) / ( 2 * a );
}

void Raiz2(float a, float b, float delta, float *x1, float *x2)
{
    *x1 = ( -b + sqrt(delta)) / ( 2 * a);
    *x2 = ( -b - sqrt(delta)) / ( 2 * a);
}

float Delta(float a, float b, float c)
{
    return pow(b, 2) - 4 * a * c;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    float a, b, c, delta, x1, x2;
    x1 = 0; x2 = 0;

    printf("Digite, em ordem, os valores de A, B, e C da equação Ax² + Bx + C = 0: ");
    scanf("%f%f%f", &a, &b, &c);

    delta = Delta(a, b, c);

    if (delta > 0)
    {
        Raiz2(a, b, delta, &x1, &x2);
        printf("As raízes são %.2f e %.2f\n", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = Raiz1(a, b);
        printf("A raíz é %.2f\n", x1);
    }
    else {
        printf("Não existe raíz real!\n");
    }
    return 0;
}