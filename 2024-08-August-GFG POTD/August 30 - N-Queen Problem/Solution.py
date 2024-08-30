# { Driver Code Starts
# Initial Template for Python 3

class Solution:
    def nQueen(self, n):
        result = []
        board = [-1] * n  # Array to store the position of queens
        self.solveNQueens(0, board, n, result)
        return result

    def solveNQueens(self, row, board, n, result):
        if row == n:
            solution = [col + 1 for col in board]  # Convert 0-indexed to 1-indexed
            result.append(solution)
            return
        for col in range(n):
            if self.isSafe(row, col, board):
                board[row] = col
                self.solveNQueens(row + 1, board, n, result)

    def isSafe(self, row, col, board):
        for i in range(row):
            # Check if any queen in previous rows attacks the current position
            if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
                return False
        return True

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        ans = ob.nQueen(n)
        if len(ans) == 0:
            print("-1")
        else:
            for sol in ans:
                print(f"[{' '.join(map(str, sol))}] ", end="")
            print()
# } Driver Code Ends
