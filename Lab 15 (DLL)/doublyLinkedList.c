#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev, *next;
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
Node *head = NULL;

int main()
{
    int choice, input, position;

    while (choice != 8)
    {
        printf("\n\n**************DOUBLY LINKED LIST***********************\n");
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

    Node *new_node = get_new_node();
    new_node->info = data;
    new_node->prev = NULL;
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
void *insert_at_end(int data)
{

    Node *new_node = get_new_node();
    Node *temp;
    new_node->info = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void *delete_at_beg()
{
    Node *hold;
    if (head == NULL)
        printf("List already empty");

    else
    {
        hold = head;
        head->prev = NULL;
        head = head->next;
        // printf("head = %d", head->next->info);

        free(hold);
    }
}
void *delete_at_end()
{
    Node *temp = head, *hold;
    if (head == NULL)
        printf("List already empty");
    else if (head->next == NULL)
    {
        printf("hllo");
        hold = head;
        head = NULL;
        free(hold);
    }
    else
    {
        printf("Hello1");
        while (temp->next->next != NULL)
        {

            printf("%d", temp->info);
            temp = temp->next;
        }
        printf("Herllo");
        printf("%d", temp->info);
        hold = temp->next;
        printf("%d", hold->info);
        temp->next = NULL;
        free(hold);
    }
}
void insert_at_any(int data, int pos)
{
    Node *temp1 = head, *temp2, *new_node;
    new_node = get_new_node();
    new_node->info = data;
    while (pos != 2)
    {
        temp1 = temp1->next;
        pos--;
    }
    temp2 = temp1->next;
    temp1->next = new_node;
    temp2->prev = new_node;
    new_node->next = temp2;
    new_node->prev = temp1;
}
void *delete_at_any(int pos)
{
    Node *temp1 = head, *temp2, *new_node;
    new_node = get_new_node();
    while (pos != 1)
    {
        temp1 = temp1->next;
        pos--;
    }
    temp2 = temp1->prev;
    temp2->next = temp1->next;
    temp1->next->prev = temp2;
    free(temp1);
}
void traverse()
{
    Node *ptr = head;
    printf("\nCurrent doubly linked list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}