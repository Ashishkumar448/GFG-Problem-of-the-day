#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        // BFS from each node
        for (int start = 0; start < V; start++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        // Found a cycle
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     int V = 7;
//     vector<vector<int>> edges = {{0,5},{0,6},{5,1},
