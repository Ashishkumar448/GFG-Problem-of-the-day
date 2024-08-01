def is_safe(x, y, maze, visited):
    n = len(maze)
    return x >= 0 and x < n and y >= 0 and y < n and maze[x][y] == 1 and not visited[x][y]

def find_paths_util(x, y, maze, visited, path, paths):
    n = len(maze)
    
    # If destination (bottom-right corner) is reached
    if x == n - 1 and y == n - 1:
        paths.append(path)
        return
    
    # Mark the cell as visited
    visited[x][y] = True
    
    # Move in all four possible directions
    moves = ['D', 'L', 'R', 'U']
    row = [1, 0, 0, -1]
    col = [0, -1, 1, 0]
    
    for k in range(4):
        next_x = x + row[k]
        next_y = y + col[k]
        
        if is_safe(next_x, next_y, maze, visited):
            find_paths_util(next_x, next_y, maze, visited, path + moves[k], paths)
    
    # Unmark the cell (backtracking)
    visited[x][y] = False

def find_path(maze):
    paths = []
    n = len(maze)
    
    # If starting cell itself is blocked
    if maze[0][0] == 0:
        return paths
    
    visited = [[False for _ in range(n)] for _ in range(n)]
    
    find_paths_util(0, 0, maze, visited, "", paths)
    
    return paths

# Driver code
t = int(input())
for _ in range(t):
    n = int(input())
    maze = []
    for i in range(n):
        maze.append(list(map(int, input().split())))
    
    result = find_path(maze)
    result.sort()
    if result:
        print(" ".join(result))
    else:
        print(-1)
