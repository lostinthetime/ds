#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr;
    int size;
    int front;
    int rear;

} queue;

queue *createQueue(int size)
{
    queue *st = (queue *)(malloc(sizeof(queue)));
    st->arr = malloc(sizeof(sizeof(int) * size));
    st->front = -1;
    st->rear = -1;
    st->size = size;
    return st;
}

void push(queue *st, int data)
{
    if (st->rear == st->size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        st->arr[++st->rear] = data;
        st->front = 0;
    }
}

void pop(queue *st)
{
    if (st->front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int el = st->arr[st->front];
        st->arr[st->front++] = 0;
        printf("%d is popped\n", el);
    }
}

void display(queue *st)
{
    int i = 0;
    while (st->front <= st->rear)
    {
        printf("%d ", st->arr[st->front++]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    queue *st = createQueue(n);
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