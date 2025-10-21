from collections import Counter
import heapq

class Solution:
    def topKFreq(self, arr, k):
        # Step 1: Count frequencies
        freq = Counter(arr)
        
        # Step 2: Use heap with custom sort order
        # (-frequency, -number) makes it a max-heap by both frequency and number
        heap = [(-f, -num) for num, f in freq.items()]
        heapq.heapify(heap)
        
        # Step 3: Extract top k elements
        result = []
        for _ in range(k):
            f, num = heapq.heappop(heap)
            result.append(-num)
        
        return result
