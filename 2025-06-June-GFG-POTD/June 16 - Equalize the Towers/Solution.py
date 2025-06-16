class Solution:
    def minCost(self, heights, cost):
        n = len(heights)
        towers = list(zip(heights, cost))
        towers.sort()

        sorted_heights = [h for h, _ in towers]
        sorted_cost = [c for _, c in towers]

        prefix_cost = [0] * n
        prefix_cost_height = [0] * n
        prefix_cost[0] = sorted_cost[0]
        prefix_cost_height[0] = sorted_cost[0] * sorted_heights[0]

        for i in range(1, n):
            prefix_cost[i] = prefix_cost[i - 1] + sorted_cost[i]
            prefix_cost_height[i] = prefix_cost_height[i - 1] + sorted_cost[i] * sorted_heights[i]

        suffix_cost = [0] * n
        suffix_cost_height = [0] * n
        suffix_cost[n - 1] = sorted_cost[n - 1]
        suffix_cost_height[n - 1] = sorted_cost[n - 1] * sorted_heights[n - 1]

        for i in range(n - 2, -1, -1):
            suffix_cost[i] = suffix_cost[i + 1] + sorted_cost[i]
            suffix_cost_height[i] = suffix_cost_height[i + 1] + sorted_cost[i] * sorted_heights[i]

        min_total_cost = float('inf')

        for i in range(n):
            cost_left = cost_right = 0
            target_height = sorted_heights[i]

            if i > 0:
                cost_left = target_height * prefix_cost[i - 1] - prefix_cost_height[i - 1]

            if i < n - 1:
                cost_right = suffix_cost_height[i + 1] - target_height * suffix_cost[i + 1]

            total_cost = cost_left + cost_right
            min_total_cost = min(min_total_cost, total_cost)

        return int(min_total_cost)
