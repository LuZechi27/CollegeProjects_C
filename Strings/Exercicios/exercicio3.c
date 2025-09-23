/*
3) Faça um programa que receba uma palavra e
verifique se ela é um palíndromo, ou seja, se escrita
do fim para o começo é igual à palavra escrita do
começo para o fim. Exemplo: RENNER, ANA,
MIRIM, OVO, etc.
*/
#include <stdio.h>
#include <string.h>
#define Max 10

int isPalindrome(int size, char str[])
{
    int i, flag = 1;
    for (i = 0; i < size/2; i++)
    {
        if (str[i] != str[size - i - 1])
            flag = 0;
    }
    return flag;
}

int main()
{
    char word[Max];
    int size;
    
    printf("Informe a palavra: ");
    fgets(word, Max, stdin);
    word[strcspn(word, "\n")] = '\0';
    
    size = strlen(word);

    if (isPalindrome(size, word)){
        printf("\nÉ palíndromo!\n");
    } else {
        printf("\nNão é palíndromo!\n");
    }

    return 0;
}