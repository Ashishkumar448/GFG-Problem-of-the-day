from collections import deque

class Solution:
    def maxEdgesToAdd(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)

        indegree = [0] * V
        for _, v in edges:
            indegree[v] += 1

        # Topological Sort
        q = deque([i for i in range(V) if indegree[i] == 0])
        topo = []
        while q:
            u = q.popleft()
            topo.append(u)
            for v in adj[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        pos = [0] * V
        for i, node in enumerate(topo):
            pos[node] = i

        # Reachability matrix
        reachable = [[False] * V for _ in range(V)]
        for i in range(V):
            self.dfs(i, adj, reachable, i)

        # Count possible edges
        count = 0
        for i in range(V):
            for j in range(V):
                if (
                    i != j
                    and pos[i] < pos[j]
                    and not reachable[j][i]
                    and j not in adj[i]
                ):
                    count += 1

        return count

    def dfs(self, src, adj, reachable, node):
        for nei in adj[node]:
            if not reachable[src][nei]:
                reachable[src][nei] = True
                self.dfs(src, adj, reachable, nei)
