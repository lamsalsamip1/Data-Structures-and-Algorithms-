// wap to evaluate prefix expression

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 10
struct stack
{
    char items[MAX];
    int top;
};
typedef struct stack st;
st prestack, resultstack;
void push(st *s, int element); // Performs push operation on stack
int pop(st *s);                // Performs pop operation on stack
int evaluatePre();
int main()
{
    int option, input;
    prestack.top = -1, resultstack.top = -1;
    printf("Enter the prefix operation:");
    gets(prestack.items);
    printf("Result:%d", evaluatePre());
    return 0;
}
void push(st *s, int element)
{
    if (s->top == MAX - 1)
        printf("***********STACK IS FULL**************\n");
    else
        s->items[++s->top] = element;
}
int pop(st *s)
{
    if (s->top == -1)
        printf("***********STACK IS EMPTY**************\n");
    else
        return s->items[s->top--];
}
int evaluatePre()
{
    int i, symbol, a, b, len;
    len = strlen(prestack.items);
    for (i = len - 1; i >= 0; i--)
    {
        symbol = prestack.items[i];
        if (symbol >= '0' && symbol <= '9')
        {
            push(&resultstack, symbol - '0');
        }
        else
        {
            a = pop(&resultstack);
            b = pop(&resultstack);
            switch (symbol)
            {
            case '+':
                push(&resultstack, b+a);
                break;
            case '-':
                push(&resultstack, b-a);
                break;
            case '/':
                push(&resultstack, b/a);
                break;
            case '*':
                push(&resultstack, b*a);
                break;
            case '^':
                push(&resultstack, pow(b, a));
                break;
            }
        }
    }
    return pop(&resultstack);
}
