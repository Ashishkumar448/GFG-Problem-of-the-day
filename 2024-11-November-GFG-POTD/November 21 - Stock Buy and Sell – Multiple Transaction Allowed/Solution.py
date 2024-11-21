class Solution:
    def maximumProfit(self, prices):
        n = len(prices)
        profit = 0

        # Traverse the prices array
        for i in range(1, n):
            # If the current price is greater than the previous price, add the difference to profit
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]

        return profit


if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        prices = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.maximumProfit(prices)
        print(res)
