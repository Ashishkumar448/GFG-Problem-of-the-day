from collections import deque

class Solution:
    def bfs(self, adj):
        result = []
        queue = deque([0])  # Start from node 0
        visited = [False] * len(adj)
        visited[0] = True

        while queue:
            node = queue.popleft()
            result.append(node)

            for neighbor in adj[node]:
                if not visited[neighbor]:
                    queue.append(neighbor)
                    visited[neighbor] = True
        
        return result
