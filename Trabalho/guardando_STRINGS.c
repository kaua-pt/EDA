#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Palavra
{
    char palavra[100000001];
    int tam;

} Palavra;

typedef struct queue
{
    int l;
    int r;
    int maxsize;
    Palavra *q;

    char (*full)(struct queue *);

} queue;

char full(queue *q);

queue initialize(int maxs)
{
    queue new;

    new.q = malloc(sizeof(Palavra) * maxs);

    new.l = 0;
    new.r = 0;

    new.maxsize = maxs;
    new.full = full;

    return new;
}

char full(queue *q)
{
    return q->r == q->maxsize;
}

int empty(queue *q)
{
    if (q->l == q->r)
    {
        return 0;
    }
    return 1;
}

Palavra back(queue *q)
{
    return q->q[q->r - 1];
}

Palavra front(queue *q)
{
    return q->q[q->l];
}

void dequeue(queue *q)
{
    ++q->l;
}

void enqueue(queue *q, Palavra i)
{
    if (q->full(q))
        return;

    q->q[q->r++] = i;
}

int size(queue *q)
{
    return q->r - q->l;
}

void destroy(queue *q)
{
    free(q->q);
}

int main()
{
    char input[1000000];
    int count = 0;

    // fila
    queue fila;
    fila = initialize(1e5);

    // Pegando quais serao as palavra
    while (scanf("%s", &input) != EOF)
    {
        Palavra palavra;
        int tam = strlen(input);

        palavra.tam = tam;
        strcpy(palavra.palavra, input);

        enqueue(&fila, palavra);
        count++;
    }

    Palavra ultima_palavra;
    ultima_palavra = back(&fila);

    int i;
    // verificando as palavras
    for (i = 0; i < count - 1; i++)
    {
        int contador = 0;
        Palavra palavra_analisada;
        palavra_analisada = front(&fila);

        int char1 = 0; // o char1 e a posicao de algum char do ultimo elemento
        int j;
        // verificando letra por letra
        for (j = 0; j < palavra_analisada.tam + 1; j++)
        {
            /*
            Se o char 1 for maior que o tamanho da ultima palavra que dizer que a
            palavra existe na palavra analisada, ai voltamos o char1 para 0 para que possamos ver
            se a ultima palavra existe mais vezes na palavra analisada
            */
            if (char1 > ultima_palavra.tam - 1)
            {
                contador++;
                char1 = 0;
            }

            char *letra_analisando = palavra_analisada.palavra[j];
            char *letra_ultima = ultima_palavra.palavra[char1];

            // se as letras forem iguais add no char1 se nao volta o char1 para 0
            if (letra_analisando == letra_ultima)
            {
                char1++;
            }
            else
            {
                char1 = 0;
            }
        }

        dequeue(&fila);
        printf("%d\n", contador);
    }

    destroy(&fila);

    return 0;
}
