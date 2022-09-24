// Array implementation of stack

#include <stdlib.h>
#define MAX 10
struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;
int isFull(st *s);             // Checks if stack is full
int isEmpty(st *s);            // Checks if stack is empty
void makeEmpty(st *s);         // Empties the stack
int top(st *s);                // Returns the topmost element of stack
void push(st *s, int element); // Performs push operation on stack
void pop(st *s);               // Performs pop operation on stack
int main()
{
    int option, input;
    st st1;
    st1.top = -1;
    do
    {
        printf("\n**********STACK OPERATIONS***************\n");
        printf("1. Push element\n2.Pop element out\n3.Check topmost element\n4.Exit\n***********\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter element you would like to push: ");
            scanf("%d", &input);
            push(&st1, input);
            break;
        case 2:
            pop(&st1);
            break;
        case 3:
            printf("Topmost element is : %d", top(&st1));
            break;
        case 4:
            exit(0);
        }
    } while (option != 4);
}
int isFull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void makeEmpty(st *s)
{
    s->top = -1;
}
int top(st *s)
{
    return s->items[s->top];
}
void push(st *s, int element)
{
    if (isFull(s))
        printf("***********STACK IS FULL**************\n");
    else
        s->items[++s->top] = element;
}
void pop(st *s)
{
    if (isEmpty(s))
        printf("***********STACK IS EMPTY**************\n");
    else
        printf("Deleted item: %d", s->items[s->top--]);
}
