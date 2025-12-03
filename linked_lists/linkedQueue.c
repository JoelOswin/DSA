#include "linkedQueue.h"

QueueNode* CreateNode(int key)
{
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    if (node == NULL) return NULL;
    node->key = key;
    node->link = NULL;
    return node;
}

int isEmpty(Queue* queue)
{
    return queue->front == NULL;
}

void addq(Queue** queue, int key)
{
    if ((*queue) == NULL)
        return;

    QueueNode* node = CreateNode(key);

    if (isEmpty(*queue)){ 
        (*queue)->front = (*queue)->rear = node;
        return;
    } 

    (*queue)->rear->link = node;
    (*queue)->rear = node;
}

int deleteq(Queue** queue)
{
    if ((*queue) == NULL)
        return -1;

    if ((*queue)->front == NULL)
        return -1;
    
    QueueNode* node = (*queue)->front;
    (*queue)->front = (*queue)->front->link;
    int val = node->key;
    free(node);
    return val;
}

int peek(Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->front->key;
}

void printq(Queue* queue)
{
    QueueNode* node = queue->front;
    while(node != NULL){
        printf("%d ->", node->key);
        node = node->link;
    }  
}