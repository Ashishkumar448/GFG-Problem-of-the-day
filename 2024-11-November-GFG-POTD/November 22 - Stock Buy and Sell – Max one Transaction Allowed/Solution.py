# User function Template for Python
class Solution:
    def maximumProfit(self, prices):
        min_price = float('inf')  # Initialize to infinity for the minimum price
        max_profit = 0            # Initialize the maximum profit
        
        # Traverse the prices array
        for price in prices:
            if price < min_price:
                min_price = price  # Update minimum price
            else:
                # Calculate profit and update max_profit if current profit is greater
                max_profit = max(max_profit, price - min_price)
        
        return max_profit  # Return maximum profit (0 if no profitable transaction)

# Driver code to take input and test the function
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        prices = list(map(int, input().split()))
        obj = Solution()
        res = obj.maximumProfit(prices)
        print(res)
