#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int c, int d) {
    vis[u] = true;
    for (int v : adj[u]) {
        if ((u == c && v == d) || (u == d && v == c)) continue; // skip the edge (c,d)
        if (!vis[v]) dfs(v, adj, vis, c, d);
    }
}

bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(V, false);
    dfs(c, adj, visited, c, d);

    return !visited[d];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, vector<int>(2));
        for (int i = 0; i < E; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }
        int c, d;
        cin >> c >> d;
        cout << (isBridge(V, edges, c, d) ? "true" : "false") << "\n";
        cout << "~\n";
    }
    return 0;
}
