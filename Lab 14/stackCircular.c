// write a progam to implement stack as a circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next; // self referential structure
};
typedef struct node Node;
Node *pstack = NULL;
Node *get_new_node();
int isEmpty();
void push(int item);
void pop();
int main()
{
    int option, input;
    do
    {
        printf("\n**********STACK OPERATIONS***************\n");
        printf("1. Push element\n2.Pop element out\n3.Check if empty\n4.Exit\n***********\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter element you would like to push: ");
            scanf("%d", &input);
            push(input);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty)
                printf("Stack is empty");
            else
                printf("Stack is not empty");
            break;
        case 4:
            exit(0);
        }
    } while (option != 4);
}
Node *get_new_node()
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    return p;
}
int isEmpty()
{
    if (pstack == NULL)
        return 1;
    return 0;
}
void push(int item)
{
    Node *new_node = get_new_node();
    new_node->info = item;
    if (pstack == NULL)
    {
        pstack = new_node;
        pstack->next = pstack;
    }
    else
    {
        new_node->next = pstack->next;
        pstack->next = new_node;
    }
}
void pop()
{
    Node *temp;
    if (pstack == NULL)
    {
        printf("Stack underflow");
    }
    else if (pstack->next == pstack)
    {
        printf("Popped item = %d", pstack->info);
        pstack = NULL;
    }
    else
    {
        temp = pstack->next;
        pstack->next = temp->next;
        printf("Popped item = %d", temp->info);
        free(temp);
    }
}