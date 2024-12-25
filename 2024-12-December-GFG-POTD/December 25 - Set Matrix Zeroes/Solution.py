class Solution:
    def setMatrixZeroes(self, mat):
        n, m = len(mat), len(mat[0])

        # Flags to determine if first row and column need to be set to zero
        firstRowZero = any(mat[0][j] == 0 for j in range(m))
        firstColZero = any(mat[i][0] == 0 for i in range(n))

        # Mark rows and columns to be zeroed in the first row and column
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = 0  # Mark the row
                    mat[0][j] = 0  # Mark the column

        # Set the matrix cells to zero based on the markers
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0

        # Handle the first row
        if firstRowZero:
            for j in range(m):
                mat[0][j] = 0

        # Handle the first column
        if firstColZero:
            for i in range(n):
                mat[i][0] = 0


# Driver code
if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        n, m = map(int, input().split())
        mat = [list(map(int, input().split())) for _ in range(n)]

        Solution().setMatrixZeroes(mat)

        for row in mat:
            print(" ".join(map(str, row)))

        print("~")
