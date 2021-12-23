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

void delete (node **head)
{
    int flag = 0;
    node *temp = *head;
    while (temp->next != NULL)
    {
        if (flag == 0)
        {
            node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            flag = 1;
        }
        else
        {
            flag = 0;
            temp = temp->next;
        }
    }
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%d-> ", head->data);
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
    printf("Before Delete \n");
    display(head);
    delete (&head);
    printf("After Delete \n");
    display(head);
}