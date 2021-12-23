#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **head, int data)
{
    if (*head == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        *head = temp;
        return;
    }
    push(&((*head)->next), data);
}

void swap(node *a, node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sort(node *start)
{
    int swapped, i;
    node *ptr1;
    node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void merge(node *l1, node *l2)
{

    while (l2->next != NULL)
    {
        l2 = l2->next;
    }
    l2->next = l1;
}

void display(node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node *l1, *l2;
    l1 = NULL;
    l2 = NULL;

    push(&l1, 1);
    push(&l1, 5);
    push(&l1, 2);
    push(&l1, 9);
    push(&l2, 1);
    push(&l2, 4);
    push(&l2, 6);
    push(&l2, 2);
    sort(l1);
    sort(l2);
    merge(l1, l2);
    display(l2);
}