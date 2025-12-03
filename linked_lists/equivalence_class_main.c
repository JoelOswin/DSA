#include "equivalence_class.h"

void main()
{
    int i=0,j=0,index=0;
    seq* head = (seq*) malloc(sizeof(seq));
    head->index = -1;
    head->link = head;
    seq* current = head;

    // PHASE 1 : Creation of sequence
    printf("Enter pairs (Enter -1 -1 to stop): ");
    for (;;){
        scanf("%d %d", &i, &j);
        if((i!=-1)&&(j!=-1)){
            Node* node = CreateNode(i);
            Node* node1 = CreateNode(j);
            node->link = node1;
            node1->link = NULL;

            seq* newTerm = (seq*) malloc(sizeof(Node));
            newTerm->index = 0;
            newTerm->node = node;
            newTerm->link = head; 

            current->link = newTerm;
            current = current->link; 
        }else 
            break;
    }
    printSeq(head);    

    // PHASE 2 : Creation of equivalence class
    current=head->link;
    seq* eq_class_head = (seq*) malloc(sizeof(seq));
    eq_class_head->index = -1;
    eq_class_head->link = eq_class_head;
    seq* current_eq = eq_class_head;

    while(current->index != -1){
        
    }
}