# { Driver Code Starts
class Solution:
    # Function to minimize the cost to reach the last index
    def minimizeCost(self, k, arr):
        n = len(arr)
        dp = [float('inf')] * n
        dp[0] = 0  # Starting point has 0 cost

        # Iterate through each index from 1 to n-1
        for i in range(1, n):
            # Check up to k steps back
            for j in range(1, k + 1):
                if i - j >= 0:
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]))

        return dp[n - 1]  # Return the cost to reach the last index


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().split()))
        sol = Solution()
        print(sol.minimizeCost(k, arr))
# } Driver Code Ends
