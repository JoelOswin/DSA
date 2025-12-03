#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

struct element{
    int id;
    char name[25];
};

struct queue{
    struct element arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void InitializeQ(struct queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isFullQ(struct queue* queue)
{
    if (queue->rear==(MAX_QUEUE_SIZE-1))
        return true;
    return false;
}

bool isEmptyQ(struct queue* queue)
{
    if (queue->front==queue->rear)
        return true;
    return false;
}

int queueFull(struct queue* queue)
{
    if (queue->rear==(MAX_QUEUE_SIZE-1) && queue->front==-1)
    {
        printf("Queue Full");
        return -1;
    } 
    else if (isEmptyQ(queue))
    {
        queue->front = -1;
        queue->rear = -1;
        return 1;
    } 
    else
    {
        queue->front++;
        int i;
        for (i=0; queue->front<MAX_QUEUE_SIZE; i++, queue->front++)
        {
            struct element temp;
            SWAP(queue->arr[i], queue->arr[queue->front], temp);
        }
        queue->rear = --i;
        queue->front = -1;
        return 1;
    }
}

void AddQ(struct queue* queue, struct element item)
{
    int key=1;
    if (isFullQ(queue))
        key=queueFull(queue);
    if (key==1)
        queue->arr[++queue->rear]=item;
}

struct element DeleteQ(struct queue* queue)
{
    if (isEmptyQ(queue))
        printf("Empty Queue");
    else
        return queue->arr[++queue->front];
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
    AddQ(&queue,item); // queueFull has a time complexity of O(MAX_QUEUE_SIZE) => O(10)
    
    for (int i=queue.front+1; i<=queue.rear; i++)
        printf("\n%d-%s\n", queue.arr[i].id, queue.arr[i].name);
}