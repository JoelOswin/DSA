#include "linkedStack.h"

void push(stackNode** head, int key)
{
    stackNode* node = (stackNode*) malloc(sizeof(stackNode));
    if (!node) return;
    node->key = key;
    node->link = NULL;

    if (*head == NULL){
        *head = node;
    }
    
    node->link = *head;
    *head = node;
}

int pop(stackNode** head)
{
    stackNode* node = *head;
    (*head) = (*head)->link;
    int val=node->key;
    free(node);
    return val;
}

int peek(stackNode** head)
{
    return (*head)->key;
}