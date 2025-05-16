import heapq

class Node:
    def __init__(self, data, row, col):
        self.data = data
        self.row = row
        self.col = col

    def __lt__(self, other):
        return self.data < other.data  # Min-heap

def find_smallest_range(arr):
    k = len(arr)
    n = len(arr[0])
    heap = []
    max_val = float('-inf')

    for i in range(k):
        val = arr[i][0]
        heapq.heappush(heap, Node(val, i, 0))
        max_val = max(max_val, val)

    start, end = 0, float('inf')

    while True:
        curr = heapq.heappop(heap)
        min_val = curr.data

        if max_val - min_val < end - start:
            start, end = min_val, max_val

        if curr.col + 1 < n:
            next_val = arr[curr.row][curr.col + 1]
            heapq.heappush(heap, Node(next_val, curr.row, curr.col + 1))
            max_val = max(max_val, next_val)
        else:
            break

    return [start, end]

# Sample driver
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        k = int(input())
        arr = []
        for _ in range(k):
            arr.append(list(map(int, input().split())))
        result = find_smallest_range(arr)
        print(result[0], result[1])
        print("~")
