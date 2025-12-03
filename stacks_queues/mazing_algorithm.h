#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE_M 4
#define SIZE_N 4

typedef struct
{
    short int horizontal;
    short int vert;
} offset;

typedef struct
{
    int row;
    int col;
} element;

typedef struct
{
    element *arr;
    int top; 
} stack;

void InitializeMoves(offset moves[]);
void InitializeS(stack *stack);
void push(stack *stack, element item);
element pop(stack *stack);
void Initialize_Mark(int mark[SIZE_M+2][SIZE_N+2]);
bool solve_maze(int maze[SIZE_M][SIZE_N], stack *stack, int start_pos[2], int end_pos[2]);