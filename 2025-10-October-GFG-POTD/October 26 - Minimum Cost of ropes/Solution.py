import heapq

class Solution:
    @staticmethod
    def minCost(arr):
        if len(arr) <= 1:
            return 0

        heapq.heapify(arr)  # Convert list into min-heap
        total_cost = 0

        while len(arr) > 1:
            first = heapq.heappop(arr)
            second = heapq.heappop(arr)
            cost = first + second
            total_cost += cost
            heapq.heappush(arr, cost)

        return total_cost

# Example usage
arr = [4, 3, 2, 6]
print(Solution.minCost(arr))  # Output: 29
