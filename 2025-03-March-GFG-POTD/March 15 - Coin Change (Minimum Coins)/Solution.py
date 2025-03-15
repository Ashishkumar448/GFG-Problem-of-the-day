class Solution:
    def minCoins(self, coins, total):
        if total == 0:
            return 0
        
        dp = [total + 1] * (total + 1)
        dp[0] = 0
        
        for i in range(1, total + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        return -1 if dp[total] == total + 1 else dp[total]

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        coins = list(map(int, input().split()))
        total = int(input())
        obj = Solution()
        print(obj.minCoins(coins, total))
