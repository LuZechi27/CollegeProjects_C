/*
3. Faça um programa que leia três notas de provas de uma turma de 50 alunos (3
notas para cada aluno). Para cada aluno, o programa deve calcular a média
ponderada como segue: Média = (nota1*2 + nota2*4 + nota3*3 ) / 10. Além de
mostrar a média de cada aluno, o programa deve mostrar uma mensagem
"Aprovado", caso a média seja maior ou igual a 6,0, e uma mensagem
"Reprovado", caso contrário. Ao final, o programa deve calcular e apresentar a
média geral da turma.
*/
#include <stdio.h>
#include <locale.h>

int main()
{
    int alunos = 3;

    setlocale(LC_ALL,"Portuguese");

    float nota1, nota2, nota3, soma, media;
    int i;

    for (i = 1; i <= alunos; i++ )
    {
        printf("\nInforme as 3 notas em sequencia do %d aluno: ",i);
        scanf("%d%d%d",&nota1, &nota2, &nota3);
    }
}