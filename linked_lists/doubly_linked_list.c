#include "doubly_linked_list.h"

Node* CreateHead()
{
    Node* head = (Node*) malloc(sizeof(Node));
    if (head == NULL) return NULL;
    head->llink = head;
    head->rlink = head;
    head->data = -1;
    return head;
}

Node* CreateNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->data = data;
    node->llink = NULL;
    node->rlink = NULL;
    return node;
}

void addNode(Node** head, int data, int dir)
{
    if (head == NULL) return;
    if ((*head)->llink == (*head)){
        Node* node = CreateNode(data);
        if (node == NULL) return;
        (*head)->llink = node;
        (*head)->rlink = node;
        node->llink = (*head);
        node->rlink = (*head);
        return;
    }

    Node* node = CreateNode(data);
    if (node == NULL) return;
    if (dir){
        Node* current = (*head)->rlink;
        current->rlink = node;
        node->llink = current;
        node->rlink = (*head);
        (*head)->rlink = node;
    }else{
        Node* current = (*head)->llink;
        current->llink = node;
        node->rlink = current;
        node->llink = (*head);
        (*head)->llink = node;
    }
}

int removeNode(Node** head, int dir)
{
    if (head == NULL) return -1;
    if ((*head)->llink == (*head)) return -1;
    int return_val=-1;
    if (dir){
        Node* rtemp = (*head)->rlink;
        Node* current = rtemp->llink;
        current->rlink = (*head);
        (*head)->rlink = current;
        return_val = rtemp->data;
        free(rtemp);
    }else{
        Node* ltemp = (*head)->llink;
        Node* current = ltemp->rlink;
        current->llink = (*head);
        (*head)->llink = current;
        return_val = ltemp->data;
        free(ltemp);
    }
    return return_val;
}

void printList(Node* head, int dir)
{
    if (head == NULL) return;
    if (!dir){
        head = head->llink;
        while(head->data != -1){
            printf("%d,", head->data);
            head = head->rlink;
        }
    }else{
        head = head->rlink;
        while(head->data != -1){
            printf("%d,", head->data);
            head = head->llink;
        }
    }
}
