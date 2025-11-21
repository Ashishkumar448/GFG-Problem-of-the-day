#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int INF = INT_MAX;

    vector<int> dijkstra(int src, int V, vector<vector<pair<int,int>>>& adj) {
        vector<int> dist(V, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto& p : adj[u]) {
                int v = p.first, w = p.second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2];
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        vector<int> distA = dijkstra(a, V, adj);
        vector<int> distB = dijkstra(b, V, adj);

        long long ans = distA[b];   // no curved edge case

        // Try curved edges once
        for (auto &e : edges) {
            int x = e[0], y = e[1], w2 = e[3];

            if (distA[x] != INF && distB[y] != INF)
                ans = min(ans, (long long)distA[x] + w2 + distB[y]);

            if (distA[y] != INF && distB[x] != INF)
                ans = min(ans, (long long)distA[y] + w2 + distB[x]);
        }

        return ans >= INF ? -1 : (int)ans;
    }
};
