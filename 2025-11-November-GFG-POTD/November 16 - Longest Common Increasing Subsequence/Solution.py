class Solution:
    def LCIS(self, a, b):
        n, m = len(a), len(b)
        dp = [0] * m
        ans = 0

        for i in range(n):
            currentMax = 0

            for j in range(m):
                if a[i] > b[j]:
                    currentMax = max(currentMax, dp[j])
                elif a[i] == b[j]:
                    dp[j] = currentMax + 1
                    ans = max(ans, dp[j])

        return ans
