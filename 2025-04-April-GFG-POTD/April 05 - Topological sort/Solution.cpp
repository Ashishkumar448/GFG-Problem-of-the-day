#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> result;
        vector<vector<int>> adj(V);
        
        // Build adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // Calculate in-degrees
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }
        
        // Queue for nodes with 0 in-degree
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return result;
    }
};

// Usage Example
int main() {
    int V = 4, E = 3;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    Solution obj;
    vector<int> result = obj.topoSort(V, edges);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
