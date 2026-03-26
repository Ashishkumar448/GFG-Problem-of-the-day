import heapq

class Solution:
    MOD = int(1e9 + 7)

    def countPaths(self, V, edges):
        # Build adjacency list
        graph = [[] for _ in range(V)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))

        # Dijkstra arrays
        dist = [float('inf')] * V
        dist[0] = 0

        ways = [0] * V
        ways[0] = 1

        pq = [(0, 0)]  # (dist, node)

        while pq:
            d, node = heapq.heappop(pq)

            if d > dist[node]:
                continue

            for neigh, w in graph[node]:
                if d + w < dist[neigh]:
                    dist[neigh] = d + w
                    ways[neigh] = ways[node]
                    heapq.heappush(pq, (dist[neigh], neigh))
                elif d + w == dist[neigh]:
                    ways[neigh] = (ways[neigh] + ways[node]) % self.MOD

        return ways[V - 1] % self.MOD
