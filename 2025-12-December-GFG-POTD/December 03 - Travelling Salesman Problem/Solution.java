class Solution {
    public int tsp(int[][] cost) {
        int n = cost.length;
        if (n == 0) return 0;        // defensive: no cities (not expected by problem)
        if (n == 1) return cost[0][0]; // handle single-city case
        
        int N = 1 << n;
        int INF = Integer.MAX_VALUE / 2;
        int[][] dp = new int[N][n];
        for (int i = 0; i < N; i++) {
            java.util.Arrays.fill(dp[i], INF);
        }

        dp[1][0] = 0;  // start at city 0 (mask with only city 0 visited)

        for (int mask = 0; mask < N; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) != 0) {
                    int cur = dp[mask][u];
                    if (cur >= INF) continue; // skip unreachable states
                    for (int v = 0; v < n; v++) {
                        if ((mask & (1 << v)) == 0) {
                            int nextMask = mask | (1 << v);
                            dp[nextMask][v] = Math.min(dp[nextMask][v], cur + cost[u][v]);
                        }
                    }
                }
            }
        }

        int ans = INF;
        int full = N - 1;
        for (int i = 1; i < n; i++) {
            ans = Math.min(ans, dp[full][i] + cost[i][0]);
        }

        return ans;
    }
}
