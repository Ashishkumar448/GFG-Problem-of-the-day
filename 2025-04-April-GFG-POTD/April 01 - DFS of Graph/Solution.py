class Solution:
    def dfsHelper(self, node, adj, visited, result):
        visited[node] = True
        result.append(node)

        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfsHelper(neighbor, adj, visited, result)

    def dfs(self, adj):
        V = len(adj)
        result = []
        visited = [False] * V
        self.dfsHelper(0, adj, visited, result)
        return result


if __name__ == "__main__":
    tc = int(input().strip())

    for _ in range(tc):
        V = int(input().strip())
        adj = []

        for _ in range(V):
            line = input().strip()
            adj.append(list(map(int, line.split())) if line else [])

        obj = Solution()
        ans = obj.dfs(adj)
        print(*ans)
        print("~")
