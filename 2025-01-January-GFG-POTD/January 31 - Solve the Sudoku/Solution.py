class Solution:
    # Function to find a solved Sudoku
    def solveSudoku(self, mat):
        self.solveSudokuUtil(mat)

    # Utility function to solve the Sudoku using backtracking
    def solveSudokuUtil(self, mat):
        row, col = -1, -1
        empty = True

        # Find an empty cell (represented by 0)
        for r in range(9):
            for c in range(9):
                if mat[r][c] == 0:
                    row, col = r, c
                    empty = False
                    break
            if not empty:
                break

        # If no empty cell is found, the Sudoku is solved
        if empty:
            return True

        # Try digits from 1 to 9
        for num in range(1, 10):
            if self.isSafe(mat, row, col, num):
                mat[row][col] = num  # Place the number

                # Recursively call the function to continue solving
                if self.solveSudokuUtil(mat):
                    return True

                # If placing num doesn't lead to a solution, reset it
                mat[row][col] = 0

        return False  # Trigger backtracking

    # Function to check if placing num in mat[row][col] is valid
    def isSafe(self, mat, row, col, num):
        # Check the row and column
        for x in range(9):
            if mat[row][x] == num or mat[x][col] == num:
                return False

        # Check the 3x3 box
        startRow, startCol = row - row % 3, col - col % 3
        for i in range(3):
            for j in range(3):
                if mat[i + startRow][j + startCol] == num:
                    return False

        return True


# Driver code
if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        mat = []
        for i in range(9):
            row = list(map(int, input().split()))
            mat.append(row)

        sol = Solution()
        sol.solveSudoku(mat)

        for i in range(9):
            print(" ".join(map(str, mat[i])))
        print("~")
