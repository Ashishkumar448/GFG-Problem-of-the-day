#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 2: First BFS from any node (say 0)
        int farthestNode = bfs(0, adj, V).first;

        // Step 3: Second BFS from farthestNode to find the diameter
        int diameter = bfs(farthestNode, adj, V).second;

        return diameter;
    }

private:
    // BFS that returns {farthestNode, distance}
    pair<int, int> bfs(int start, vector<vector<int>>& adj, int V) {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q; // {node, distance}
        q.push({start, 0});
        visited[start] = true;

        int farthestNode = start, maxDist = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist > maxDist) {
                maxDist = dist;
                farthestNode = node;
            }
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, dist + 1});
                }
            }
        }
        return {farthestNode, maxDist};
    }
};
