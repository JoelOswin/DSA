#include "circularQueue.h"

void main()
{
    Queue* queue = CreateQ();
    addq(&queue, 1);
    addq(&queue, 2);
    addq(&queue, 3);
    addq(&queue, 100);
    printQ(queue);
    dequeue(&queue);
    //printf("\n%d", dequeue(&queue));
    printQ(queue);
    //revNodes(&queue);
    printf("\n");
    printQ(queue); 
}