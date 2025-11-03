from collections import deque, defaultdict

class Solution:
    def safeNodes(self, V: int, edges: list[list[int]]) -> list[int]:
        reverse_graph = defaultdict(list)
        outdegree = [0] * V

        # Build reverse graph and count outdegree
        for u, v in edges:
            reverse_graph[v].append(u)
            outdegree[u] += 1

        q = deque()
        safe = []

        # Start with terminal nodes (outdegree = 0)
        for i in range(V):
            if outdegree[i] == 0:
                q.append(i)

        # Kahn’s Algorithm
        while q:
            node = q.popleft()
            safe.append(node)
            for prev in reverse_graph[node]:
                outdegree[prev] -= 1
                if outdegree[prev] == 0:
                    q.append(prev)

        return sorted(safe)

# Example usage:
# sol = Solution()
# print(sol.safeNodes(5, [[1,0],[1,2],[1,3],[1,4],[2,3],[3,4]]))
