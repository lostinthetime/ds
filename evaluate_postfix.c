#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int capacity;
    int *array;
} stack;

stack *createStack(int size)
{
    stack *st = (stack *)(malloc(sizeof(stack)));
    st->array = malloc(sizeof(sizeof(int) * size));
    st->top = -1;
    st->capacity = size;
    return st;
}

int isEmpty(stack *stack)
{
    return stack->top == -1;
}
char peek(stack *stack)
{
    return stack->array[stack->top];
}
char pop(stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
void push(stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostFix(char *exp)
{
    stack *st = createStack(strlen(exp));
    int i;
    if (!st)
        return -1;
    for (i = 0; exp[i]; i++)
    {
        if (isdigit(exp[i]))
            push(st, exp[i] - '0');

        else
        {
            int val1 = pop(st);
            int val2 = pop(st);
            switch (exp[i])
            {
            case '+':
                push(st, val2 + val1);
                break;
            case '-':
                push(st, val2 - val1);
                break;
            case '*':
                push(st, val2 * val1);
                break;
            case '/':
                push(st, val2 / val1);
                break;
            }
        }
    }
    return pop(st);
}

int main()
{
    char exp[] = "231*+9-";
    printf("postfix evaluation: %d", evaluatePostFix(exp));
}