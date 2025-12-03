#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* llink;
    struct Node* rlink;
} Node;

Node* CreateNode(int data);
Node* CreateHead();
void addNode(Node** head, int data, int dir); // 1 for right, 0 for left
int removeNode(Node** head, int dir); // dir = 1 for right, 0 for left
void printList(Node* head, int dir);