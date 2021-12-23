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

void pop(node **head)
{
    node *temp = *head;
    node *last;
    while (temp->next != NULL)
    {
        last = temp;
        temp = temp->next;
    }
    last->next = NULL;
    printf("%d is popped\n", temp->data);
    free(temp);
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d-> ", head->data);
    display(head->next);
}

int main()
{
    int top = -1;
    node *head = NULL;
    while (1)
    {

        int ch;
        int num;
        printf("1: Push\n2: Pop\n3: Display\n4: Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &num);
            push(&head, num);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
}