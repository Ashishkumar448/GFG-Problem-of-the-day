# Python program to check if strings can form a circle

from collections import defaultdict

class Solution:
    def isCircle(self, arr):
        # Create adjacency list
        adj = defaultdict(list)
        in_degree = [0] * 26
        out_degree = [0] * 26
        
        # Populate adjacency list and degree counts
        for s in arr:
            start = s[0]
            end = s[-1]
            adj[start].append(end)
            out_degree[ord(start) - ord('a')] += 1
            in_degree[ord(end) - ord('a')] += 1
        
        # Check if in-degree and out-degree of each node match
        for i in range(26):
            if in_degree[i] != out_degree[i]:
                return 0

        # Check if the graph is strongly connected
        if not self.isStronglyConnected(arr, adj):
            return 0
        
        return 1

    def isStronglyConnected(self, arr, adj):
        # Find the first character to start the DFS from
        start = arr[0][0]

        # Visited array for both directions
        visited = [False] * 26
        # Forward DFS
        self.dfs(start, adj, visited)
        
        # Check if all relevant nodes were visited
        for s in arr:
            if not visited[ord(s[0]) - ord('a')]:
                retur
