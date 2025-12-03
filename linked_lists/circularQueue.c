#include "circularQueue.h"

Queue* CreateQ()
{
    QueueNode* front = (QueueNode*) malloc(sizeof(QueueNode));
    if (front == NULL) return NULL;
    front->num = -1;
    front->link = front;
    QueueNode* rear = front;

    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) return NULL;
    queue->front = front;
    queue->rear = rear;
    return queue;
}

void addq(Queue** queue, int num)
{
    if (*queue==NULL) return;
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    if (node == NULL) return;
    node->num = num;

    node->link = (*queue)->rear->link;
    (*queue)->rear->link = node;
    (*queue)->rear = node;
}

int dequeue(Queue** queue)
{
    if (*queue == NULL) return -11;
    if ((*queue)->front == (*queue)->rear) return -10;
    QueueNode* temp = (*queue)->front;
    QueueNode* node = (*queue)->front->link;
    (*queue)->rear->link = node;
    (*queue)->front = node;
    int num = node->num;
    node->num = -1;
    free(temp);
    return num;
}

void revNodes(Queue** queue)
{
    if (*queue == NULL) return;
    QueueNode* current = (*queue)->front;
    QueueNode* current1 = (*queue)->front->link;
    while (current != (*queue)->rear){
        QueueNode* temp = current1->link;
        current1->link = current;
        current->link = temp;

        current1 = current1->link;
        current = current->link;
    }
}

void printQ(Queue* queue)
{
    QueueNode* front = queue->front;
    while(front != queue->rear){
        front = front->link;
        printf("%d->", front->num);
    }
    printf("Point to empty element");
}