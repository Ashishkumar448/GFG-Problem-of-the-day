import heapq
import sys
input = sys.stdin.read

class Solution:
    def nearlySorted(self, arr, k):
        # Min-heap to keep track of the smallest elements
        min_heap = []
        
        # Insert first k+1 elements into the min-heap
        for i in range(min(k + 1, len(arr))):
            heapq.heappush(min_heap, arr[i])

        index = 0  # Index for placing elements in the sorted array
        for i in range(k + 1, len(arr)):
            # Extract the minimum element from the heap and place in sorted portion
            arr[index] = heapq.heappop(min_heap)
            index += 1
            # Add the next element from the array to the heap
            heapq.heappush(min_heap, arr[i])

        # Extract remaining elements from the heap and place them in the array
        while min_heap:
            arr[index] = heapq.heappop(min_heap)
            index += 1


# Driver code
if __name__ == "__main__":
    t = int(input())
    results = []
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        obj = Solution()
        obj.nearlySorted(arr, k)
        results.append(" ".join(map(str, arr)))
    
    # Print all results for the test cases
    print("\n".join(results))
