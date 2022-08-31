// 5b infixcx to postfix conversion using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct Stack
{
    char items[MAX];
    int top;
} stack;
stack opstack, postfix, infix;
void push(stack *s, char element);
char pop(stack *s);
int isEmpty(stack *s);
int precedence(char ch);
void inToPost();
int main()
{
    opstack.top = -1, postfix.top = -1, infix.top = -1;
    printf("Enter the infix expression:");
    gets(infix.items);
    inToPost();
    printf("Equivalent postfix expression:%s", postfix.items);

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
void inToPost()
{

    int i;
    char symbol, next;
    for (i = 0; infix.items[i] != '\0'; i++)
    {
        symbol = infix.items[i];
        switch (symbol)
        {
        case '(':
            push(&opstack, symbol);
            break;
        case ')':
            while ((next = pop(&opstack)) != '(')
            {
                push(&postfix, next);
            }
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            while (!isEmpty(&opstack) && precedence(opstack.items[opstack.top]) >= precedence(symbol))
            {
                push(&postfix, pop(&opstack));
            }
            push(&opstack, symbol);
            break;
        default:
            push(&postfix, symbol);
        }
    }
    while (!isEmpty(&opstack))
    {
        push(&postfix, pop(&opstack));
    }
    push(&postfix, '\0');
}

// reverse bracket condition for prefix and scan right to left