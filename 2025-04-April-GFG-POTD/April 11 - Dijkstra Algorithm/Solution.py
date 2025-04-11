import heapq

class Solution:
    def dijkstra(self, V, edges, src):
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))

        dist = [float('inf')] * V
        dist[src] = 0

        pq = [(0, src)]  # (distance, node)

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue

            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))

        return dist

# Example usage:
V = 3
edges = [[0, 1, 1], [1, 2, 3], [0, 2, 6], [1, 0, 1], [2, 1, 3], [2, 0, 6]]
src = 2

sol = Solution()
print(sol.dijkstra(V, edges, src))  # Output: [4, 3, 0]
