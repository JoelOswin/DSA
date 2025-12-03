#include "linkedStack.h"
#define MAX_STACKS 1

void main()
{
    stackNode top[MAX_STACKS];
    
    push(&top[0], 1);
    push(&top[0], 2);
    push(&top[0], 3);
    printf("%d", pop(&top[0]));
}