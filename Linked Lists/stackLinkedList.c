// Implement stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node Node;
Node *get_new_node();
Node *push(Node *head, int data);
void traverse(Node *head);
Node *pop(Node *head);
int main()
{
    Node *head;
    head = NULL;
    int choice, input, position;

    while (choice != 9)
    {
        printf("\n\n**************STACK USING LINKED LIST***********************\n");
        printf("1.Push\n2.Pop\n3.Traverse\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &input);
            head = push(head, input);
            break;
        case 2:
            head = pop(head);
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            exit(1);
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

Node *push(Node *head, int data)
{
    Node *ptr = get_new_node();
    ptr->info = data;
    ptr->next = head;
    return (ptr);
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
Node *pop(Node *head)
{

    if (head == NULL)
        printf("List is already empty !");
    else
    {
        printf("Popped element:%d", head->info);
        Node *temp;
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }

    return head;
}
