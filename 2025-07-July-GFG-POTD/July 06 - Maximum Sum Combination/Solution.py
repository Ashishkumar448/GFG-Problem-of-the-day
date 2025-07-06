import heapq

class Solution:
    def topKSumPairs(self, a, b, k):
        n = len(a)
        a.sort()
        b.sort()

        max_heap = []
        visited = set()

        i, j = n - 1, n - 1
        heapq.heappush(max_heap, (-(a[i] + b[j]), i, j))
        visited.add((i, j))

        result = []

        while k > 0 and max_heap:
            sum_neg, i, j = heapq.heappop(max_heap)
            result.append(-sum_neg)
            k -= 1

            if i - 1 >= 0 and (i - 1, j) not in visited:
                heapq.heappush(max_heap, (-(a[i - 1] + b[j]), i - 1, j))
                visited.add((i - 1, j))

            if j - 1 >= 0 and (i, j - 1) not in visited:
                heapq.heappush(max_heap, (-(a[i] + b[j - 1]), i, j - 1))
                visited.add((i, j - 1))

        return result
