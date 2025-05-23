class Solution:
    @staticmethod
    def noOfWays(m, n, x):
        # Create dp table
        dp = [[0] * (x + 1) for _ in range(n + 1)]
        
        # Base case
        dp[0][0] = 1
        
        # Fill the dp table
        for dice in range(1, n + 1):
            for total in range(1, x + 1):
                for face in range(1, m + 1):
                    if total - face >= 0:
                        dp[dice][total] += dp[dice - 1][total - face]
        
        return dp[n][x]
