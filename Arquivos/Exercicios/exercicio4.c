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
    char *nome;
    char prontuario[9];
    float notas_provas[3];
    float notas_trabalho[2];
} Aluno;

int ler_alunos_arq(Aluno **alunos, int *tamanho_vet)
{
    FILE *arq;
    int i, j, len;

    if ((arq = fopen("Notas_AP2S2.bin", "rb+")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    /*
    Conteúdo do arquivo:

    [numero de elementos do vetor]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    ...
    */
    fread(tamanho_vet, sizeof(int), 1, arq);
    *alunos = (Aluno *)malloc((*tamanho_vet) * sizeof(Aluno));
    for (i = 0; i < *tamanho_vet; i++)
    {
        fread(&len, sizeof(int), 1, arq);
        (*alunos)[i].nome = (char *)malloc(len * sizeof(char));
        if ((*alunos)[i].nome == NULL)
        {
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if ((fread((*alunos)[i].nome, sizeof(char), len, arq)) != len)
        {
            perror("Erro na leitura do nome");
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if ((fread((*alunos)[i].prontuario, sizeof(char), 9, arq)) != 9)
        {
            perror("Erro na leitura do prontuario");
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if ((fread((*alunos)[i].notas_provas, sizeof(float), 3, arq)) != 3)
        {
            perror("Erro na leitura das notas das provas");
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if ((fread((*alunos)[i].notas_trabalho, sizeof(float), 2, arq)) != 2)
        {
            perror("Erro na leitura das notas dos trabalhos");
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if (ferror(arq))
        {
            perror("Erro");
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
        if (feof(arq))
        {
            fclose(arq);
            free(*alunos);
            free((*alunos)[i].nome);
            return 0;
        }
    }
    fclose(arq);
    return 1;
}

int gravar_alunos_arq(Aluno *alunos, int tamanho)
{
    FILE *arq;
    int i, j, len;

    if ((arq = fopen("Notas_AP2S2.bin", "wb+")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        fclose(arq);
        return 0;
    }
    /*
    Conteúdo do arquivo:

    [numero de elementos do vetor]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    [tamanho do nome][nome][prontuario][vetor das notas das provas][vet. notas trabalho]
    ...
    */
    fwrite(&tamanho, sizeof(int), 1, arq);
    for (i = 0; i < tamanho; i++)
    {
        len = strlen(alunos[i].nome) + 1;
        fwrite(&len, sizeof(int), 1, arq);
    
        if (fwrite(alunos[i].nome, sizeof(char), len, arq) != len)
        {
            perror("Erro na gravacao do nome");
            fclose(arq);
            return 0;
        }
        if ((fwrite(alunos[i].prontuario, sizeof(char), 9, arq)) != 9)
        {
            perror("Erro na gravacao do prontuario");
            fclose(arq);
            return 0;
        }
        if ((fwrite(alunos[i].notas_provas, sizeof(float), 3, arq)) != 3)
        {
            perror("Erro na gravacao das notas das provas");
            fclose(arq);
            return 0;
        }
        if ((fwrite(alunos[i].notas_trabalho, sizeof(float), 2, arq)) != 2)
        {
            perror("Erro na gravacao das notas dos trabalhos");
            fclose(arq);
            return 0;
        }
        if (ferror(arq))
        {
            perror("Erro");
            fclose(arq);
            return 0;
        }
    }
    fclose(arq);
    return 1;
}

int main()
{
    FILE *arq_notas;
    Aluno *alunos;
    int i, tamanho;
    
    if (!ler_alunos_arq(&alunos, &tamanho))
    {
        printf("Erro");
        alunos = (Aluno *)malloc(4 * sizeof(Aluno));
        tamanho = 4;

        alunos[0].nome = (char *)malloc(6 * sizeof(char));
        strcpy(alunos[0].nome, "Maria");
        strcpy(alunos[0].prontuario, "sc365987");
        alunos[0].notas_provas[0] = 6.5;
        alunos[0].notas_provas[1] = 4.0;
        alunos[0].notas_provas[2] = 7.5;
        alunos[0].notas_trabalho[0] = 5.0;
        alunos[0].notas_trabalho[1] = 7.8;


        alunos[1].nome = (char *)malloc(8 * sizeof(char));
        strcpy(alunos[1].nome, "Roberto");
        strcpy(alunos[1].prontuario, "sc569874");
        alunos[1].notas_provas[0] = 4.5;
        alunos[1].notas_provas[1] = 3.0;
        alunos[1].notas_provas[2] = 6.0;
        alunos[1].notas_trabalho[0] = 5.0;
        alunos[1].notas_trabalho[1] = 8.6;

        alunos[2].nome = (char *)malloc(7 * sizeof(char));
        strcpy(alunos[2].nome, "Carlos");
        strcpy(alunos[2].prontuario, "sc222222");
        alunos[2].notas_provas[0] = 7.0;
        alunos[2].notas_provas[1] = 8.0;
        alunos[2].notas_provas[2] = 9.0;
        alunos[2].notas_trabalho[0] = 10.0;
        alunos[2].notas_trabalho[1] = 10.0;

        alunos[3].nome = (char *)malloc(6 * sizeof(char));
        strcpy(alunos[3].nome, "Pedro");
        strcpy(alunos[3].prontuario, "sc112141");
        alunos[3].notas_provas[0] = 9.0;
        alunos[3].notas_provas[1] = 6.0;
        alunos[3].notas_provas[2] = 10.0;
        alunos[3].notas_trabalho[0] = 7.0;
        alunos[3].notas_trabalho[1] = 5.0;
    }
    else 
    {
        printf("arquivo lido com sucesso\n");
    }
    for (i = 0; i < tamanho; i++)
    {
        puts(alunos[i].nome);
    }
    

    

    if (!gravar_alunos_arq(alunos, 4))
    {
        perror("Erro");
        exit(0);
    }
    else 
    {
        printf("Gravado com sucesso");
    }
    for (i = 0; i < tamanho; i++)
    {
        free(alunos[i].nome);
    }
    free(alunos);
    
    return 0;
}