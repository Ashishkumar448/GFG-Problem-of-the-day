class Solution {
    public int minCost(String s, String t, char[][] transform, int[] cost) {

        int n = s.length();
        // Graph of 26x26, initialize with large values
        long[][] dist = new long[26][26];
        long INF = (long)1e15;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }

        // Fill edges
        for (int i = 0; i < transform.length; i++) {
            int x = transform[i][0] - 'a';
            int y = transform[i][1] - 'a';
            dist[x][y] = Math.min(dist[x][y], cost[i]);
        }

        // Floyd–Warshall to compute shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long answer = 0;

        // Try to match each character
        for (int i = 0; i < n; i++) {
            int a = s.charAt(i) - 'a';
            int b = t.charAt(i) - 'a';

            if (a == b) continue; // already equal

            long best = INF;

            // Try converting both to some character c
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = Math.min(best, dist[a][c] + dist[b][c]);
                }
            }

            if (best == INF) return -1; // impossible
            answer += best;
        }

        return (int)answer;
    }
}
