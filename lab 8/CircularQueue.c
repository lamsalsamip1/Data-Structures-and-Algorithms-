// MEMORY IS WASTED IN LINEAR QUEUE

// one place is sacrificed in this method
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
void makeEmpty(Queue *);
void enqueue(Queue *, int item);
int dequeue(Queue *);

int main()
{
    Queue q;

    // INITIAL EMPTY STATE
    q.front = q.rear = MAXQUEUE - 1;

    int num,
        el;
    do
    {
        printf("\n********************LINEAR QUEUE OPERATIONS****************\n");
        printf("1.Insert element\n2.Delete element\n3.Make queue empty\n4.Check if queue is empty\n5.Check if queue is full\n6.Exit\n");
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
            makeEmpty(&q);
            printf("Queue is now empty\n");
            break;
        case 4:
            if (isEmpty(&q))
                printf("Queue is empty");
            else
                printf("Queue is not empty");
            break;
        case 5:
            if (isFull(&q))
                printf("Queue is full");
            else
                printf("Queue is not full");
            break;
        }
    } while (num != 6);
    return 0;
}
int isEmpty(Queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}
int isFull(Queue *q)
{
    if (q->front == (q->rear + 1) % MAXQUEUE)
        return 1;
    return 0;
}
void makeEmpty(Queue *q)
{
    q->front = q->rear = MAXQUEUE - 1;
}

void enqueue(Queue *q, int item)
{
    if (!isFull(q))
    {
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->items[q->rear] = item;
    }

    else
        printf("Queue overflow\n");
}
int dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        q->front = (q->front + 1) % MAXQUEUE;
        return q->items[q->front];
    }

    else
        printf("Queue is empty\n");
    return 0;
}