class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(V, LLONG_MAX);
        vector<long long> ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;

        using P = pair<long long,int>;  // {dist, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &nbr : graph[node]) {
                int nei = nbr.first;
                long long w = nbr.second;

                if (d + w < dist[nei]) {
                    dist[nei] = d + w;
                    ways[nei] = ways[node];
                    pq.push({dist[nei], nei});
                }
                else if (d + w == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};
