from collections import deque

class Solution:
    def shortestPath(self, edges, n, m, src):
        # Create an adjacency list for the graph
        adjList = [[] for _ in range(n)]
        for i in range(m):
            u, v = edges[i]
            adjList[u].append(v)
            adjList[v].append(u)  # Since the graph is undirected

        # Array to store the shortest path distances from src
        dist = [-1] * n  # Initialize all distances as -1 (unreachable)
        dist[src] = 0  # Distance to the source is 0

        # Queue for BFS
        queue = deque([src])

        # Perform BFS
        while queue:
            node = queue.popleft()

            for neighbor in adjList[node]:
                if dist[neighbor] == -1:  # If the neighbor hasn't been visited
                    dist[neighbor] = dist[node] + 1
                    queue.append(neighbor)

        return dist

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        edge = [list(map(int, input().split())) for _ in range(m)]
        src = int(input())
        obj = Solution()
        res = obj.shortestPath(edge, n, m, src)
        print(" ".join(map(str, res)))
