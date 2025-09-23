/*
Faça um programa que receba dois números e
execute uma das operações listadas a seguir, de
acordo com a escolha do usuário. Se for digitada
uma opção inválida, mostre a mensagem de erro e
finalize o programa. As opções são:
1. Primeiro número elevado ao segundo número;
2. Raiz quadrada de cada número;
3. Raiz cúbica de cada número;
4. Produto dos números;
OBS: Usar comando de seleção múltipla (case)
*/
#include<stdio.h>
#include<math.h>

int main()
{
    int opt;
    float n1, n2;
    printf("\nInforme dois numeros: ");
    scanf("%f%f",&n1,&n2);

    printf("\nEscolha aopção:\n");
    printf("\n1. Primeiro número elevado ao segundo número;\n");
    printf("2. Raiz quadrada de cada número;\n");
    printf("3. Raiz cúbica de cada número;\n");
    printf("4. Produto dos números;\n");

    scanf("%d", &opt);

    switch (opt) {
        case 1 : printf("%.2f\n", pow(n1, n2));
            break;
        case 2 : printf("%.2f, %.2f\n",sqrt(n1), sqrt(n2));
            break;
        case 3 : printf("%.2f, %.2f\n", cbrt(n1),cbrt(n2));
            break;
        case 4 : printf("%.2f\n", (n1 * n2));
            break;
        default : printf("Erro, opção inválida.\n");
    }
}