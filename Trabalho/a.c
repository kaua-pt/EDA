#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005
#define MAX_M 4200000

int verifica_substring(char *string, char *substring)
{
    int n = 0;
    char *ponteiro = strstr(string, substring);
    while (ponteiro != 0)
    {
        ponteiro++;
        ponteiro = strstr(ponteiro, substring);
        n++;
    }

    return n;
}

int main()
{
    char **strings = (char **)malloc(MAX_N * sizeof(char *));
    char str[MAX_M];
    int n = 0;

    for (; scanf(" %s", str) == 1; n++)
    {
        strings[n] = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(strings[n], str);
    }

    for (int i = 0; i < n - 1; i++)
        printf("%d\n", verifica_substring(strings[i], strings[n - 1]));

    return 0;
}