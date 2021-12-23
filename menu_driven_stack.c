#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int size;
    int top;
} stack;

stack *createStack(int size)
{
    stack *st = (stack *)(malloc(sizeof(stack)));
    st->arr = malloc(sizeof(sizeof(int) * size));
    st->top = -1;
    st->size = size;
    return st;
}

void push(stack *st, int data)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Is Full\n");
    }
    else
    {
        st->arr[++st->top] = data;
    }
}

void pop(stack *st)
{
    if (st->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int el = st->arr[st->top--];
        printf("%d is popped\n", el);
    }
}

void display(stack *st)
{
    int i = 0;
    while (i <= st->top)
    {
        printf("%d ", st->arr[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    stack *st = createStack(n);
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
            push(st, num);
            break;
        case 2:
            pop(st);
            break;
        case 3:
            display(st);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
}