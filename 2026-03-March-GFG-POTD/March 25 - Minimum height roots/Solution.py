from collections import deque

class Solution:
    def minHeightRoot(self, V, edges):
        result = []

        # Edge case
        if V == 1:
            return [0]

        # Step 1: Build graph
        adj = [[] for _ in range(V)]
        degree = [0] * V

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1

        # Step 2: Add initial leaves
        q = deque()
        for i in range(V):
            if degree[i] == 1:
                q.append(i)

        # Step 3: Trim leaves
        remaining_nodes = V

        while remaining_nodes > 2:
            size = len(q)
            remaining_nodes -= size

            for _ in range(size):
                node = q.popleft()

                for neighbor in adj[node]:
                    degree[neighbor] -= 1

                    if degree[neighbor] == 1:
                        q.append(neighbor)

        # Remaining nodes are centers
        return list(q)
