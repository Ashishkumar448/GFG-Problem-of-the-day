import heapq

class Solution:
    def kClosest(self, points, k):
        # Max heap to store (-distance, index)
        maxHeap = []

        for i, (x, y) in enumerate(points):
            dist = x * x + y * y
            heapq.heappush(maxHeap, (-dist, i))  # negate distance for max-heap
            if len(maxHeap) > k:
                heapq.heappop(maxHeap)  # remove farthest point

        # Collect k closest points
        result = []
        while maxHeap:
            _, idx = heapq.heappop(maxHeap)
            result.append(points[idx])

        return result
