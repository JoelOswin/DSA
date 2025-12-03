#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int num;
    struct listNode *link;
} listNode;

void InsertElement(listNode**, int);
int DeleteElement(listNode**, int);
int length(listNode*);
listNode* merge(listNode*, listNode*);
void freeList(listNode*);
void printList(listNode*);