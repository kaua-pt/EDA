#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005
#define MAX_M 420000

int existe(char *str1, char *str2, int id)
{
    int i, j = 0;

    for (i = id; i < strlen(str1); i++)
    {
        if (str1[i] == str2[j])
            j++;
        else
            j = 0;
        if (j == strlen(str2))
            return i;
    }
    return -1;
}

int ocorrencias(char *str1, char *str2)
{
    int quantidade = 0, indice = 0;
    do
    {
        indice = existe(str1, str2, indice);
        if (indice != -1)
            quantidade++;
    } while (indice != -1);

    return quantidade;
}

int main()
{
    char **strings = malloc(MAX_N * sizeof(char *));
    char str[MAX_M];
    int n = 0;

    while (scanf("%s", str) != EOF)
    {
        strings[n] = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(strings[n], str);
    }

    int i;
    for (i = 0; i < n - 1; i++)
        printf("%d\n", ocorrencias(strings[i], strings[n - 1]));

    return 0;
}