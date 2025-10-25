import heapq

class Solution:
    def minOperations(self, arr):
        original_sum = sum(arr)
        target = original_sum / 2.0
        current_sum = original_sum

        # Convert to max heap by storing negative values
        pq = [-float(x) for x in arr]
        heapq.heapify(pq)

        operations = 0

        while current_sum > target:
            largest = -heapq.heappop(pq)
            half = largest / 2.0
            current_sum -= half
            heapq.heappush(pq, -half)
            operations += 1

        return operations
