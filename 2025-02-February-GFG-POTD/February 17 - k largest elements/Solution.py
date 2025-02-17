import heapq

class Solution:
    def kLargest(self, arr, k):
        # Use a max heap by inverting values
        maxHeap = [-num for num in arr]
        heapq.heapify(maxHeap)

        result = []
        for _ in range(k):
            result.append(-heapq.heappop(maxHeap))
        return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())

        ob = Solution()
        ans = ob.kLargest(arr, k)

        print(*ans)
        print("~")
