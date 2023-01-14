#include <stdio.h>

struct Node
{
    int i;
    struct Node *next;
};
typedef struct Node node;

void start(node *pilha)
{
    pilha->next = NULL;
    pilha->i = 0;
}

int empty(node *pilha)
{
    if (pilha->next == NULL)
    {
        return 1;
    }
    return 0;
}

void freeM(node *pilha)
{
    if (!empty(pilha))
        return;
}

int main()
{
    node *pilha;

    return 0;
}