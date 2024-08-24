class Solution:
    def knapSack(self, W, wt, val):
        n = len(wt)
        dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
        
        # Build the dp array from bottom up
        for i in range(n + 1):
            for w in range(W + 1):
                if i == 0 or w == 0:
                    dp[i][w] = 0
                elif wt[i - 1] <= w:
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])
                else:
                    dp[i][w] = dp[i - 1][w]
        
        return dp[n][W]


if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        W = int(input())
        val = list(map(int, input().split()))
        wt = list(map(int, input().split()))

        solution = Solution()
        print(solution.knapSack(W, wt, val))


