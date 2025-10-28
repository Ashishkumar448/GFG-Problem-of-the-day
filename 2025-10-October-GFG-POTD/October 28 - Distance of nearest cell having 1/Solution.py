from collections import deque

class Solution:
    def nearest(self, grid):
        n, m = len(grid), len(grid[0])
        dist = [[-1] * m for _ in range(n)]
        q = deque()
        
        # Initialize queue with all 1's
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))
        
        # Directions: up, down, left, right
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS
        while q:
            x, y = q.popleft()
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[x][y] + 1
                    q.append((nx, ny))
        
        return dist
