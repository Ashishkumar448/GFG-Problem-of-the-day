class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> graph(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Dijkstra arrays
        vector<long long> dist(V, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(V, 0);
        ways[0] = 1;

        // Min heap: {dist, node}
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &[neigh, w] : graph[node]) {
                if (d + w < dist[neigh]) {
                    dist[neigh] = d + w;
                    ways[neigh] = ways[node];
                    pq.push({dist[neigh], neigh});
                } 
                else if (d + w == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};
