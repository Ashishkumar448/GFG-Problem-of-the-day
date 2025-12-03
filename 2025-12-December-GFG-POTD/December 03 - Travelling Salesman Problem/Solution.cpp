class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0][0];

        int N = 1 << n;
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(N, vector<int>(n, INF));

        dp[1][0] = 0;  // starting at city 0

        for (int mask = 0; mask < N; mask++) {
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u)) {
                    int cur = dp[mask][u];
                    if (cur >= INF) continue;
                    for (int v = 0; v < n; v++) {
                        if ((mask & (1 << v)) == 0) {
                            int nextMask = mask | (1 << v);
                            dp[nextMask][v] = min(dp[nextMask][v], cur + cost[u][v]);
                        }
                    }
                }
            }
        }

        int full = N - 1;
        int ans = INF;
        for (int i = 1; i < n; i++) {
            ans = min(ans, dp[full][i] + cost[i][0]);
        }
        return ans;
    }
};
