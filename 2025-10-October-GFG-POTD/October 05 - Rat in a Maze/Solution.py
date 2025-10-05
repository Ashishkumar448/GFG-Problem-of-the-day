class Solution:
    def ratInMaze(self, maze):
        n = len(maze)
        result = []

        # If start or destination is blocked
        if maze[0][0] == 0 or maze[n - 1][n - 1] == 0:
            return result

        visited = [[False for _ in range(n)] for _ in range(n)]
        self.backtrack(0, 0, maze, n, "", visited, result)
        result.sort()  # lexicographic order
        return result

    def backtrack(self, i, j, maze, n, path, visited, result):
        # Base case: reached destination
        if i == n - 1 and j == n - 1:
            result.append(path)
            return

        visited[i][j] = True

        # Directions: D, L, R, U
        di = [1, 0, 0, -1]
        dj = [0, -1, 1, 0]
        dirs = ['D', 'L', 'R', 'U']

        for k in range(4):
            ni, nj = i + di[k], j + dj[k]
            if self.isSafe(ni, nj, maze, visited, n):
                self.backtrack(ni, nj, maze, n, path + dirs[k], visited, result)

        visited[i][j] = False  # backtrack

    def isSafe(self, i, j, maze, visited, n):
        return 0 <= i < n and 0 <= j < n and maze[i][j] == 1 and not visited[i][j]
