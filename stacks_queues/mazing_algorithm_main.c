#include "mazing_algorithm.h"

void main()
{
    stack stack;
    int maze[SIZE_M][SIZE_N] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };

    int start_pos[2]={0,0}, end_pos[2]={2,1}; 
    bool is_solved = solve_maze(maze, &stack, start_pos, end_pos);
    
    printf("\n%s", is_solved? "true":"false");
    /*
    for (int i=0; i<6; i++){ 
        for (int j=0; j<6; j++)
            printf("%d ", mark[i][j]);
        printf("\n");
    }
    */

    int top = stack.top;
    printf("\nPATH:\n");
    for(int i=0; top!=-1; top--, i++){
        if (top==0){ 
            printf("(%d,%d)", stack.arr[i].row, stack.arr[i].col);
            continue;
        }
        printf("(%d,%d)->", stack.arr[i].row, stack.arr[i].col);
    }

    free(stack.arr);
}