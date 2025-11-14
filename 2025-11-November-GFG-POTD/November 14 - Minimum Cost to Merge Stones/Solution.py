class Solution:
    def mergeStones(self, stones, k):
        n = len(stones)

        # Feasibility condition
        if (n - 1) % (k - 1) != 0:
            return -1

        # Prefix sums
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]

        INF = 10**12
        # dp[i][j][m] = min cost to merge stones i..j into m piles
        dp = [[[INF] * (k + 1) for _ in range(n)] for _ in range(n)]

        for i in range(n):
            dp[i][i][1] = 0

        for length in range(2, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1

                for m in range(2, k + 1):
                    mid = i
                    while mid < j:
                        dp[i][j][m] = min(dp[i][j][m],
                                          dp[i][mid][1] + dp[mid + 1][j][m - 1])
                        mid += (k - 1)

                # If we can merge k piles into 1
                if dp[i][j][k] < INF:
                    dp[i][j][1] = dp[i][j][k] + (prefix[j + 1] - prefix[i])

        return dp[0][n - 1][1]
