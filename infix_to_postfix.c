#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int *array;
    int size;
    int top;
} stack;

stack *createStack(int size)
{
    stack *st = (stack *)(malloc(sizeof(stack)));
    st->array = malloc(sizeof(sizeof(int) * size));
    st->top = -1;
    st->size = size;
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

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char *exp)
{
    int i, k;
    stack *st = createStack(strlen(exp));
    if (!st)
        return -1;
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(st, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(st) && peek(st) != '(')
                exp[++k] = pop(st);
            if (!isEmpty(st) && peek(st) != '(')
                return -1;
            else
                pop(st);
        }
        else
        {
            while (!isEmpty(st) && prec(exp[i]) <= prec(peek(st)))
                exp[++k] = pop(st);
            push(st, exp[i]);
        }
    }
    while (!isEmpty(st))
        exp[++k] = pop(st);

    exp[++k] = '\0';
    printf("%s", exp);
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
}