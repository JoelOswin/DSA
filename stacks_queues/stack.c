#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STACK_SIZE 10

struct element{
    int id;
    char name[25];
};

struct stack{
    struct element arr[MAX_STACK_SIZE];
    int top;
};

void InitializeS(struct stack* stack)
{
    stack->top=-1;
}

void Push(struct stack* stack, struct element item, int size)
{
    if (stack->top>=size-1)
        return;
    stack->arr[++stack->top]=item;
}

struct element pop(struct stack* stack, int size)
{
    if (stack->top!=-1)
        return stack->arr[stack->top--];
}

void main()
{
    struct stack stack;
    struct element item;
    InitializeS(&stack);

    item.id=1;
    strcpy(item.name,"Joel Oswin J");
    Push(&stack,item,10);

    item.id=2;
    strcpy(item.name,"Steph Curry");
    Push(&stack,item,10);
    
    printf("%s\n", pop(&stack, 10).name);

    for (int i=0; i<=stack.top; i++)
        printf("%d-%s\n", stack.arr[i].id, stack.arr[i].name);
}