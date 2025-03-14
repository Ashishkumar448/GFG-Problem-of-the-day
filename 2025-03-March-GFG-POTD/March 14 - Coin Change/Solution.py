class Solution:
    def count(self, coins, sum):
        n = len(coins)
        dp = [0] * (sum + 1)
        
        # Base case: There is one way to make sum 0, by choosing no coins
        dp[0] = 1
        
        # Process each coin one by one
        for coin in coins:
            for j in range(coin, sum + 1):
                dp[j] += dp[j - coin]
        
        return dp[sum]

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        coins = list(map(int, input().split()))
        sum_value = int(input())
        ob = Solution()
        print(ob.count(coins, sum_value))
        print("~")
