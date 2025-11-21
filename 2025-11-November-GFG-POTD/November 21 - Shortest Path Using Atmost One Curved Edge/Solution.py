import heapq

class Solution:
    INF = 10**18

    def dijkstra(self, src, V, adj):
        dist = [self.INF] * V
        dist[src] = 0

        pq = [(0, src)]  # (distance, node)

        while pq:
            d, u = heapq.heappop(pq)

            if d != dist[u]:
                continue

            for v, w in adj[u]:
                if d + w < dist[v]:
                    dist[v] = d + w
                    heapq.heappush(pq, (dist[v], v))

        return dist

    def shortestPath(self, V, a, b, edges):
        adj = [[] for _ in range(V)]

        # Add straight edges
        for x, y, w1, w2 in edges:
            adj[x].append((y, w1))
            adj[y].append((x, w1))

        distA = self.dijkstra(a, V, adj)
        distB = self.dijkstra(b, V, adj)

        ans = distA[b]  # no curved edge

        # Try using curved edges once
        for x, y, w1, w2 in edges:
            # use curved x → y
            if distA[x] < self.INF and distB[y] < self.INF:
                ans = min(ans, distA[x] + w2 + distB[y])

            # use curved y → x
            if distA[y] < self.INF and distB[x] < self.INF:
                ans = min(ans, distA[y] + w2 + distB[x])

        return -1 if ans >= self.INF else ans
