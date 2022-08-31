// Descending unordered priority queue
#include <stdio.h>
#define MAXQUEUE 10
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
int peek(Queue *, int item);
void traverse(Queue *);
int main()
{
    Queue q;

    q.front = 0;
    q.rear = -1;

    int num, el;
    do
    {
        printf("\n********************Descending Ordered Priority Queue****************\n");
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
        int i;
        for (i = q->front; i <= q->rear; i++)
        {
            printf(" %d", q->items[i]);
        }
    }
}
int peek(Queue *q, int item)
{
    int i;
    for (i = q->front; i <= q->rear; i++)
    {
        if (item < q->items[i])
        {
            return i;
        }
    }
    return -1;
}
void enqueue(Queue *q, int item)
{
    int i, index, temp;
    if (q->front == 0 && q->rear == -1)
    {
        q->rear++;
        q->items[q->rear] = item;
        traverse(q);
    }

    else if (!isFull(q))
    {
        index = peek(q, item);
        q->rear++;

        if (index == -1)
        {
            q->items[q->rear] = item;
            return;
        }
        for (i = q->rear; i >= index; i--)
        {
            // Shift elements one step right
            q->items[i + 1] = q->items[i];
        }
        q->items[index] = item;
    }

    else
        printf("Queue overflow\n");
}

int dequeue(Queue *q)
{
    int i, ind;
    if (!isEmpty(q))
    {
        return q->items[q->front++];
    }

    else
        printf("Queue is empty\n");
    return 0;
}