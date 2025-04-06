from collections import deque

class Solution:
    def topoSort(self, V, edges):
        result = []
        adj = [[] for _ in range(V)]

        # Build adjacency list
        for u, v in edges:
            adj[u].append(v)

        # Calculate in-degrees
        in_degree = [0] * V
        for u in range(V):
            for v in adj[u]:
                in_degree[v] += 1

        # Queue for nodes with 0 in-degree
        q = deque()
        for i in range(V):
            if in_degree[i] == 0:
                q.append(i)

        while q:
            node = q.popleft()
            result.append(node)
            for neighbor in adj[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)

        return result

# Usage Example
if __name__ == "__main__":
    V = 4
    E = 3
    edges = [[3, 0], [1, 0], [2, 0]]
    sol = Solution()
    res = sol.topoSort(V, edges)
    print(res)
