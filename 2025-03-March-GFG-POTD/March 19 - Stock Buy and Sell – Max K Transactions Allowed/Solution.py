class Solution:
    def maxProfit(self, k: int, prices: list) -> int:
        n = len(prices)
        if n == 0 or k == 0:
            return 0

        # If k is large enough, treat it as unlimited transactions
        if k >= n // 2:
            return sum(max(prices[i] - prices[i - 1], 0) for i in range(1, n))

        # DP table
        dp = [[0] * n for _ in range(k + 1)]

        for i in range(1, k + 1):
            maxDiff = -prices[0]
            for j in range(1, n):
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff)
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j])

        return dp[k][n - 1]

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    
    for _ in range(t):
        prices = list(map(int, input().strip().split()))
        k = int(input().strip())

        obj = Solution()
        print(obj.maxProfit(k, prices))
        print("~")
