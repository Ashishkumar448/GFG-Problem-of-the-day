class Solution:
    def tsp(self, cost):
        n = len(cost)
        if n == 0:
            return 0
        if n == 1:
            return cost[0][0]

        N = 1 << n
        INF = 10**15
        dp = [[INF] * n for _ in range(N)]

        dp[1][0] = 0  # start at city 0

        for mask in range(N):
            for u in range(n):
                if mask & (1 << u):
                    cur = dp[mask][u]
                    if cur >= INF:
                        continue
                    for v in range(n):
                        if not (mask & (1 << v)):
                            nextMask = mask | (1 << v)
                            dp[nextMask][v] = min(dp[nextMask][v], cur + cost[u][v])

        full = N - 1
        ans = min(dp[full][i] + cost[i][0] for i in range(1, n))
        return ans
