#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10

struct element
{
    int id;
    char name[25];
};

struct queue
{
    struct element arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void InitializeQ(struct queue* queue)
{
    queue->front=0;
    queue->rear=0;
}

void AddQ(struct queue* queue, struct element item)
{
    queue->rear=(queue->rear+1) % MAX_QUEUE_SIZE;
    if (queue->front==queue->rear)
    {
        queue->rear = MAX_QUEUE_SIZE-1;
        printf("Queue Full");
    }
    else
        queue->arr[queue->rear]=item;
}

struct element DeleteQ(struct queue* queue)
{
    if (queue->front==queue->rear)
        printf("Queue Empty");
    else
    {
        queue->front=(queue->front+1) % MAX_QUEUE_SIZE;
        return queue->arr[queue->front];
    }
}

void printQ(struct queue* queue)
{
    int front=queue->front;
    while (front!=queue->rear)
    {
        front=(front+1) % MAX_QUEUE_SIZE;
        printf("\n%d-%s\n", queue->arr[front].id, queue->arr[front].name);
    }
}

void main()
{
    struct element item;
    struct queue queue;
    
    InitializeQ(&queue);

    for (int i=0; i<MAX_QUEUE_SIZE; i++)
    {
        item.id=i+1;
        strcpy(item.name,"Joel Oswin J");
        AddQ(&queue,item);
    }

    printf("%s\n", DeleteQ(&queue).name);

    item.id=2;
    strcpy(item.name,"Steph Curry");
    AddQ(&queue,item);
    
    printQ(&queue);
}
