#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycle
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> edges(E, vector<int>(3));
        for (int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (int val : res) {
            cout << val << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
