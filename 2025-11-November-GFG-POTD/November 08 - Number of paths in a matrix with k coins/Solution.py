class Solution:
    def numberOfPath(self, mat, k):
        n, m = len(mat), len(mat[0])
        dp = [[[None for _ in range(k + 1)] for _ in range(m)] for _ in range(n)]
        
        def helper(i, j, k):
            # Out of bounds
            if i >= n or j >= m:
                return 0
            
            # If at bottom-right
            if i == n - 1 and j == m - 1:
                return 1 if k == mat[i][j] else 0
            
            # Memoization check
            if dp[i][j][k] is not None:
                return dp[i][j][k]
            
            # If current cell value > remaining sum
            if k < mat[i][j]:
                dp[i][j][k] = 0
                return 0
            
            # Move down and right
            down = helper(i + 1, j, k - mat[i][j])
            right = helper(i, j + 1, k - mat[i][j])
            
            dp[i][j][k] = down + right
            return dp[i][j][k]
        
        return helper(0, 0, k)
