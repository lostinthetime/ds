#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct item
{
    int value;
    int priority;
} item;

item pr[100];

int size = -1;

void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}

int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= size; i++)
    {
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    };
    size--;
}

void traverse()
{
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", pr[i].value);
    }
}
int main()
{
    while (1)
    {

        int ch;
        int num;
        int prio;
        printf("1: Push\n2: Pop\n3: Display\n4: Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d %d", &num, &prio);
            enqueue(num, prio);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }