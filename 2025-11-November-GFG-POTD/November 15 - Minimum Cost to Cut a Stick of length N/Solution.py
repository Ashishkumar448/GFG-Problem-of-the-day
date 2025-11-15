class Solution:
    def minCutCost(self, n: int, cuts: List[int]) -> int:
        m = len(cuts)
        arr = [0] + sorted(cuts) + [n]

        dp = [[0] * (m + 2) for _ in range(m + 2)]

        # dp[i][j] = min cost to cut stick between arr[i] and arr[j]
        for length in range(2, m + 2):
            for i in range(m + 2 - length):
                j = i + length
                dp[i][j] = float('inf')

                for k in range(i + 1, j):
                    dp[i][j] = min(
                        dp[i][k] + dp[k][j] + arr[j] - arr[i],
                        dp[i][j]
                    )

                if dp[i][j] == float('inf'):
                    dp[i][j] = 0

        return dp[0][m + 1]
