class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        vector<int> result;

        // Edge case
        if (V == 1) {
            result.push_back(0);
            return result;
        }

        // Step 1: Build graph
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        // Step 2: Add initial leaves
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Step 3: Trim leaves
        int remainingNodes = V;

        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;

                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes are centers
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
