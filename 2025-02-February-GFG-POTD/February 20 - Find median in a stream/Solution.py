import heapq
import sys

class Solution:
    def getMedian(self, arr):
        medians = []
        maxHeap = []  # Left half (max heap, simulated using negation)
        minHeap = []  # Right half (min heap)

        for num in arr:
            if not maxHeap or num <= -maxHeap[0]:
                heapq.heappush(maxHeap, -num)
            else:
                heapq.heappush(minHeap, num)

            # Balance the heaps
            if len(maxHeap) > len(minHeap) + 1:
                heapq.heappush(minHeap, -heapq.heappop(maxHeap))
            elif len(minHeap) > len(maxHeap):
                heapq.heappush(maxHeap, -heapq.heappop(minHeap))

            # Find median
            if len(maxHeap) == len(minHeap):
                medians.append((-maxHeap[0] + minHeap[0]) / 2.0)
            else:
                medians.append(-maxHeap[0])

        return medians

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getMedian(arr)
        print(" ".join(f"{x:.1f}" for x in ans))
        print("~")
