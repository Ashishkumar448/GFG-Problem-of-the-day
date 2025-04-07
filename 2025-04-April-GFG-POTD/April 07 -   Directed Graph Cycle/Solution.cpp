#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfsCycle(int node, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& adj) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, visited, recStack, adj)) return true;
            } else if (recStack[neighbor]) {
                return true; // Cycle detected
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false), recStack(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfsCycle(i, visited, recStack, adj)) return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, vector<int>(2));
        for (int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        Solution obj;
        cout << (obj.isCyclic(V, edges) ? "true" : "false") << endl;
    }
    return 0;
}
