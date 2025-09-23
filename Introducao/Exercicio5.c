#include<stdio.h>
/*
Dados três valores X, Y e Z, verifique se eles podem
ser os comprimentos dos lados de um triângulo. Se
forem, verifique se é um triângulo equilátero,
isósceles ou escaleno. Se não formarem um
triângulo, escreva uma mensagem informando que
não é triângulo. Considere que:
– O comprimento de cada lado do triângulo é menor do que
a soma dos outros dois lados.
– O triângulo equilátero tem três lados iguais.
– O triângulo isósceles tem o comprimento de dois lados
iguais.
– O triângulo escaleno tem os três lados diferentes
*/
int main()
{
    //Coleta os valores dos comprimentos
    float x, y, z;
    printf("Digite 3 comprimentos para lados de triangulos: ");
    scanf("%f%f%f", &x, &y, &z);
    //Checa se não é nulo
    if (x && y && z)
    {   
        //Checa se forma triangulo
        if ((x < y + z)&&(y < x + z)&&(z < x + y))
        {   
            //equilatero
            if (x == y && y == z) {
                    printf("\nO triangulo é equilatero.\n");
                }
            //isosceles
            else if ((x == y)||(x == z)||(y == z)) {
                    printf("\nO triangulo é isosceles.\n");
                }
            //escaleno
            else {
                    printf("\nO triangulo é escaleno\n");
                }
        }
        else {
            printf("\nOs comprimentos nao formam um triangulo.\n");
        }
    }
    else {
        printf("\nOs comprimentos sao nulos.");
    }
}
