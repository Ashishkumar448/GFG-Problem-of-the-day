#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent); // Path compression
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int parentU = find(u, parent);
            int parentV = find(v, parent);

            if (parentU == parentV)
                return true;

            parent[parentU] = parentV;
        }
        return false;
    }
};

// Example usage
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, vector<int>(2));
        for (int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}
