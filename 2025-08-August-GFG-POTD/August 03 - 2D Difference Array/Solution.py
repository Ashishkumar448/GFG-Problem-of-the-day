class Solution:
    def applyDiff2D(self, mat, opr):
        n = len(mat)
        m = len(mat[0])

        # Step 1: Initialize diff matrix
        diff = [[0] * (m + 2) for _ in range(n + 2)]  # Padding to avoid bounds check

        # Step 2: Apply operations to diff matrix
        for op in opr:
            val, r1, c1, r2, c2 = op
            diff[r1][c1] += val
            if c2 + 1 < m:
                diff[r1][c2 + 1] -= val
            if r2 + 1 < n:
                diff[r2 + 1][c1] -= val
            if r2 + 1 < n and c2 + 1 < m:
                diff[r2 + 1][c2 + 1] += val

        # Step 3: 2D prefix sum over rows
        for i in range(n):
            for j in range(1, m):
                diff[i][j] += diff[i][j - 1]

        # Step 4: 2D prefix sum over columns
        for j in range(m):
            for i in range(1, n):
                diff[i][j] += diff[i - 1][j]

        # Step 5: Add diff to original matrix and prepare result
        res = []
        for i in range(n):
            row = []
            for j in range(m):
                row.append(mat[i][j] + diff[i][j])
            res.append(row)

        return res
