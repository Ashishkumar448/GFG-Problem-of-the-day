class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0
        
        n = len(prices)
        left_profit = [0] * n
        right_profit = [0] * n
        
        # Left to right pass to find max profit for first transaction
        min_price = prices[0]
        for i in range(1, n):
            min_price = min(min_price, prices[i])
            left_profit[i] = max(left_profit[i - 1], prices[i] - min_price)
        
        # Right to left pass to find max profit for second transaction
        max_price = prices[-1]
        for i in range(n - 2, -1, -1):
            max_price = max(max_price, prices[i])
            right_profit[i] = max(right_profit[i + 1], max_price - prices[i])
        
        # Calculate the maximum combined profit
        max_profit = 0
        for i in range(n):
            max_profit = max(max_profit, left_profit[i] + right_profit[i])
        
        return max_profit

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        prices = list(map(int, input().split()))
        sol = Solution()
        print(sol.maxProfit(prices))
