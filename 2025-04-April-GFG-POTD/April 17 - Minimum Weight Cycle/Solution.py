class Solution:
    def findMinCycle(self, V, edges):
        INF = int(1e9)
        minCycle = INF

        graph = [[INF] * V for _ in range(V)]
        for i in range(V):
            graph[i][i] = 0

        for u, v, w in edges:
            graph[u][v] = min(graph[u][v], w)

        for u, v, w in edges:
            original = graph[u][v]
            graph[u][v] = INF

            dist = [row[:] for row in graph]
            for k in range(V):
                for i in range(V):
                    for j in range(V):
                        if dist[i][k] < INF and dist[k][j] < INF:
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

            if dist[u][v] < INF:
                minCycle = min(minCycle, dist[u][v] + w)

            graph[u][v] = original

        return -1 if minCycle == INF else minCycle


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V = int(input())
        E = int(input())
        edges = []
        for _ in range(E):
            u, v, w = map(int, input().split())
            edges.append([u, v, w])
            edges.append([v, u, w])
        sol = Solution()
        print(sol.findMinCycle(V, edges))
