class Solution:
    def maximizeCuts(self, n, x, y, z):
        # Creating a dp array with size n+1 and initializing with -1
        dp = [-1] * (n + 1)
        
        # Base case: 0 length segment can have 0 cuts
        dp[0] = 0
        
        # Filling the dp array
        for i in range(1, n + 1):
            if i >= x and dp[i - x] != -1:
                dp[i] = max(dp[i], dp[i - x] + 1)
            if i >= y and dp[i - y] != -1:
                dp[i] = max(dp[i], dp[i - y] + 1)
            if i >= z and dp[i - z] != -1:
                dp[i] = max(dp[i], dp[i - z] + 1)
        
        # If dp[n] is still -1, no cuts could be made, so return 0
        return dp[n] if dp[n] != -1 else 0

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        x, y, z = map(int, input().split())
        obj = Solution()
        print(obj.maximizeCuts(n, x, y, z))
