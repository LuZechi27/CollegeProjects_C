/*
Faça um programa para resolver equações
do 2 o grau. Considere:
ax² + bx + c = 0 Obs: a deve ser diferente de 0
delta = b² - 4 * a * c
Se delta < 0, não existe raiz real
Se delta = 0, existe uma raiz real
x = (-b) / (2 * a)
Se delta > 0, existem duas raízes reais
x1 = (- b + raiz quadrada de delta) / (2 * a)
x2 = (- b - raiz quadrada de delta) / (2 * a)
*/
#include<stdio.h>
#include<math.h>

int main()
{
    float x1, x2, raizD, delta, a, b, c;
    printf("Informe os numeros A, B e C da equação Ax² + Bx + C = 0 com A diferente de 0: ");
    scanf("%f%f%f",&a,&b,&c);

    if (a != 0)
    {
        delta = pow(b,2) - 4*a*c;
        if (delta >= 0) {
            if (delta == 0){
                x1 = x2 = (-b)/ 2*a;
                printf("\nA equação possui duas raízes iguais de valor %.2f\n", x1);
            }
            else {
                raizD = sqrt(delta);
                x1 = (-b + raizD)/ 2*a;
                x2 = (-b - raizD)/ 2*a;
                printf("\nA equação possui raízes iguais a %.2f e %.2f\n", x1, x2);
            }
        }
        else {
            printf("\nA equação não posui raízes reais.\n");
        }
    }
    else {
        printf("\nA precisa ser diferente de 0.\n");
    }
}
