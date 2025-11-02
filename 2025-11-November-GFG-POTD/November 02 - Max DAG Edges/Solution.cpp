#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) adj[e[0]].push_back(e[1]);

        vector<int> indegree(V, 0);
        for (auto &e : edges) indegree[e[1]]++;

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<int> pos(V);
        for (int i = 0; i < V; i++)
            pos[topo[i]] = i;

        // Reachability matrix
        vector<vector<bool>> reachable(V, vector<bool>(V, false));
        for (int i = 0; i < V; i++)
            dfs(i, adj, reachable, i);

        // Count possible additional edges
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && pos[i] < pos[j] && !reachable[j][i] &&
                    find(adj[i].begin(), adj[i].end(), j) == adj[i].end()) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    void dfs(int src, vector<vector<int>>& adj, vector<vector<bool>>& reachable, int node) {
        for (int nei : adj[node]) {
            if (!reachable[src][nei]) {
                reachable[src][nei] = true;
                dfs(src, adj, reachable, nei);
            }
        }
    }
};
