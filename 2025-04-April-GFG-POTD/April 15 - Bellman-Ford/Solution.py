class Solution:
    def bellmanFord(self, V, edges, src):
        dist = [int(1e8)] * V
        dist[src] = 0

        # Relax all edges V - 1 times
        for _ in range(V - 1):
            for u, v, w in edges:
                if dist[u] != int(1e8) and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        # Check for negative weight cycle
        for u, v, w in edges:
            if dist[u] != int(1e8) and dist[u] + w < dist[v]:
                return [-1]

        return dist

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V = int(input())
        E = int(input())
        edges = [list(map(int, input().split())) for _ in range(E)]
        src = int(input())

        obj = Solution()
        ans = obj.bellmanFord(V, edges, src)
        print(" ".join(map(str, ans)))
        print("~")
