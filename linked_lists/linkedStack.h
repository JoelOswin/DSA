#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 1

typedef struct stackNode{
    int key;
    struct stackNode *link;
} stackNode;

void push(stackNode**, int key);
int pop(stackNode**);
int peek(stackNode**);