class Solution:
    def isCyclic(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)

        visited = [False] * V
        recStack = [False] * V

        def dfsCycle(node):
            visited[node] = True
            recStack[node] = True

            for neighbor in adj[node]:
                if not visited[neighbor]:
                    if dfsCycle(neighbor):
                        return True
                elif recStack[neighbor]:
                    return True

            recStack[node] = False
            return False

        for i in range(V):
            if not visited[i]:
                if dfsCycle(i):
                    return True
        return False

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V, E = map(int, input().split())
        edges = [list(map(int, input().split())) for _ in range(E)]
        obj = Solution()
        print("true" if obj.isCyclic(V, edges) else "false")
