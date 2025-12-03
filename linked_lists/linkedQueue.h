#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int key;
    struct QueueNode* link;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
} Queue;

QueueNode* CreateNode(int);
void addq(Queue**, int);
int deleteq(Queue**);
int peek(Queue*);
int isEmpty(Queue*);
void printq(Queue*);