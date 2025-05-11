import heapq

def kth_largest(arr, k):
    n = len(arr)
    min_heap = []

    for i in range(n):
        total = 0
        for j in range(i, n):
            total += arr[j]
            if len(min_heap) < k:
                heapq.heappush(min_heap, total)
            elif total > min_heap[0]:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap, total)

    return min_heap[0]

# Example driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        k = int(input())
        print(kth_largest(arr, k))
        print("~")
