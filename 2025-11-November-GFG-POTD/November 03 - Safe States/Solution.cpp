#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> reverseGraph(V);
        vector<int> outdegree(V, 0);

        // Build reverse graph and count outdegree
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            reverseGraph[v].push_back(u);
            outdegree[u]++;
        }

        queue<int> q;
        vector<int> safe;

        // Start with terminal nodes (outdegree = 0)
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        // Kahn’s Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int prev : reverseGraph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     vector<vector<int>> edges = {{1,0},{1,2},{1,3},{1,4},{2,3},{3,4}};
//     vector<int> res = sol.safeNodes(5, edges);
//     for (int x : res) cout << x << " ";
// }
