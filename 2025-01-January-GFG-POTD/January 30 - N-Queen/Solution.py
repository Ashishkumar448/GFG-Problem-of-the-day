class Solution:
    def nQueen(self, n: int):
        results = []
        board = [0] * n  # board[i] = row position of queen in column i
        self.solveNQueens(n, 0, board, results)
        return results

    def solveNQueens(self, n: int, col: int, board: list[int], results: list[list[int]]):
        if col == n:
            # A valid configuration is found; add it to results
            solution = [board[i] + 1 for i in range(n)]  # converting to 1-based index
            results.append(solution)
            return

        for row in range(n):
            if self.isSafe(row, col, board):
                board[col] = row  # Place queen
                self.solveNQueens(n, col + 1, board, results)  # Recur to place rest of the queens

    def isSafe(self, row: int, col: int, board: list[int]) -> bool:
        for i in range(col):
            # Check if the queen can be attacked
            if board[i] == row or abs(board[i] - row) == abs(i - col):
                return False
        return True

# Example usage
if __name__ == "__main__":
    sol = Solution()
    n = 4  # Change this value to test with different sizes
    solutions = sol.nQueen(n)
    
    for solution in solutions:
        print(f"[{' '.join(map(str, solution))}] ", end="")
    print()
