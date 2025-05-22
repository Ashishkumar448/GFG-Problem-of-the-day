class Solution:
    @staticmethod
    def minDeletions(s: str) -> int:
        n = len(s)
        rev = s[::-1]
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        # Fill dp table for LCS between s and rev
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if s[i - 1] == rev[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        lps_length = dp[n][n]
        return n - lps_length
