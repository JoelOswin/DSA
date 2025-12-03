#include "equivalence_class.h"

Node* CreateNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}

void printClass(Node* head)
{
    head = head->link;
    printf("{");
    while (head->data != -1){
        printf("%d,", head->data);
        head = head->link;
    }
    printf("}\n");
}

void printSeq(seq* head)
{
    head = head->link;
    while(head->index != -1){
        printf("(%d,%d)\n", head->node->data, head->node->link->data);
        head = head->link;
    }
}