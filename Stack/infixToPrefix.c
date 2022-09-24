// 5c infixcx to prefix conversion using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct Stack
{
    char items[MAX];
    int top;
} stack;
stack opstack, prefix, infix;
void push(stack *s, char element);
char pop(stack *s);
int isEmpty(stack *s);
int precedence(char ch);
void inToPre();
int main()
{
    opstack.top = -1, prefix.top = -1, infix.top = -1;
    printf("Enter the infix expression:");
    gets(infix.items);
    strrev(infix.items);
    inToPre();
    printf("Equivalent prefix expression:%s", strrev(prefix.items));

    return 0;
}
int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void push(stack *s, char element)
{
    if (s->top == MAX - 1)
        printf("***********STACK IS FULL**************\n");
    else
        s->items[++s->top] = element;
}
char pop(stack *s)
{
    if (isEmpty(s))
        printf("***********STACK IS EMPTY**************\n");
    else
        return s->items[s->top--];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void inToPre()
{

    int i;
    char symbol, next;
    for (i = 0; infix.items[i] != '\0'; i++)
    {
        symbol = infix.items[i];
        switch (symbol)
        {
        case ')':
            push(&opstack, symbol);
            break;
        case '(':
            while ((next = pop(&opstack)) != ')')
            {
                push(&prefix, next);
            }
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            while (!isEmpty(&opstack) && precedence(opstack.items[opstack.top]) >= precedence(symbol))
            {
                push(&prefix, pop(&opstack));
            }
            push(&opstack, symbol);
            break;
        default:
            push(&prefix, symbol);
        }
    }
    while (!isEmpty(&opstack))
    {
        push(&prefix, pop(&opstack));
    }
    push(&prefix, '\0');
}

// reverse bracket condition for prefix and scan right to left
