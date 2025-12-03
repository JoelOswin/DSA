#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int top;
    int capacity;
} stack;

typedef enum{
    lparen, rparen, add, sub, mul, divide, mod, eos, operand
} precedence;

precedence getToken(char expr[], char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return add;
        case '-': return sub;
        case '*': return mul;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void InitializeS(stack *stack)
{
    stack->top=-1;
    stack->capacity=5;
    stack->arr=malloc(stack->capacity*sizeof(int));
}

void stackFull(stack *stack)
{
    stack->arr = realloc(stack->arr, 2*stack->capacity*sizeof(int));
    stack->capacity *= 2;
}

void push(stack *stack, int element)
{
    if (stack->top == stack->capacity-1)
        stackFull(stack);
    stack->arr[++stack->top]=element;
}

int pop(stack *stack)
{
    if (stack->top==-1){
        printf("Stack Empty!");
    }
    return stack->arr[stack->top--];
}

int eval(char expr[])
{
    int n=0;
    char symbol;

    stack stack;
    InitializeS(&stack);

    precedence token;
    token = getToken(expr, &symbol, &n);

    while (token != eos){
        if (token == operand)
            push(&stack, symbol-'0');
        else{

            int oper1 = pop(&stack);
            int oper2 = pop(&stack);

            switch(token)
            {
                case add: 
                    push(&stack, (oper1+oper2));
                    break;
                case sub: 
                    push(&stack, (oper1-oper2));
                    break;
                case mul:
                    push(&stack, (oper1*oper2));
                    break;
                case divide:
                    push(&stack, (oper1/oper2));
                    break;
                case mod:
                    push(&stack, (oper1%oper2));
            }
        }
        token = getToken(expr, &symbol, &n);
    }
    return pop(&stack);
}

void main()
{
    char expr[10];
    printf("Enter a postfix expression: ");
    scanf("%s", &expr);

    int solution = eval(expr);
    printf("\nSolution: %d", solution);
}