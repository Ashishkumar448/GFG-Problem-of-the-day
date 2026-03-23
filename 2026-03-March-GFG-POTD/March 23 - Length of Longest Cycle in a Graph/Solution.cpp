class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }

        vector<bool> visited(V, false);
        vector<int> timeVisited(V, 0);
        vector<int> visId(V, -1);

        int maxCycle = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;

            int curr = i;
            int time = 0;

            // Traverse path
            while (curr != -1 && !visited[curr]) {
                visited[curr] = true;
                timeVisited[curr] = time;
                visId[curr] = i;
                time++;
                curr = adj[curr];
            }

            // Check cycle in same traversal
            if (curr != -1 && visId[curr] == i) {
                int cycleLength = time - timeVisited[curr];
                maxCycle = max(maxCycle, cycleLength);
            }
        }

        return maxCycle;
    }
};
