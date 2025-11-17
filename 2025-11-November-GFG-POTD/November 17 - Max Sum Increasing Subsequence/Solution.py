class Solution:
    def maxSumIS(self, arr):
        n = len(arr)
        
        dp = arr[:]  # Each element is at least a subsequence of itself
        maxSum = arr[0]
        
        for i in range(1, n):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i] = max(dp[i], dp[j] + arr[i])
            maxSum = max(maxSum, dp[i])
        
        return maxSum
