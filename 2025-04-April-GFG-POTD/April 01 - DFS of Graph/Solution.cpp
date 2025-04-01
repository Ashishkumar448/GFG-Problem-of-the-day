#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V, false);
        dfsHelper(0, adj, visited, result);
        return result;
    }
};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int V;
        cin >> V;
        vector<vector<int>> adj(V);

        cin.ignore();
        for (int i = 0; i < V; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int val;
            while (ss >> val) {
                adj[i].push_back(val);
            }
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl << "~" << endl;
    }
    return 0;
}
