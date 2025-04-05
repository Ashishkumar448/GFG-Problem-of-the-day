class Solution:
    def __init__(self):
        self.dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        self.dy = [-1, 0, 1, -1, 1, -1, 0, 1]

    def is_valid(self, x, y, n, m):
        return 0 <= x < n and 0 <= y < m

    def dfs(self, grid, visited, x, y, n, m):
        visited[x][y] = True
        for dir in range(8):
            newX = x + self.dx[dir]
            newY = y + self.dy[dir]
            if (self.is_valid(newX, newY, n, m) and
                grid[newX][newY] == 'L' and not visited[newX][newY]):
                self.dfs(grid, visited, newX, newY, n, m)

    def countIslands(self, grid):
        n = len(grid)
        m = len(grid[0])
        visited = [[False for _ in range(m)] for _ in range(n)]
        count = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'L' and not visited[i][j]:
                    self.dfs(grid, visited, i, j, n, m)
                    count += 1
        return count


# Driver Code
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    grid = [input().split() for _ in range(n)]

    obj = Solution()
    print(obj.countIslands(grid))
    print("~")
