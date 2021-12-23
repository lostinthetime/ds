#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *push(node *last, int data)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = data;
    if (last == NULL)
    {
        last = temp;
        last->next = last;
        return last;
    }
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return temp;
}

void traverse(node *last)
{
    node *p;
    p = last->next;
    do
    {
        printf("%d-> ", p->data);
        p = p->next;
    } while (p != last->next);
}

int main()
{
    node *last = NULL;
    last = push(last, 1);
    last = push(last, 2);
    last = push(last, 3);
    last = push(last, 4);
    last = push(last, 5);
    traverse(last);
}