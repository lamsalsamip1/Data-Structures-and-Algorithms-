// Implementation of queue using circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next; // self referential structure
};
typedef struct node Node;
Node *pqueue = NULL;
Node *get_new_node();
void enqueue(int item);
void dequeue();
int main()
{
    int option, input;
    do
    {
        printf("\n**********LINEAR QUEUE OPERATIONS***************\n");
        printf("1. Insert element\n2.Delete element out\n3.Exit\n***********\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter element you would like to push: ");
            scanf("%d", &input);
            enqueue(input);
            break;
        case 2:
            dequeue();
            break;
        }
    } while (option != 3);
}
Node *get_new_node()
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    return p;
}
void enqueue(int item)
{
    Node *new_node = get_new_node();
    new_node->info = item;
    if (pqueue == NULL)
    {
        pqueue = new_node;
        pqueue->next = pqueue;
    }
    else
    {
        new_node->next = pqueue->next;
        pqueue->next = new_node;
        pqueue = new_node;
    }
}
void dequeue()
{
    Node *temp;
    if (pqueue == NULL)
    {
        printf("Queue is empty");
    }
    else if (pqueue->next == pqueue)
    {
        printf("Deleted item = %d", pqueue->info);
        pqueue = NULL;
    }
    else
    {
        temp = pqueue->next;
        pqueue->next = temp->next;
        printf("Deleted item = %d", temp->info);
        free(temp);
    }
}
