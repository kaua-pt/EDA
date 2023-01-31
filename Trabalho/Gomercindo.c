#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int id;
    int value;
    int next;
} Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

void criaPilha(Pilha *pilha, int s)
{
    pilha->v = malloc(sizeof(Pilha) * s);
    pilha->size = s;
    pilha->elem = -1;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == -1;
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

Item espia(Pilha *pilha)
{
    return pilha->v[pilha->elem];
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->elem++;
    pilha->v[pilha->elem] = e;
    return 0;
}

int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
        return 1;

    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha);
}

void solve(Pilha *pilha, int n)
{
    Item e;

    // Obter valores
    while (n-- >= 1)
    {
        scanf("%d %d %d", &e.id, &e.value, &e.next);
        empilha(pilha, e);
    }

    // fazer buscas completar o alg;
    // ideia : trocar os valores ordenando linearmente

    // obter fim
    int a;
    for (a = 0; a < pilha->elem; a++)
    {
        if (pilha->v[a].next == -1)
        {
            Item tt = pilha->v[a];
            pilha->v[a] = pilha->v[pilha->elem];
            pilha->v[pilha->elem] = tt;
        }
    }

    int b, c;
    for (b = 0; b < pilha->elem - 1; b++)
    {
        for (c = b + 1; c < pilha->elem - 1; c++)
        {
            if (pilha->v[b].next == pilha->v[c].id)
            {
                Item temp = pilha->v[c];
                pilha->v[c] = pilha->v[b + 1];
                pilha->v[b + 1] = temp;
            }
        }
    }
    int k;
    for (k = 0; k < pilha->elem + 1; k++)
        printf("%d\n", pilha->v[k].value);
}

int main()
{
    Pilha pilha;
    int n;
    scanf("%d", &n);
    criaPilha(&pilha, n);
    solve(&pilha, n);
    return 0;
}