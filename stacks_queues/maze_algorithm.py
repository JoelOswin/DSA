moves = [(-1,0), (-1,1), (0,1), (1,1), (1,0), (1,-1), (1,-1), (-1,-1)]
stack=[]

def solve_maze(maze, start_pt, exit_pt):
    mark=[]
    for i in range(len(maze)+2):
        if i==0 or i==len(maze)+1:
            mark.append([1 for _ in range(len(maze[0])+2)])
        else:
            mark.append([1] + [0 for _ in range(len(maze[0]))] + [1])
    
    start_pt = start_pt[0]+1, start_pt[0]+1
    exit_pt = exit_pt[0]+1, exit_pt[0]+1

    current_pos=(1,1)
    stack.append(current_pos)
    mark[1][1]=1
    found = False

    while (stack != []):
        current_pos = stack[-1]
        row=current_pos[0]
        col=current_pos[1]
        dir=0
        while dir<8:
            nextRow = row + moves[dir][0]
            nextCol = col + moves[dir][1]
            #print(maze[nextRow-1][nextCol-1])
            if (nextRow == exit_pt[0] and nextCol == exit_pt[1]):
                stack.append((nextRow,nextCol))
                mark[nextRow][nextCol]=1
                return True

            if (mark[nextRow][nextCol]==0 and maze[nextRow-1][nextCol-1]==0):
                mark[nextRow][nextCol]=1
                stack.append((nextRow,nextCol))
                row = nextRow
                col = nextCol
                dir=0
            dir+=1
        if (not found):
            stack.pop()

    return False

maze = [
    [0, 1, 1, 1],
    [0, 0, 0, 1],
    [0, 1, 1, 1],
    [0, 0, 0, 0]
]    

solution = solve_maze(maze, (0,0), (3,3))

print(stack)