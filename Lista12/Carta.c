#include <stdio.h>
typedef int Item;
#define EXC(A, B) \
    Item tt = A;  \
    A = B;        \
    B = tt

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
    pilha->elem = 0;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == 0;
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

Item espia(Pilha *pilha)
{
    return pilha->v[pilha->elem - 1];
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->v[pilha->elem++] = e;
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

int passar(Pilha *pilha)
{
    int i, retorno = espia(pilha);
    Item a;
    // printf(" %d,", retorno);
    desempilha(pilha);
    for (i = 0; i < pilha->elem; i++)
    {
        if (i == 0)
        {
            a = pilha->v[0]; // pegar na mao
            // realizar a operação de "insertion";
            pilha->v[0] = pilha->v[pilha->elem]; // colocar o maior no menor
            continue;
        }
        EXC(a, pilha->v[i]);
    }
    return retorno;
}

void resolver(int c)
{
    printf("meu c %d\n", c);
    int cart = 1;
    Pilha *p;
    criaPilha(&p, c);
    // encher a pilha
    while (cart++ <= c)
        empilha(&p, c);

    printf("Cartas descartadas:");
    while (p->elem > 1)
        passar(&p);

    printf("\n");
    printf("Carta restante: %d\n", p->v[0]);

    desalocaPilha(&p);
    return;
}

int main()
{
    int cartas;
    scanf("%d", &cartas);
    resolver(cartas);
    return 0;
}