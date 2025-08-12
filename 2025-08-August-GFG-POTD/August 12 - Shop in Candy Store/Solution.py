class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        n = len(prices)
        
        # Calculate min cost
        min_cost = 0
        i, j = 0, n - 1
        while i <= j:
            min_cost += prices[i]
            i += 1
            j -= k  # take k most expensive ones for free
        
        # Calculate max cost
        max_cost = 0
        i, j = 0, n - 1
        while i <= j:
            max_cost += prices[j]
            j -= 1
            i += k  # take k cheapest ones for free
        
        return [min_cost, max_cost]

# Example usage
sol = Solution()
print(sol.minMaxCandy([3, 2, 1, 4], 2))  # Output: [3, 7]
