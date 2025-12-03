#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

typedef struct seq{
    int index;
    struct Node* node;
    struct seq* link;
} seq;

Node* CreateNode(int data);
void printClass(Node* head);
void printSeq(seq* head);