class Solution:
    def maxProfit(self, arr, k):
        n = len(arr)
        if n == 0:
            return 0

        hold = -arr[0]  # Buying on day 0
        cash = 0        # No stock in hand

        for i in range(1, n):
            prev_cash = cash

            # Sell stock today
            cash = max(cash, hold + arr[i] - k)

            # Buy stock today
            hold = max(hold, prev_cash - arr[i])

        return cash
