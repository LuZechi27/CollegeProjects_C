#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     FILE *arqTeste;
//     char string[100];

//     if ((arqTeste = fopen("arquivoTeste.txt", "w")) == NULL)
//     {
//         perror("Erro ao abrir o arquivo");
//         exit(0);
//     }
//     do
//     {
//         printf("\nDigite uma nova string. Para terminar, digite <enter>: ");
//         gets(string);
//         fputs(string, arqTeste);
//         fputc('\n', arqTeste);
//         if (ferror(arqTeste))
//         {
//             perror("Erro na gravacao em arquivo");
//             fclose(arqTeste);
//             exit(0);
//         }
//     } while (strlen(string) > 1);
//     fclose(arqTeste);
// }

int main()
{
    FILE *p;
    char str[80], c;
    printf("\n\n Entre com um nome para o arquivo:\n");
    gets(str);
    if ((p = fopen(str, "w+")) == NULL) /* Se ocorrer erro na abertura do arquivo..*/
    {
        perror("Erro! Impossivel abrir o arquivo!\n");
        exit(0);
    }
    fprintf(p, "Este eh um arquivo chamado:\n%s\n", str);
    rewind(p); /*posiciona o curso no inicio do arquivo para a leitura */
    while (!feof(p))
    {
        fscanf(p, "%c", &c);
        printf("%c", c);
    }
    fclose(p);
}