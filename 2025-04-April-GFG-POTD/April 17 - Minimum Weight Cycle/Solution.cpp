#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        int INF = 1e9;
        int minCycle = INF;

        vector<vector<int>> graph(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i)
            graph[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u][v] = min(graph[u][v], w);
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int original = graph[u][v];
            graph[u][v] = INF;

            vector<vector<int>> dist = graph;

            for (int k = 0; k < V; ++k)
                for (int i = 0; i < V; ++i)
                    for (int j = 0; j < V; ++j)
                        if (dist[i][k] < INF && dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            if (dist[u][v] < INF)
                minCycle = min(minCycle, dist[u][v] + w);

            graph[u][v] = original;
        }

        return minCycle == INF ? -1 : minCycle;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edgeList;
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edgeList.push_back({u, v, w});
            edgeList.push_back({v, u, w});
        }
        Solution obj;
        cout << obj.findMinCycle(V, edgeList) << endl;
    }
    return 0;
}
