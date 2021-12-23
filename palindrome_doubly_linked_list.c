#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void push(node **head, int data)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->next = temp->prev = NULL;
    temp->data = data;
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
    temp->prev = last;
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

int palindrome(node *head, node *rev)
{
    if (rev->data != head->data)
        return 0;
    else if (rev->data == head->data)
    {
        if (rev == head)
            return 1;
        palindrome(head->next, rev->prev);
    }
}

int checkPalindrome(node *head)
{
    node *rev = head;
    while (rev->next != NULL)
        rev = rev->next;
    return palindrome(head, rev);
}
int main()
{
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);

    int check = checkPalindrome(head);
    if (check)
        printf("List is Palindrome\n");
    else
        printf("List is not Palindrome\n");
}