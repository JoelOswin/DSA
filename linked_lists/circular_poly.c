#include "circular_poly.h"

polyNode* pread(int coeff[], int exponent[], int n)
{
    polyNode* head = (polyNode*) malloc(sizeof(polyNode));
    if (head == NULL) return NULL;
    head->coeff=0;
    head->exponent=-1;
    head->link=NULL;

    polyNode* current = head;

    for (int i=0; i<n; i++){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return NULL;
        term->coeff = coeff[i];
        term->exponent = exponent[i];
        term->link = NULL;
        current->link = term;
        current = current->link;
    }
    current->link = head;

    return head;
}

void pwrite(polyNode* head)
{
    if (head == NULL) return;
    polyNode* current = head->link;
    while(current->link != head){
        if (current->link->coeff > 0)
            printf("%dx^%d +", current->coeff, current->exponent);
        else
            printf("%dx^%d ", current->coeff, current->exponent);
        current = current->link;
    }
    if (current != head)
        if (current->exponent==0)
            printf("%d", current->coeff);
        else
            printf("%dx^%d", current->coeff, current->exponent);
}

polyNode* padd(polyNode* a, polyNode* b)
{
    polyNode* head = (polyNode*) malloc(sizeof(polyNode));
    if (head == NULL) return NULL;
    head->coeff = 0;
    head->exponent = -1;
    head->link = NULL;

    polyNode* current = head;
    polyNode* head1 = a;
    polyNode* head2 = b;
    a = a->link;
    b = b->link;
    while ((a!=head1) && (b!=head2)){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        if (a->exponent == b->exponent){
            int sum = a->coeff + b->coeff;
            if (sum){
                term->coeff = sum;
                term->exponent = a->exponent;
                term->link = NULL;
                current->link = term;
                current = current->link;
            }
            a = a->link;
            b = b->link;
        }else if (b->exponent > a->exponent){
            term->coeff = b->coeff;
            term->exponent = b->exponent;
            term->link = NULL;
            current->link = term;
            current = current->link;
            b = b->link;
        }else if (a->exponent > b->exponent){
            term->coeff = a->coeff;
            term->exponent = a->exponent;
            term->link = NULL;
            current->link = term;
            current = current->link;
            a = a->link;           
        }
    }
    while (a!=head1){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        term->coeff = a->coeff;
        term->exponent = a->exponent;
        term->link = NULL;
        current->link = term;
        current = current->link;
        a = a->link;
    }

    while (b!=head2){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        term->coeff = b->coeff;
        term->exponent = b->exponent;
        term->link = NULL;
        current->link = term;
        current = current->link;
        b = b->link;
    }
    current->link = head;
    return head;
}

polyNode* psub(polyNode* a, polyNode* b)
{
    polyNode* head = (polyNode*) malloc(sizeof(polyNode));
    if (head == NULL) return NULL;
    head->coeff = 0;
    head->exponent = -1;
    head->link = NULL;

    polyNode* current = head;
    polyNode* head1 = a;
    polyNode* head2 = b;
    a = a->link;
    b = b->link;
    while ((a!=head1) && (b!=head2)){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        if (a->exponent == b->exponent){
            int sum = a->coeff - b->coeff;
            if (sum){
                term->coeff = sum;
                term->exponent = a->exponent;
                term->link = NULL;
                current->link = term;
                current = current->link;
            }
            a = a->link;
            b = b->link;
        }else if (b->exponent > a->exponent){
            term->coeff = -b->coeff;
            term->exponent = b->exponent;
            term->link = NULL;
            current->link = term;
            current = current->link;
            b = b->link;
        }else if (a->exponent > b->exponent){
            term->coeff = -a->coeff;
            term->exponent = a->exponent;
            term->link = NULL;
            current->link = term;
            current = current->link;
            a = a->link;           
        }
    }
    while (a!=head1){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        term->coeff = -a->coeff;
        term->exponent = a->exponent;
        term->link = NULL;
        current->link = term;
        current = current->link;
        a = a->link;
    }

    while (b!=head2){
        polyNode* term = (polyNode*) malloc(sizeof(polyNode));
        if (term == NULL) return head;
        term->coeff = -b->coeff;
        term->exponent = b->exponent;
        term->link = NULL;
        current->link = term;
        current = current->link;
        b = b->link;
    }
    current->link = head;
    return head;
}

float eval(polyNode* head, float x)
{
    polyNode* current = head->link;
    float sum = 0;
    while(current!=head){
        sum += (current->coeff * pow(x,current->exponent));
        current = current->link;
    }
    return sum;
}

polyNode* perase(polyNode** head)
{
    polyNode** current = &(*head)->link;
    while(*current != *head){
        polyNode** temp = &(*current)->link;
        free(*temp);
        *current = (*current)->link;
    }
    return *head;
}
