/*
4- Faça um programa que crie um arquivo binário
denominado “Notas_AP2S2.bin” com registros de alunos
que cursaram a disciplina de AP2S2. Cada linha do arquivo
terá o nome de um aluno, o seu prontuário, a nota de cada
uma das 3 provas realizadas na disciplina, bem como dos 2
trabalhos, conforme no exemplo a seguir:

Maria sc365987 6.5 4.0 7.5 5.0 7.8
Roberto sc569874 4.5 3.0 6.0 5.0 8.6
Carlos sc222222 7.0 8.0 9.0 10.0 10.0
Pedro sc112141 9.0 6.0 10.0 7.0 5.0

O programa deverá ler o arquivo criado e deverá implementar
funções para:

a) Calcular e apresentar a média semestral de cada estudante
(os pesos de cada avaliação devem ser fornecidos pelo
usuário);

b) Apresentar o nome e a média dos estudantes que
obtiveram média final menor que 6.0;

c) Apresentar o nome e a média do estudante que obteve a
menor média final (se houver mais de um aluno, a função
deverá exibir todos);

d) Apresentar o nome e a média do estudante que obteve a
maior média final (se houver mais de um aluno, a função
deverá exibir todos).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    char prontuario[9];
    float notas_provas[3];
    float notas_trabalho[2];
} Aluno;

int ler_alunos_arq(Aluno *aluno)
{
    FILE *arq;
    int i, j;
    char c, *str;

    str = (char *)malloc(30 * sizeof(char));

    if ((arq = fopen("C:/Users/LGPHP/Documents/VSCode Programas/Luiz/APR2/Arquivos/Exercicios/Notas_AP2S2.bin", "rb+")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    for (i = 0; !feof(arq); i++)
    {
        c = ' ';
        j = 0;
        while (c != '\0' && !feof(arq));
        {
            fread(&c, sizeof(char), 1, arq);
            str[j] = c;
            if (ferror(arq))
            {
                printf("%d, %d",i ,j);
                perror("Erro na leitura do nome");
                return 0;
            }
            j++;
        }
        strcpy(aluno[i].nome, str);
        printf("%s", str);
        if (feof(arq))
        {
            return 0;
        }

        if ((fread(aluno[i].prontuario, sizeof(char), 9, arq)) != 9)
        {
            perror("Erro na leitura do prontuario");
            return 0;
        }
        if ((fread(aluno[i].notas_provas, sizeof(float), 3, arq)) != 3)
        {
            perror("Erro na leitura das notas das provas");
            return 0;
        }
        if ((fread(aluno[i].notas_trabalho, sizeof(float), 2, arq)) != 2)
        {
            perror("Erro na leitura das notas dos trabalhos");
            return 0;
        }
        if (ferror(arq))
        {
            perror("Erro");
            return 0;
        }
        if (feof(arq))
        {
            return 0;
        }
    }
    fclose(arq);
    return 1;
}

int gravar_alunos_arq(Aluno *alunos, int tamanho)
{
    FILE *arq;
    int i, j;

    if ((arq = fopen("Notas_AP2S2.bin", "wb+")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; alunos[i].nome[j] != '\0'; j++)
            fwrite(&alunos[i].nome[j], sizeof(char), 1, arq);
        
        fwrite(&alunos[i].nome[j], sizeof(char), 1, arq);
        if (ferror(arq))
        {
            perror("Erro na gravacao do nome");
            return 0;
        }
        if ((fwrite(alunos[i].prontuario, sizeof(char), 9, arq)) != 9)
        {
            perror("Erro na gravacao do prontuario");
            return 0;
        }
        if ((fwrite(alunos[i].notas_provas, sizeof(float), 3, arq)) != 3)
        {
            perror("Erro na gravacao das notas das provas");
            return 0;
        }
        if ((fwrite(alunos[i].notas_trabalho, sizeof(float), 2, arq)) != 2)
        {
            perror("Erro na gravacao das notas dos trabalhos");
            return 0;
        }
        if (ferror(arq))
        {
            perror("Erro");
            return 0;
        }
    }
    fclose(arq);
    return 1;
}

int main()
{
    FILE *arq_notas;
    Aluno aluno[4];

    strcpy(aluno[0].nome, "Maria");
    strcpy(aluno[0].prontuario, "sc365987");
    aluno[0].notas_provas[0] = 6.5;
    aluno[0].notas_provas[1] = 4.0;
    aluno[0].notas_provas[2] = 7.5;
    aluno[0].notas_trabalho[0] = 5.0;
    aluno[0].notas_trabalho[1] = 7.8;

    strcpy(aluno[1].nome, "Roberto");
    strcpy(aluno[1].prontuario, "sc569874");
    aluno[1].notas_provas[0] = 4.5;
    aluno[1].notas_provas[1] = 3.0;
    aluno[1].notas_provas[2] = 6.0;
    aluno[1].notas_trabalho[0] = 5.0;
    aluno[1].notas_trabalho[1] = 8.6;

    strcpy(aluno[2].nome, "Carlos");
    strcpy(aluno[2].prontuario, "sc222222");
    aluno[2].notas_provas[0] = 7.0;
    aluno[2].notas_provas[1] = 8.0;
    aluno[2].notas_provas[2] = 9.0;
    aluno[2].notas_trabalho[0] = 10.0;
    aluno[2].notas_trabalho[1] = 10.0;

    strcpy(aluno[3].nome, "Pedro");
    strcpy(aluno[3].prontuario, "sc112141");
    aluno[3].notas_provas[0] = 9.0;
    aluno[3].notas_provas[1] = 6.0;
    aluno[3].notas_provas[2] = 10.0;
    aluno[3].notas_trabalho[0] = 7.0;
    aluno[3].notas_trabalho[1] = 5.0;

    if (!gravar_alunos_arq(aluno, 4))
    {
        perror("Erro");
        exit(0);
    }

    printf("Gravado com sucesso");

    if (!ler_alunos_arq(aluno))
    {
        perror("Erro");
        exit(0);
    }
        
    
    printf("arquivo lido com sucesso");


    return 0;
}