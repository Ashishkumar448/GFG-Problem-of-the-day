#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        vector<int> result;
        queue<int> q;
        vector<bool> visited(adj.size(), false);

        q.push(0);  // Start from node 0
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return result;
    }
};
