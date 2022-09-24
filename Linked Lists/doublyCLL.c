// Doubly Circular Linked Lists

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev, *next;
};
typedef struct node Node;
Node *tail = NULL;
Node *get_new_node();
void *insert_at_beg(int data);
void *insert_at_end(int data);
void *delete_at_beg();
void *delete_at_end();
void traverse();

int main()
{
    int choice, input, position;

    while (choice != 6)
    {
        printf("\n\n**************DOUBLY LINKED LIST***********************\n");
        printf("1.Insert element at beginning.\n2.Insert element at end.\n3.Delete first element.\n4.Delete last element.\n5.Display all items.\n6.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            insert_at_beg(input);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            insert_at_end(input);
            break;

        case 3:
            delete_at_beg();
            break;
        case 4:
            delete_at_end();
            break;
        case 5:
            traverse();
            break;

        default:
            break;
        }
    }

    return 0;
}
Node *get_new_node()
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    return p;
}
void *insert_at_beg(int data)
{

    Node *new_node = get_new_node(), *temp;
    new_node->info = data;

    if (tail == NULL)
    {
        new_node->prev = new_node->next = new_node;
        tail = new_node;
    }
    else
    {
        temp = tail->next;
        new_node->next = temp;
        new_node->prev = tail;
        temp->prev = new_node;
        tail->next = new_node;
    }
}
void *insert_at_end(int data)
{
    Node *new_node = get_new_node(), *temp;
    new_node->info = data;
    if (tail == NULL)
    {
        new_node->prev = new_node->next = new_node;
        tail = new_node;
    }
    else
    {
        temp = tail->next;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = temp;
        temp->prev = new_node;
        tail = new_node;
    }
}
void *delete_at_beg()
{
    Node *temp;
    if (tail == NULL)
        printf("List is already empty");

    else if (temp == tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        temp = tail->next;
        tail->next = temp->next;
        temp->next->prev = tail;
        free(temp);
    }
}
void *delete_at_end()
{
    Node *temp;
    if (tail == NULL)
        printf("List is already empty");

    else if (temp == tail)
    {
        temp = tail->prev;
        free(tail);
        tail = NULL;
    }
    else
    {
        temp = tail->prev;
        temp->next = tail->next;
        tail->next->prev = temp;
        free(tail);
        tail = temp;
    }
}
void traverse()
{
    if (tail == NULL)
        printf("List is empty");
    else
    {
        Node *temp = tail->next;
        printf("\nCurrent linked list: ");
        do
        {
            printf("%d ", temp->info);
            temp = temp->next;
        } while (temp != tail->next);
    }
}
