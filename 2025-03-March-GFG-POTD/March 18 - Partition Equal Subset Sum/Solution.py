class Solution:
    def equalPartition(self, arr):
        total_sum = sum(arr)

        # If total sum is odd, it's impossible to split into equal subsets
        if total_sum % 2 != 0:
            return False

        target = total_sum // 2
        n = len(arr)
        dp = [[False] * (target + 1) for _ in range(n + 1)]

        # Base case: sum 0 is always possible
        for i in range(n + 1):
            dp[i][0] = True

        # DP table filling
        for i in range(1, n + 1):
            for j in range(1, target + 1):
                if arr[i - 1] > j:  # If element is greater than sum, exclude it
                    dp[i][j] = dp[i - 1][j]
                else:
                    # Include or exclude the current element
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]

        return dp[n][target]


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print("true" if ob.equalPartition(arr) else "false")
        print("~")
