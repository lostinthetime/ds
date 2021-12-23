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

void sortList(node **head)
{
    node *curr = *head;
    node *temp;

    if (*head == NULL)
    {
        return;
    }
    else
    {
        while (curr != NULL)
        {
            temp = curr->next;
            while (temp != NULL)
            {
                if (curr->data > temp->data)
                {
                    int tempData = curr->data;
                    curr->data = temp->data;
                    temp->data = tempData;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }
    }
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
    push(&head, 12);
    push(&head, 39);
    push(&head, 14);
    push(&head, 35);
    push(&head, 26);
    push(&head, 17);
    traverse(head);
    sortList(&head);
    traverse(head);
}