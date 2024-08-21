#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
        // Create an adjacency list for the graph
        vector<vector<int>> adjList(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Since the graph is undirected
        }

        // Array to store the shortest path distances from src
        vector<int> dist(n, -1);  // Initialize all distances as -1 (unreachable)
        dist[src] = 0;  // Distance to the source is 0

        // Queue for BFS
        queue<int> q;
        q.push(src);

        // Perform BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjList[node]) {
                if (dist[neighbor] == -1) {  // If the neighbor hasn't been visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edge(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> edge[i][0] >> edge[i][1];
        }
        int src;
        cin >> src;
        Solution obj;
        vector<int> res = obj.shortestPath(edge, n, m, src);
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
