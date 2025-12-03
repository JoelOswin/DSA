#include "linkedlist.h"

void main()
{
    listNode* head = NULL;

    InsertElement(&head, 2);
    InsertElement(&head, 3);
    InsertElement(&head, 5);
    InsertElement(&head, 4);
    printList(head);

    printf("\n");
    DeleteElement(&head, 4);

    listNode* head2 = NULL;

    InsertElement(&head2, 7);
    listNode* merged = merge(head, head2);
    printList(merged);

    freeList(head);
    freeList(head2);
    freeList(merged);
}