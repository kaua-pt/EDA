#include <stdio.h>
#include <stdlib.h>

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
    if (head->size == 0)
    {
        printf("No job for Ada?\n");
        return 1;
    }
    Node *newBegin = head->begin->next;
    printf("%d\n", head->begin->c);
    free(head->begin);
    newBegin->prev = NULL;
    head->begin = newBegin;
    head->size--;
    return 0;
}

int popLast(Head *head)
{
    if (head->size == 0)
    {
        printf("No job for Ada?\n");
        return 1;
    }
    Node *newLast = head->end->prev;

    printf("%d\n", head->end->c);

    free(head->end->prev);
    head->end = newLast;
    head->size--;
    return 0;
}

int reverse(Head *head) {}

int main()
{
    int q, i, n, flag = 0;
    char com[1001];
    Head head;
    createHead(&head);

    scanf("%d", &q);

    for (i = 0; i < q; i++)
    {
        scanf("%s", com);
        if (com[0] == 'b')
            if (flag == 0)
                popLast(&head);
            else
                popFrist(&head);
        if (com[0] == 'f')
            if (flag == 0)
                popFrist(&head);
            else
                popLast(&head);
        if (com[0] == 'p')
        {
            scanf("%d", &n);
            if (flag == 0)
                pushToBack(&head, n);
            else
                pushFrist(&head, n);
        }
        if (com[0] == 't')
        {
            scanf("%d", &n);
            if (flag == 0)
                pushFrist(&head, n);
            else
                pushToBack(&head, n);
        }
        if (com[0] == 'r')
        {
            if (flag == 0)
                flag = 1;
            if (flag == 1)
                flag = 0;
        }
    }

    return 0;
}