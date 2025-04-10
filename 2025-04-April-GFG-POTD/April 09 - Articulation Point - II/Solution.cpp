#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer;
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,
             vector<bool>& visited, vector<bool>& isArticulation) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u, adj, tin, low, visited, isArticulation);
                low[u] = min(low[u], low[v]);

                if (low[v] >= tin[u] && parent != -1)
                    isArticulation[u] = true;

                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        vector<int> tin(V, -1), low(V, -1);
        vector<bool> visited(V, false), isArticulation(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, -1, adj, tin, low, visited, isArticulation);
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i])
                res.push_back(i);
        }

        if (res.empty()) res.push_back(-1);
        sort(res.begin(), res.end());
        return res;
    }
};

// Example usage:
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
    Solution obj;
    vector<int> result = obj.articulationPoints(V, edges);
    for (int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
