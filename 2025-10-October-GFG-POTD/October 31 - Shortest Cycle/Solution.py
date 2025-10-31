from collections import deque

class Solution:
    def shortCycle(self, V: int, edges: list[list[int]]) -> int:
        # Build adjacency list
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        ans = float('inf')

        # BFS from each node
        for start in range(V):
            dist = [-1] * V
            parent = [-1] * V
            q = deque([start])
            dist[start] = 0

            while q:
                u = q.popleft()
                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        parent[v] = u
                        q.append(v)
                    elif parent[u] != v:
                        # Found a cycle
                        ans = min(ans, dist[u] + dist[v] + 1)

        return -1 if ans == float('inf') else ans


# Example usage:
# sol = Solution()
# V = 7
# edges = [[0,5],[0,6],[5,1],[6,1],[6,2],[2,3],[3,4],[1,4]]
# print(sol.shortCycle(V, edges))  # Output: 4
