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

void InitializeMoves(offset moves[])
{
    moves[0].horizontal=-1; //North
    moves[0].vert=0;

    moves[1].horizontal=-1; //North-East
    moves[1].vert=1;

    moves[2].horizontal=0; //East
    moves[2].vert=1;

    moves[3].horizontal=1;  //South-East
    moves[3].vert=1;

    moves[4].horizontal=1;  //South
    moves[4].vert=0;

    moves[5].horizontal=1;  //South-West
    moves[5].vert=-1;

    moves[6].horizontal=0;  //West
    moves[6].vert=-1;

    moves[7].horizontal=-1; //North-West
    moves[7].vert=-1;
}

void InitializeS(stack *stack)
{
    stack->top = -1;
    stack->arr = malloc((SIZE_M*SIZE_N)*sizeof(element));
}

void push(stack *stack, element item)
{
    stack->arr[++stack->top]=item;
}

element pop(stack *stack)
{
    if (stack->top!=-1)
        return stack->arr[stack->top--];
    printf("Stack Empty!");
}

void Initialize_Mark(int maze[SIZE_M][SIZE_N], int mark[SIZE_M+2][SIZE_N+2])
{
        for (int i=0; i<SIZE_M+2; i++)
        if (i==0 || i==SIZE_M+1)
            for (int j=0; j<SIZE_N+2; j++)
                mark[i][j]=1;
        else{
            mark[i][0]=1;
            mark[i][SIZE_N+1]=1;

            for (int j=0; j<SIZE_N; j++)
                mark[i][j+1]=0; //maze[i-1][j];
        }
}

bool solve_maze(int maze[SIZE_M][SIZE_N], int start_pos[2], int end_pos[2])
{
    stack stack;
    offset moves[8];
    int mark[SIZE_M+2][SIZE_N+2];
    int row, col, nextRow, nextCol;
    element current_pos, next_pos;

    Initialize_Mark(maze, mark);
    InitializeS(&stack);
    InitializeMoves(moves);

    start_pos[0]+=1, start_pos[1]+=1;
    end_pos[0]+=1, end_pos[1]+=1;

    current_pos.row=start_pos[0], row=start_pos[0];
    current_pos.col=start_pos[1], col=start_pos[1];
    push(&stack, current_pos);

    while(stack.top!=-1)
    {
        current_pos=pop(&stack);
        row=current_pos.row, col=current_pos.col;

        int dir=0;
        while (dir < 8){
            nextRow = row + moves[dir].horizontal;
            nextCol = col + moves[dir].vert;

            if (nextRow == end_pos[0] && nextCol == end_pos[1]){
                mark[nextRow][nextCol] = 1;
                printf("Path Found!\n");
                return true;
            }

            if (mark[nextRow][nextCol]==0 && maze[nextRow-1][nextCol-1]==0){
                mark[nextRow][nextCol]=1;
                row = nextRow;
                col = nextCol;
                dir = 0;
                next_pos.row = nextRow, next_pos.col = nextCol;
                push(&stack, next_pos);
                continue;
            }
            dir++;
        }
    }
    printf("No path found!");
    return false;
}

void main()
{
    offset moves[8];
    stack stack;
    int maze[SIZE_M][SIZE_N] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int mark[6][6];
    int start_pos[2]={0,0}, end_pos[2]={3,3}; 
    bool is_solved = solve_maze(maze, start_pos, end_pos);
    
    printf("\n%s", is_solved? "true":"false");
    /*
    for (int i=0; i<6; i++){ 
        for (int j=0; j<6; j++)
            printf("%d ", mark[i][j]);
        printf("\n");
    }
    */
}