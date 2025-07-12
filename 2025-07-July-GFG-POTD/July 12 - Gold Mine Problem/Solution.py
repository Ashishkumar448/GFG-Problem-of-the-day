class Solution:
    def maxGold(self, mat):
        n = len(mat)
        m = len(mat[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]

        # Fill the last column
        for i in range(n):
            dp[i][m - 1] = mat[i][m - 1]

        # Fill the table from second-last column to the first
        for j in range(m - 2, -1, -1):
            for i in range(n):
                right = dp[i][j + 1]
                right_up = dp[i - 1][j + 1] if i > 0 else 0
                right_down = dp[i + 1][j + 1] if i < n - 1 else 0

                dp[i][j] = mat[i][j] + max(right, right_up, right_down)

        # The maximum value in the first column will be the result
        return max(dp[i][0] for i in range(n))
