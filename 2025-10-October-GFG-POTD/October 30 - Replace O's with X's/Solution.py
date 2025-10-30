class Solution:
    def fill(self, grid):
        if not grid or not grid[0]:
            return
        
        n, m = len(grid), len(grid[0])
        
        # Helper DFS function
        def dfs(i, j):
            if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != 'O':
                return
            grid[i][j] = '#'  # mark as safe
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)
        
        # Step 1: Mark border-connected 'O's
        for i in range(n):
            if grid[i][0] == 'O':
                dfs(i, 0)
            if grid[i][m - 1] == 'O':
                dfs(i, m - 1)
        for j in range(m):
            if grid[0][j] == 'O':
                dfs(0, j)
            if grid[n - 1][j] == 'O':
                dfs(n - 1, j)
        
        # Step 2: Replace surrounded 'O' → 'X' and '#' → 'O'
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'O':
                    grid[i][j] = 'X'
                elif grid[i][j] == '#':
                    grid[i][j] = 'O'
