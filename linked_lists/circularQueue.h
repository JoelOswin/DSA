#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int num;
    struct QueueNode* link;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* CreateQ();
void addq(Queue**, int num);
int dequeue(Queue**);
void revNodes(Queue**);
void printQ(Queue*);