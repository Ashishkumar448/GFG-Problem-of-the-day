class Solution:
    def isSubsetSum(self, arr, target_sum):
        n = len(arr)
        dp = [[False] * (target_sum + 1) for _ in range(n + 1)]

        # Base case: sum 0 is always possible
        for i in range(n + 1):
            dp[i][0] = True

        # Fill DP table
        for i in range(1, n + 1):
            for j in range(1, target_sum + 1):
                if arr[i - 1] > j:  # If element is greater than sum, cannot include
                    dp[i][j] = dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]

        return dp[n][target_sum]


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target_sum = int(input())

        ob = Solution()
        if ob.isSubsetSum(arr, target_sum):
            print("true")
        else:
            print("false")

        print("~")
