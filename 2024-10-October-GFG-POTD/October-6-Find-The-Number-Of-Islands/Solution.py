class Solution:
    def dfs(self, grid, i, j, visited):
        # Check boundary conditions and if the current cell is land and not visited
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0' or visited[i][j]:
            return

        # Mark the current cell as visited
        visited[i][j] = True

        # Explore all 8 possible directions
        rowNbr = [-1, -1, -1, 0, 0, 1, 1, 1]
        colNbr = [-1, 0, 1, -1, 1, -1, 0, 1]

        for k in range(8):
            self.dfs(grid, i + rowNbr[k], j + colNbr[k], visited)

    def numIslands(self, grid):
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])
        visited = [[False for _ in range(m)] for _ in range(n)]

        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.dfs(grid, i, j, visited)
                    count += 1
        return count


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        grid = [list(input().split()) for _ in range(n)]
        obj = Solution()
        print(obj.numIslands(grid))
