#include <stdio.h>
#include <stdlib.h>
typedef int Item;

typedef struct Node
{
    Item c;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Head
{
    int size;
    struct Node *begin;
    struct Node *end;
} Head;

void merge(int *vetor, int i, int f, int m)
{
    int vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            vetorAux[AUXi++] = vetor[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    while (Ai <= m)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        vetor[p] = vetorAux[v++];
    }
}

void mergeSort(int *vetor, int i, int j)
{
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(vetor, i, meio);
    mergeSort(vetor, meio + 1, j);
    merge(vetor, i, j, meio);
}

int createHead(Head *head)
{
    head->begin = NULL;
    head->end = NULL;
    head->size = 0;
    return 0;
}

int pushFrist(Head *head, Item e)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return 1;

    node->c = e;
    node->next = NULL;
    node->prev = NULL;

    head->size++;
    head->begin = node;
    head->end = node;

    return 0;
}

int pushToBack(Head *head, Item e)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return -1;

    node->c = e;
    node->prev = head->end;
    node->next = NULL;

    head->end->next = node;

    head->size++;
    head->end = node;
    return 0;
}

int pushLink(Head *head, Item e)
{
    if (head->size == 0)
    {
        pushFrist(head, e);
        return;
    }
    pushToBack(head, e);
}

int popFrist(Head *head)
{
    Node *newBegin = head->begin->next;
    free(head->begin);
    newBegin->prev = NULL;
    head->begin = newBegin;
    head->size--;
    return 0;
}

int popLast(Head *head)
{
    Node *newLast = head->end->prev;
    free(head->end->prev);
    head->end = newLast;
    head->size--;
    return 0;
}

int popLink(Head *head)
{
    if (head->size == 1)
    {
        popFrist(head);
        return 0;
    }
    popLast(head);
    return 0;
}

void print(Head *head, int n)
{
    int i, j;
    int aux[head->size];
    Node *node = head->begin;

    for (i = 0; i < head->size; i++)
    {
        aux[i] = node->c;
        node = node->next;
    }

    mergeSort(aux, 0, head->size - 1);

    for (j = 0; j < n; j++)
        printf("%d ", aux[j]);

    printf("\n");
    return;
}

void aloca(Head *head, int n)
{
    pushLink(head, n);
}

int main()
{
    Head head;
    createHead(&head);
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) != EOF)
    {
        if (n1 == 1)
            aloca(&head, n2);
        else
            print(&head, n2);
    }
    return 0;
}