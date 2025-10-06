class Solution:
    def __init__(self):
        self.dx = [2, 1, -1, -2, -2, -1, 1, 2]
        self.dy = [1, 2, 2, 1, -1, -2, -2, -1]

    def isSafe(self, x, y, board, n):
        return 0 <= x < n and 0 <= y < n and board[x][y] == -1

    def solveKT(self, x, y, movei, board, n):
        if movei == n * n:
            return True

        for k in range(8):
            nextX = x + self.dx[k]
            nextY = y + self.dy[k]
            if self.isSafe(nextX, nextY, board, n):
                board[nextX][nextY] = movei
                if self.solveKT(nextX, nextY, movei + 1, board, n):
                    return True
                board[nextX][nextY] = -1  # backtrack
        return False

    def knightTour(self, n):
        board = [[-1 for _ in range(n)] for _ in range(n)]
        board[0][0] = 0

        if self.solveKT(0, 0, 1, board, n):
            return board
        else:
            return [[-1]]


# Example usage:
# sol = Solution()
# res = sol.knightTour(5)
# for row in res:
#     print(row)
