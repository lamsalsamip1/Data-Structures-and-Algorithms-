// Ascending priority queue
#include <stdio.h>
#define MAXQUEUE 5
struct queue
{
    int items[MAXQUEUE];
    int front, rear;
};
typedef struct queue Queue;
int isEmpty(Queue *);
int isFull(Queue *);
void enqueue(Queue *, int item);
int dequeue(Queue *);
int peek(Queue *);
void traverse(Queue *);
int main()
{
    Queue q;

    q.front = 0;
    q.rear = -1;

    int num, el;
    do
    {
        printf("\n********************Ascending Priority Queue****************\n");
        printf("1.Insert element\n2.Delete element\n3.Traverse\n4.Exit\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Enter element to add:");
            scanf("%d", &el);
            enqueue(&q, el);
            break;
        case 2:
            printf("Element removed:%d", dequeue(&q));
            break;
        case 3:
            traverse(&q);
            break;
        }
    } while (num != 4);
    return 0;
}
int isEmpty(Queue *q)
{
    if (q->front == q->rear + 1)
        return 1;
    return 0;
}
int isFull(Queue *q)
{
    if (q->rear == MAXQUEUE - 1)
        return 1;
    return 0;
}
void makeEmpty(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
void traverse(Queue *q)
{
    if (isEmpty(q))
        printf("Queue is empty\n");

    else
    {
        printf("Traversing queue:");
        int i;
        for (i = q->front; i <= q->rear; i++)
        {
            printf(" %d", q->items[i]);
        }
    }
}
void enqueue(Queue *q, int item)
{
    if (!isFull(q))
        q->items[++q->rear] = item;
    else
        printf("Queue overflow\n");
}
int peek(Queue *q)
{
    int i, highest = q->items[q->front], position;
    for (i = q->front; i <= q->rear; i++)
    {
        if (highest < q->items[i])
        {
            highest = q->items[i];
            position = i;
        }
    }
    return position;
}
int dequeue(Queue *q)
{
    int i, ind, del;
    ind = peek(q);
    del = q->items[ind];
    if (!isEmpty(q))
    {
        for (i = ind; i < q->rear; q++)
        {
            q->items[i] = q->items[i + 1];
        }
        q->rear--;
        return del;
    }

    else
        printf("Queue is empty\n");
    return 0;
}