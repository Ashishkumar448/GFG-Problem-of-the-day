import heapq

class Solution:
    def printKClosest(self, arr, k, x):
        max_heap = []

        for val in arr:
            if val == x:
                continue
            dist = abs(val - x)
            # Python's heapq is a min-heap, simulate max-heap with negative values
            heapq.heappush(max_heap, (-dist, val))
            if len(max_heap) > k:
                heapq.heappop(max_heap)

        result = [val for _, val in max_heap]

        # Sort by closeness, prefer larger if tie
        result.sort(key=lambda a: (abs(a - x), -a))
        return result
