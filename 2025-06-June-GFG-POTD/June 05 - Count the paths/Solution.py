class Solution:
    def countPaths(self, edges, V, src, dest):
        from collections import defaultdict
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)

        memo = [-1] * V
        return self.dfs(src, dest, graph, memo)

    def dfs(self, node, dest, graph, memo):
        if node == dest:
            return 1
        if memo[node] != -1:
            return memo[node]

        total_paths = 0
        for neighbor in graph[node]:
            total_paths += self.dfs(neighbor, dest, graph, memo)

        memo[node] = total_paths
        return total_paths
