class Solution {
public:
    int minCost(string s, string t, vector<vector<char>>& transform, vector<int>& cost) {

        int n = s.size();
        const long long INF = 1e15;

        // 26x26 distance matrix
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Fill edges
        for (int i = 0; i < transform.size(); i++) {
            int x = transform[i][0] - 'a';
            int y = transform[i][1] - 'a';
            dist[x][y] = min(dist[x][y], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if (a == b) continue;

            long long best = INF;

            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }

            if (best == INF) return -1;
            answer += best;
        }

        return (int)answer;
    }
};
