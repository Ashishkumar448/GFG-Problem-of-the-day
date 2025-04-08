def dfs(u, adj, vis, c, d):
    vis[u] = True
    for v in adj[u]:
        if (u == c and v == d) or (u == d and v == c):
            continue
        if not vis[v]:
            dfs(v, adj, vis, c, d)

def isBridge(V, edges, c, d):
    adj = [[] for _ in range(V)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = [False] * V
    dfs(c, adj, visited, c, d)
    return not visited[d]

# Driver code
t = int(input())
for _ in range(t):
    V = int(input())
    E = int(input())
    edges = []
    for _ in range(E):
        u, v = map(int, input().split())
        edges.append([u, v])
    c = int(input())
    d = int(input())
    print("true" if isBridge(V, edges, c, d) else "false")
    print("~")
