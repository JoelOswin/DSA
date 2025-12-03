#include "doubly_linked_list.h"

void main()
{
    Node* head = CreateHead();
    addNode(&head, 10, 1);
    removeNode(&head, 0);
    removeNode(&head, 0);
    addNode(&head, 11, 1);
    addNode(&head, 9, 0);
    addNode(&head, 11, 1);
    addNode(&head, 8, 0);
    addNode(&head, 12, 0);
    printList(head, 0);
}