#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **head, int data)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void reverse(node **head)
{
    node *prev = NULL;
    node *curr = *head;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void traverse(node *head)
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
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    traverse(head);
    reverse(&head);
    traverse(head);
}