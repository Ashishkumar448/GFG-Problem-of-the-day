class Solution:
    def minCost(self, houses):
        n = len(houses)
        visited = [False] * n
        min_cost = [float('inf')] * n
        min_cost[0] = 0

        total_cost = 0

        for _ in range(n):
            u = -1
            for j in range(n):
                if not visited[j] and (u == -1 or min_cost[j] < min_cost[u]):
                    u = j

            visited[u] = True
            total_cost += min_cost[u]

            for v in range(n):
                if not visited[v]:
                    dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1])
                    min_cost[v] = min(min_cost[v], dist)

        return total_cost

# Example usage
houses = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
sol = Solution()
print(sol.minCost(houses))  # Output: 105
