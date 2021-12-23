#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **top, int data)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = data;
    temp->next = NULL;
    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    node *last = *top;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void traverse(node *top)
{
    while (top)
    {
        printf("%d->", top->data);
        top = top->next;
    }
}

void intersect(node *t1, node *t2)
{
    node *temp1 = t1;
    while (temp1)
    {
        node *temp2 = t2;
        while (temp2)
        {
            if (temp2->data == temp1->data)
            {
                printf("%d ", temp1->data);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main()
{
    node *t1 = NULL;
    node *t2 = NULL;
    push(&t1, 1);
    push(&t1, 2);
    push(&t1, 3);
    push(&t1, 4);
    push(&t2, 2);
    push(&t2, 7);
    push(&t2, 9);
    push(&t2, 4);
    push(&t2, 8);
    intersect(t1, t2);
}