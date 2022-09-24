// singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next; // self referential structure
};
typedef struct node Node;
Node *get_new_node();
Node *insert_at_end(Node *head, int data);
Node *insert_at_beg(Node *head, int data);
void insert_at_any(Node *head, int data, int pos);
void traverse(Node *head);
Node *delete_at_first(Node *head);
void delete_at_last(Node *head);
void delete_at_any(Node **head, int pos);
void count_nodes(Node *head);
int main()
{
    Node *head;
    head = NULL;
    int choice, input, position;

    while (choice != 9)
    {
        printf("\n\n**************SINGLY LINKED LIST***********************\n");
        printf("1.Insert element at beginning.\n2.Insert element at end.\n3.Insert element at desired position.\n4.Delete first element.\n5.Delete last element.\n6.Delete element of desired positon.\n7.Display all items.\n8.Display number of nodes.\n9.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            head = insert_at_beg(head, input);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            head = insert_at_end(head, input);
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            printf("Enter desired location to insert: ");
            scanf("%d", &position);
            insert_at_any(head, input, position);
            break;
        case 4:
            head = delete_at_first(head);
            break;
        case 5:
            delete_at_last(head);
            break;
        case 6:
            printf("Enter position of element to delete: ");
            scanf("%d", &position);
            delete_at_any(&head, position);
            break;
        case 7:
            traverse(head);
            break;
        case 8:
            count_nodes(head);
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
Node *insert_at_end(Node *head, int data)
{
    Node *ptr, *temp;
    ptr = head;
    temp = get_new_node();
    temp->info = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
    }
    return head;
}
Node *insert_at_beg(Node *head, int data)
{
    Node *ptr = get_new_node();
    ptr->info = data;
    ptr->next = head;
    return (ptr);
}
void insert_at_any(Node *head, int data, int pos)
{
    Node *ptr = head;
    Node *ptr2 = get_new_node();
    ptr2->info = data;
    ptr2->next = NULL;
    while (pos != 2)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}
void traverse(Node *head)
{
    Node *ptr = head;
    printf("\nCurrent linked list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}
Node *delete_at_first(Node *head)
{

    if (head == NULL)
        printf("List is already empty !");
    else
    {
        Node *temp;
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    return head;
}
void delete_at_last(Node *head)
{
    if (head == NULL)
        printf("List is already empty");
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void delete_at_any(Node **head, int pos)
{
    Node *current, *previous;
    current = *head;
    previous = *head;
    if (*head == NULL)
        printf("List is already empty");
    else if (pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}
void count_nodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nTotal Nodes:%d", count);
}
