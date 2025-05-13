class Solution:
    def nCr(self, n, r):
        if r > n:
            return 0
        if r == 0 or r == n:
            return 1

        dp = [0] * (r + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            for j in range(min(i, r), 0, -1):
                dp[j] = dp[j] + dp[j - 1]  # Use % MOD if needed

        return dp[r]

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, r = map(int, input().split())
        ob = Solution()
        print(ob.nCr(n, r))
        print("~")
