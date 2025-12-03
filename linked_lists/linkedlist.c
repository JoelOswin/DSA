#include "linkedlist.h"

void InsertElement(listNode** head, int element)
{
    if ((*head) == NULL){
        (*head) = malloc(sizeof(listNode));
        (*head)->num = element;
        (*head)->link = NULL;
        return;
    }

    listNode* node = malloc(sizeof(listNode));
    if (node == NULL) return;
    node->num = element;
    node->link = NULL;

    listNode* current = (*head);
    while (current->link != NULL){
        current = current->link;
    }
    current->link = node;
}

int DeleteElement(listNode** head, int element)
{
    if (*head == NULL)
        return -1;

    if ((*head)->num == element){
        int return_val = (*head)->num;
        free(*head);
        return return_val;
    }

    if ((*head)->link == NULL)
        return -1;
    
    listNode* current = (*head)->link;
    while(current->link!=NULL){
        if (current->link->num == element){
            listNode* trail = current->link;
            int value = trail->num;
            current->link = current->link->link;  
            free(trail);
            return value;
        }
        current = current->link;
    }
    return -1;
}

int length(listNode* list)
{
    int count = 0;
    listNode* local = list;
    while (local != NULL){
        count++;
        local = local->link;
    }
    return count;
}

listNode* merge(listNode* list1, listNode* list2)
{
    int m = length(list1), n = length(list2);
    listNode* head = NULL;
    
    while (list1!=NULL){
        InsertElement(&head, list1->num);
        list1 = list1->link;
    }
    while (list2!=NULL){
        InsertElement(&head, list2->num);
        list2 = list2->link;
    }

    return head;
}

void printList(listNode *head)
{
    if (head==NULL)
        return;
    printf("%d, ", head->num);
    return printList(head->link);
}

void freeList(listNode *head)
{
    while (head != NULL){
        listNode *temp = head;
        head = head->link;
        free(temp);
    }
}