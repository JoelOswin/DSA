#include "linkedQueue.h"

void main()
{
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    addq(&queue, 1);
    addq(&queue, 2);
    addq(&queue, 3);
    deleteq(&queue);

    printq(queue);
}