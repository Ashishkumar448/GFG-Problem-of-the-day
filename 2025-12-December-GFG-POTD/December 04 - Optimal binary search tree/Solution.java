class Solution {
    public int minCost(int keys[], int freq[]) {
        int n = keys.length;
        int[][] dp = new int[n][n];

        // prefix frequency sum for fast sum calculation
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + freq[i];
        }

        // len = length of interval
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = Integer.MAX_VALUE;

                // cost of all frequencies in range [i, j]
                int sum = prefix[j + 1] - prefix[i];

                // try making every key between i and j root
                for (int r = i; r <= j; r++) {
                    int left = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;
                    dp[i][j] = Math.min(dp[i][j], left + right + sum);
                }
            }
        }

        return dp[0][n - 1];
    }
}
