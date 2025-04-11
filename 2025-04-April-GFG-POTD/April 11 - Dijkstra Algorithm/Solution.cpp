#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

// Example usage:
int main() {
    int V = 3;
    vector<vector<int>> edges = {{0,1,1}, {1,2,3}, {0,2,6}, {1,0,1}, {2,1,3}, {2,0,6}};
    int src = 2;
    
    Solution obj;
    vector<int> result = obj.dijkstra(V, edges, src);
    
    for (int x : result) cout << x << " ";
    cout << endl;
}
