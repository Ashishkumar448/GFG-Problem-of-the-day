class Solution:
    def minCost(self, height):
        n = len(height)
        if n == 1:
            return 0

        prev2 = 0  # dp[i-2]
        prev1 = abs(height[1] - height[0])  # dp[i-1]

        for i in range(2, n):
            oneStep = prev1 + abs(height[i] - height[i - 1])
            twoStep = prev2 + abs(height[i] - height[i - 2])
            curr = min(oneStep, twoStep)
            prev2, prev1 = prev1, curr

        return prev1
