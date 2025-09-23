/*
5- Fazer um programa que leia um conjunto de valores
correspondentes às notas que alunos obtiveram em
uma prova. Quando o valor fornecido for um número
negativo, significa que não existem mais pontos para
serem lidos. Após isso seu programa deverá:
a. Escrever quantas notas são maiores ou iguais a
6.0
b. Escrever quantas notas são maiores ou iguais a
4.0 e menores que 6.0
c. Escrever quantos notas são menores que 4.0
*/
#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float nota;
    int maior6 = 0, maior4 = 0, menor4 = 0;
    do {
        printf("\nDigite a nota: ");
        scanf("%f", &nota);
        if (nota >= 0)
        {
            if (nota >= 6){
                maior6++;
            } else if (nota >= 4){
                maior4++;
            }else {
                menor4++;
            }
        }
    } while (nota >= 0);
    
    printf("\nNotas maiores que 6 = %d\n", maior6);
    printf("Notas maiores que 4 e menores que 6 = %d\n", maior4);
    printf("Notas menores que 4 = %d\n", menor4);
    printf("Fim.\n");
}