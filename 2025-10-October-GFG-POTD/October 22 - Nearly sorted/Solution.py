import heapq

class Solution:
    def nearlySorted(self, arr, k):
        # Create a min heap
        minHeap = []
        n = len(arr)
        index = 0

        # Step 1: Add first k+1 elements to heap
        for i in range(min(k + 1, n)):
            heapq.heappush(minHeap, arr[i])

        # Step 2: Process remaining elements
        for i in range(k + 1, n):
            arr[index] = heapq.heappop(minHeap)
            index += 1
            heapq.heappush(minHeap, arr[i])

        # Step 3: Extract remaining elements
        while minHeap:
            arr[index] = heapq.heappop(minHeap)
            index += 1
