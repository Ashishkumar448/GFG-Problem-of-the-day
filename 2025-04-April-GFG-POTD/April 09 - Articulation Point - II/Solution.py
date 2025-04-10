class Solution:
    def __init__(self):
        self.timer = 0

    def articulationPoints(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        tin = [-1] * V
        low = [-1] * V
        visited = [False] * V
        is_articulation = [False] * V

        for i in range(V):
            if not visited[i]:
                self.dfs(i, -1, adj, tin, low, visited, is_articulation)

        res = [i for i, is_art in enumerate(is_articulation) if is_art]
        return res if res else [-1]

    def dfs(self, u, parent, adj, tin, low, visited, is_articulation):
        visited[u] = True
        tin[u] = low[u] = self.timer
        self.timer += 1
        children = 0

        for v in adj[u]:
            if v == parent:
                continue
            if not visited[v]:
                self.dfs(v, u, adj, tin, low, visited, is_articulation)
                low[u] = min(low[u], low[v])
                if low[v] >= tin[u] and parent != -1:
                    is_articulation[u] = True
                children += 1
            else:
                low[u] = min(low[u], tin[v])

        if parent == -1 and children > 1:
            is_articulation[u] = True

# Example usage
V = 5
edges = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]
obj = Solution()
print(obj.articulationPoints(V, edges))
