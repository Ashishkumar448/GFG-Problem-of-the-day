# Python solution for K Closest Points to Origin
import heapq

def kClosest(points, k):
    maxHeap = []
    for (x, y) in points:
        dist = -(x*x + y*y)
        if len(maxHeap) < k:
            heapq.heappush(maxHeap, (dist, x, y))
        else:
            heapq.heappushpop(maxHeap, (dist, x, y))
    return [[x, y] for (dist, x, y) in maxHeap]

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k, n = map(int, input().split())
        points = [list(map(int, input().split())) for _ in range(n)]
        ans = kClosest(points, k)
        ans.sort()
        for p in ans:
            print(p[0], p[1])
        print("~")
