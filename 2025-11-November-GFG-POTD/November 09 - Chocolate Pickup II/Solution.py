class Solution:
    def chocolatePickup(self, mat):
        n = len(mat)
        if mat[0][0] == -1 or mat[n - 1][n - 1] == -1:
            return 0

        dp = [[[None for _ in range(n)] for _ in range(n)] for _ in range(n)]

        def dfs(r1, c1, r2):
            c2 = r1 + c1 - r2
            if (r1 >= n or c1 >= n or r2 >= n or c2 >= n or
                mat[r1][c1] == -1 or mat[r2][c2] == -1):
                return float('-inf')

            if r1 == n - 1 and c1 == n - 1:
                return mat[r1][c1]

            if dp[r1][c1][r2] is not None:
                return dp[r1][c1][r2]

            chocolates = mat[r1][c1]
            if r1 != r2 or c1 != c2:
                chocolates += mat[r2][c2]

            next_moves = max(
                dfs(r1 + 1, c1, r2 + 1),
                dfs(r1, c1 + 1, r2),
                dfs(r1 + 1, c1, r2),
                dfs(r1, c1 + 1, r2 + 1)
            )

            chocolates += next_moves
            dp[r1][c1][r2] = chocolates
            return chocolates

        return max(0, dfs(0, 0, 0))
