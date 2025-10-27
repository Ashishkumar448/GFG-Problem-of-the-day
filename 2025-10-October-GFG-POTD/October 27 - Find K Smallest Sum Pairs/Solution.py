import heapq

class Solution:
    def kSmallestPair(self, arr1, arr2, k):
        result = []
        if not arr1 or not arr2 or k == 0:
            return result

        # Min-heap storing (sum, i, j)
        min_heap = []
        for i in range(min(len(arr1), k)):
            heapq.heappush(min_heap, (arr1[i] + arr2[0], i, 0))

        # Extract k smallest pairs
        while k > 0 and min_heap:
            total, i, j = heapq.heappop(min_heap)
            result.append([arr1[i], arr2[j]])

            if j + 1 < len(arr2):
                heapq.heappush(min_heap, (arr1[i] + arr2[j + 1], i, j + 1))

            k -= 1

        return result
