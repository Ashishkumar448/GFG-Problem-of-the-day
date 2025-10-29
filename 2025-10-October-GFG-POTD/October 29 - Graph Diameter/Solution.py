from collections import deque, defaultdict

class Solution:
    def diameter(self, V, edges):
        # Step 1: Build adjacency list
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Step 2: First BFS from any node (say 0)
        farthestNode, _ = self.bfs(0, adj, V)

        # Step 3: Second BFS from farthestNode to find the diameter
        _, diameter = self.bfs(farthestNode, adj, V)

        return diameter

    # BFS that returns (farthestNode, distance)
    def bfs(self, start, adj, V):
        visited = [False] * V
        q = deque([(start, 0)])
        visited[start] = True

        farthestNode, maxDist = start, 0

        while q:
            node, dist = q.popleft()
            if dist > maxDist:
                maxDist = dist
                farthestNode = node
            for nei in adj[node]:
                if not visited[nei]:
                    visited[nei] = True
                    q.append((nei, dist + 1))

        return farthestNode, maxDist
