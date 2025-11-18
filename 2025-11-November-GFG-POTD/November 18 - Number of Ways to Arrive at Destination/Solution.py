import heapq

class Solution:
    MOD = 10**9 + 7

    def countPaths(self, V, edges):
        graph = [[] for _ in range(V)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))

        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1

        pq = [(0, 0)]  # (dist, node)

        while pq:
            d, node = heapq.heappop(pq)

            if d > dist[node]:
                continue

            for nei, w in graph[node]:
                if d + w < dist[nei]:
                    dist[nei] = d + w
                    ways[nei] = ways[node]
                    heapq.heappush(pq, (dist[nei], nei))
                elif d + w == dist[nei]:
                    ways[nei] = (ways[nei] + ways[node]) % self.MOD

        return ways[V - 1] % self.MOD
