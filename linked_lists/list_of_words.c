/*
SINGLY LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode 
{
    char string[20];
    struct listNode *link;
}listNode;

void printList(listNode *link)
{
    if (link==NULL)
        return;
    printf("%s", link->string);
    return printList(link->link);
}

void main()
{
    listNode *first = NULL;

    listNode data[10];
    strcpy(data[5].string, "Joel");
    first = &data[5];
    
    strcpy(data[3].string, " ");
    first->link = &data[3];

    strcpy(data[8].string, "Oswin");
    data[3].link = &data[8];
    data[8].link = NULL;

    printList(first);
}