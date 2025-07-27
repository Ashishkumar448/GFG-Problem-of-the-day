class Solution:
    def setMatrixZeroes(self, mat):
        n = len(mat)
        m = len(mat[0])

        first_row_zero = False
        first_col_zero = False

        # Step 1: Check first column for zeros
        for i in range(n):
            if mat[i][0] == 0:
                first_col_zero = True
                break

        # Step 2: Check first row for zeros
        for j in range(m):
            if mat[0][j] == 0:
                first_row_zero = True
                break

        # Step 3: Use first row and column as markers
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = 0
                    mat[0][j] = 0

        # Step 4: Zero based on markers
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0

        # Step 5: Zero first row and column
        if first_row_zero:
            for j in range(m):
                mat[0][j] = 0

        if first_col_zero:
            for i in range(n):
                mat[i][0] = 0
