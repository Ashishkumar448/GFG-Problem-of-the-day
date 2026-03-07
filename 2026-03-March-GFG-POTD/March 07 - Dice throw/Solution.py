class Solution:
    def noOfWays(self, m, n, x):
        dp = [[0]*(x+1) for _ in range(n+1)]

        # Base case
        dp[0][0] = 1

        for dice in range(1, n+1):
            for s in range(1, x+1):
                for face in range(1, m+1):
                    if s - face >= 0:
                        dp[dice][s] += dp[dice-1][s-face]

        return dp[n][x]
