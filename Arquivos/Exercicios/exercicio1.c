/*
1- Considere um arquivo texto denominado “votos.txt” que contém, em cada
linha, o voto de um eleitor, representado pelo código de identificação do
candidato. Suponha que existam 5 candidatos, cujos códigos de identificação
são: 100, 200, 300, 400, 500.
Faça um programa para apurar o resultado final da eleição. O programa
deverá implementar funções para:

a) Calcular e apresentar a quantidade de votos por candidato;

b) Calcular e apresentar a quantidade de votos do candidato mais
votado;

c) Calcular a quantidade de votos do candidato menos votado;

d) Calcular e apresentar a quantidade de votos nulos (um voto nulo é
um voto cujo código de identificação é inválido).

Obs: as funções deverão retornar os resultados para serem impressos no programa
principal. Utilize parâmetros para fazer a transferência de dados entre as funções.
NÃO USE VARIÁVEIS GLOBAIS.
*/
#include <stdio.h>
#include <stdlib.h>

int totalVotosCandidatos(int *cand, int *nulos, FILE *arq)
{
    int voto, i;
    while (!feof(arq))
    {
        fscanf(arq, "%d", &voto);
        if (ferror(arq))
            return 0;
        if (voto == 100)
            cand[0]++;
        else if (voto == 200)
            cand[1]++;
        else if (voto == 300)
            cand[2]++;
        else if (voto == 400)
            cand[3]++;
        else if (voto == 500)
            cand[4]++;
        else
            (*nulos)++;
    }
    return 1;
}

int maisVotado(int *cand)
{
    int i, maior = 0;
    for (i = 1; i < 5; i++)
    {
        if (cand[i] > cand[maior])
            maior = i;
    }
    return maior;
}

int menosVotado(int *cand)
{
    int i, menor = 0;
    for (i = 1; i < 5; i++)
    {
        if (cand[i] < cand[menor])
            menor = i;
    }
    return menor;
}

int main()
{
    FILE *arqVotos;
    int votosCandidatos[5] = {0, 0, 0, 0, 0};
    int nulos = 0, i, menor, maior;

    if ((arqVotos = fopen("votos.txt", "r+")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        fclose(arqVotos);
        exit(0);
    }
    if (!totalVotosCandidatos(votosCandidatos, &nulos, arqVotos))
    {
        perror("Error");
        fclose(arqVotos);
        exit(0);
    }
    for (i = 0; i < 5; i++)
        printf("Candidato %d, votos: %d\n", (i + 1) * 100, votosCandidatos[i]);

    maior = maisVotado(votosCandidatos);
    printf("\nCandidato mais votado foi %d, com %d votos.\n", (maior + 1) * 100, votosCandidatos[maior]);
    menor = menosVotado(votosCandidatos);
    printf("\nCandidato menos votado foi %d, com %d votos.\n", (menor + 1) * 100, votosCandidatos[menor]);
}