#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[25];
} element;

typedef struct{
    element *arr;
    int front, rear, capacity;
} queue;

void queueFull(queue *queue)
{
    element *arr = malloc(2*sizeof(element)*queue->capacity);
    queue->rear=queue->capacity-1;
    
    for (int i=queue->front+1; i<queue->capacity; i++)
        arr[i]=queue->arr[i];
    
    queue->capacity*=2;
    queue->arr = arr;
    queue->rear = (queue->rear+1) % queue->capacity;
    free(arr);
}

void InitializeQ(queue *queue)
{
    queue->front=0;
    queue->rear=0;
    queue->capacity=2;
    queue->arr = malloc(sizeof(element)*queue->capacity);
}

void AddQ(queue *queue, element item)
{
    queue->rear = (queue->rear+1) % queue->capacity;
    if (queue->front == queue->rear)
        queueFull(queue);
    queue->arr[queue->rear] = item;
}

element DeleteQ(queue *queue)
{
    if (queue->front == queue->rear)
        printf("Queue Empty!");
    else{ 
        queue->front = (queue->front+1) % queue->capacity;
        return queue->arr[queue->front];
    }
}

element frontQ(queue *queue)
{
    if (queue->front==queue->rear)
        printf("Queue Empty!");
    int front=(queue->front+1) % queue->capacity;
    return queue->arr[front];
}

void printQ(queue *queue)
{
    int front=queue->front;
    while (front < queue->rear)
    {
        front = (front+1) % queue->capacity;
        printf("%d, %s\n", queue->arr[front].id, queue->arr[front].name);
    }
}

void main()
{
    element item;
    queue queue;
    
    InitializeQ(&queue);

    for (int i=1; i<=5; i++)
    {
        item.id=i;
        strcpy(item.name,"Joel Oswin J");
        AddQ(&queue,item);
    }

    //printf("%s\n", DeleteQ(&queue).name);
    
    printQ(&queue);
}