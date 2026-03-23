class Solution:
    def longestCycle(self, V, edges):
        adj = [-1] * V

        # Build graph
        for u, v in edges:
            adj[u] = v

        visited = [False] * V
        timeVisited = [0] * V
        visId = [-1] * V

        maxCycle = -1

        for i in range(V):
            if visited[i]:
                continue

            curr = i
            time = 0

            # Traverse path
            while curr != -1 and not visited[curr]:
                visited[curr] = True
                timeVisited[curr] = time
                visId[curr] = i
                time += 1
                curr = adj[curr]

            # Check cycle in same traversal
            if curr != -1 and visId[curr] == i:
                cycleLength = time - timeVisited[curr]
                maxCycle = max(maxCycle, cycleLength)

        return maxCycle
