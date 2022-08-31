// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next; // self referential structure
};
typedef struct node Node;
Node *get_new_node();
void *insert_at_beg(int data);
void *insert_at_end(int data);
void insert_at_any(int data, int pos);
void *delete_at_beg();
void *delete_at_end();
void *delete_at_any(int pos);
void traverse();
void search(int element);
Node *start = NULL;
Node *last = NULL;
int main()
{

    int choice, input, position;

    while (choice != 9)
    {
        printf("\n\n**************CIRCULAR LINKED LIST***********************\n");
        printf("1.Insert element at beginning.\n2.Insert element at end.\n3.Insert element at desired position.\n4.Delete first element.\n5.Delete last element.\n6.Delete element of desired positon.\n7.Display all items.\n8.Search element.\n9.Exit\n");

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
            printf("Enter element to insert: ");
            scanf("%d", &input);
            printf("Enter desired location to insert: ");
            scanf("%d", &position);
            insert_at_any(input, position);
            break;
        case 4:
            delete_at_beg();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            printf("Enter position of element to delete: ");
            scanf("%d", &position);
            delete_at_any(position);
            break;
        case 7:
            traverse();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &input);
            search(input);
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
    Node *new = get_new_node();
    new->info = data;

    if (start == NULL)
    {
        new->next = new;
        start = last = new;
    }

    else
    {
        new->next = start;
        start = new;
        last->next = new;
    }
}
void *insert_at_end(int data)
{
    Node *new = get_new_node();
    new->info = data;
    if (start == NULL)
    {
        new->next = new;
        start = last = new;
    }
    else
    {

        last->next = new;
        last = new;
        last->next = start;
    }
}

void insert_at_any(int data, int pos)
{
    Node *ptr = start;
    Node *temp = get_new_node();
    temp->info = data;
    temp->next = NULL;
    while (pos != 2)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void *delete_at_beg()
{
    if (start == NULL)
        printf("LIST IS EMPTY");
    else
    {
        Node *temp = start;
        start = start->next;
        printf("Deleted element:%d", temp->info);
        last->next = start;
        free(temp);
    }
}
void *delete_at_end()
{
    if (start == NULL)
        printf("LIST IS EMPTY");
    else
    {
        Node *temp = start;
        while (temp->next->next != start)
        {
            temp = temp->next;
        }
        Node *hold = temp->next;
        last = temp;
        last->next = start;
        printf("Deleted element:%d", hold->info);
        free(hold);
    }
}
void *delete_at_any(int pos)
{
    Node *current, *previous;
    current = start;
    previous = start;
    if (start == NULL)
        printf("List is already empty");
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        printf("Deleted item:%d", current->info);
        free(current);
        current = NULL;
    }
}
void traverse()
{
    Node *temp = start;
    printf("\nCurrent linked list: ");
    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != start);
}
void search(int element)
{
    int count = 1;
    Node *temp = start;
    do
    {
        if (element == temp->info)
            printf("Element found at position %d", count);
        temp = temp->next;
        count++;
    } while (temp != start);
}