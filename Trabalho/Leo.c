#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    char name[27];
    int len;
} Item;

typedef struct Node
{
    Item c;
    Node *next;
    Node *prev;
} Node;

typedef struct Head
{
    int size;
    Node *begin;
    Node *end;
} Head;

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
        return pushFrist(&head, e);
    }
    return pushToBack(&head, e);
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

int solve(Head *head, char *input)
{
    Item final[head->size];
    Node *aux;
    int i, j;
    char myChar;

    final[0] = head->begin->c;
    // contador de final
    for (i = 0; i < head->size; i++)
    {
        aux = head->begin;
        myChar = final[i].name[final[i].len];
        // contador da lista
        for (j = 0; j < head->size; j++)
        {
            if (myChar == aux->c.name[aux->c.len])
            {
                final[i + 1] = aux->c;
            }
            aux = aux->next;
        }
    }
}

int main()
{
    Head head;
    Item e;
    createHead(&head);

    while (scanf("%s", e.name) != EOF)
    {
        e.len = strlen(e.name);
        pushLink(&head, e);
    }

    return 0;
}