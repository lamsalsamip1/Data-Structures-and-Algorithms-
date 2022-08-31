#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
char infix[max], postfix[max], stack[max];
struct stacks
{
    int top;
};
typedef struct stacks st;
int push(st s, int sym)
{
    if (s.top == max - 1)
    {
        printf("Stack is full.\n");
    }
    else
        stack[++s.top] = sym;
}
int isempty(st s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
char pop(st s)
{

    if (s.top == -1)
        printf("Stack is empty.\n");
    else
        return stack[s.top--];
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int space(char ch)
{
    if (ch == ' ' || ch == '\t')
        return 1;
    else
        return 0;
}
void intopost(st s)
{
    int i, j = 0;
    char sym, next;
    for (i = 0; i < strlen(infix); i++)
    {
        sym = infix[i];
        if (!space(sym))
        {
            switch (sym)
            {
            case '(':
                push(s, sym);
                break;
            case ')':
                while ((next = pop(s)) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isempty(s) && precedence(stack[s.top]) >= precedence(sym))
                    postfix[j++] = pop(s);
                push(s, sym);
                break;
            default:
                postfix[j++] = sym;
            }
        }
    }
    while (!isempty(s))
        postfix[j++] = pop(s);
    postfix[j] = '\0';
}

int main()
{
    struct stacks s;
    s.top = -1;
    printf("Enter an infix expression: ");
    gets(infix);
    intopost(s);
    printf("The postfix expression is:%s", postfix);
    return 0;
}