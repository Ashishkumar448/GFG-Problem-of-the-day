class Solution:
    def minCost(self, keys, freq):
        n = len(keys)
        dp = [[0] * n for _ in range(n)]

        # prefix frequency sum
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + freq[i]

        for length in range(1, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1

                dp[i][j] = float('inf')
                total_freq = prefix[j + 1] - prefix[i]

                for r in range(i, j + 1):
                    left = dp[i][r - 1] if r > i else 0
                    right = dp[r + 1][j] if r < j else 0
                    dp[i][j] = min(dp[i][j], left + right + total_freq)

        return dp[0][n - 1]
