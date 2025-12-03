#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_STACK_SIZE 2

typedef struct{
    int id;
    char name[25];
} element;

typedef struct{
    element *arr;
    int top;
    int capacity;
} stack;

void InitializeS(stack *stack)
{
    stack->capacity=INITIAL_STACK_SIZE;
    stack->arr = malloc(sizeof(element)*stack->capacity);
    stack->top=-1;
}

void StackFull(stack *stack)
{
    stack->arr = realloc(stack->arr, 2*sizeof(element)*stack->capacity);
    stack->capacity*=2;
}

void push(stack *stack, element item)
{
    if (stack->top==stack->capacity-1)
        StackFull(stack);
    stack->arr[++stack->top]=item;
}

element pop(stack *stack)
{
    if (stack->top==-1)
        printf("Stack Empty!");
    else
        return stack->arr[stack->top--];
}

void main()
{
    stack stack;
    element item;
    InitializeS(&stack);

    for (int i=1; i<=5; i++){
        item.id=i;
        strcpy(item.name,"Steph Curry");
        push(&stack,item);   
    }
    
    printf("%s\n", pop(&stack).name);

    for (int i=0; i<=stack.top; i++)
        printf("%d-%s\n", stack.arr[i].id, stack.arr[i].name);
}