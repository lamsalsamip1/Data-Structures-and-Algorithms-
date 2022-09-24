// WAP to evaluate postfix operation
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
struct stack
{
    char items[MAX];
    int top;
};
typedef struct stack st;
st poststack, resultstack;
void push(st *s, int element);
int pop(st *s);
int evaluatePost();
int main()
{
    int option, input;
    poststack.top = -1, resultstack.top = -1;
    printf("Enter the postfix operation:");
    scanf("%s", &poststack.items);
    printf("Result:%d", evaluatePost());
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
int evaluatePost()
{
    int i, symbol, a, b;
    for (i = 0; poststack.items[i] != '\0'; i++)
    {
        symbol = poststack.items[i];
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
                push(&resultstack, b + a);
                break;
            case '-':
                push(&resultstack, b - a);
                break;
            case '/':
                push(&resultstack, b / a);
                break;
            case '*':
                push(&resultstack, b * a);
                break;
            case '^':
                push(&resultstack, pow(b, a));
                break;
            }
        }
    }
    return pop(&resultstack);
}
