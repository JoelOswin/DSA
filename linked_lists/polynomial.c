#include "polynomial.h"

polyNode* CreateNode(int coeff, int exponenet)
{
    polyNode* node = (polyNode*) malloc(sizeof(polyNode));
    if (node == NULL) return NULL;
    node->coeff = coeff;
    node->exponent = exponenet;   
    node->link = NULL;
    return node;
}

void addTerm(polyNode** head, int coeff, int exponenet)
{
    polyNode* newNode = CreateNode(coeff, exponenet);
    if ((*head) == NULL){
        (*head) = newNode;
        return;
    }
    polyNode* current = *head;
    while (current->link!=NULL)
        current = current->link;
    current->link = newNode;
}

int deleteTerm(polyNode** head, int exponent){
    if ((*head)->exponent == exponent){
        int val = (*head)->coeff;
        *head = (*head)->link;
        return val; 
    }

    polyNode* node = *head;
    while(node->link != NULL){
        if (node->link->exponent == exponent){
            polyNode* temp = node->link;
            node->link = temp->link;
            int val = temp->coeff;
            free(temp);
            return val;
        }
        node = node->link;
    }
    return -1;
}

polyNode* polyAdd(polyNode* a, polyNode* b)
{
    polyNode* c = CreateNode(0,-1);
    polyNode* rear = c;
    polyNode* term = NULL;
    while(a && b){
        if (a->exponent == b->exponent){
            int sum = a->coeff + b->coeff;
            if (sum){
                term = CreateNode(sum, a->exponent);
                c->link = term;
                c = c->link;
            }
            a = a->link;
            b = b->link;
        } else if (b->exponent > a->exponent){
            term = CreateNode(b->coeff, b->exponent);
            c->link = term;
            b = b->link;
            c = c->link;
        } else if (a->exponent > b->exponent){
            term = CreateNode(a->coeff, a->exponent);
            c->link = term;
            a = a->link;
            c = c->link;
        }
    }

    while(a){
        term = CreateNode(a->coeff, a->exponent);
        c->link = term;
        a = a->link;
        c = c->link;
    }

    while(b){
        term = CreateNode(b->coeff, b->exponent);
        c->link = term;
        b = b->link;
        c = c->link;
    }

    if (rear->coeff == 0){
        polyNode* temp = rear;
        rear = rear->link;
        free(temp);
    }
    return rear;
}

void printpoly(polyNode* poly)
{
    while (poly!=NULL){
        printf("%d,%d ->", poly->coeff, poly->exponent);
        poly = poly->link;
    }
    printf("NULL");
}