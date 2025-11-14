class Solution {
    public static int mergeStones(int[] stones, int k) {
        int n = stones.length;
        
        // Feasibility condition
        if ((n - 1) % (k - 1) != 0) return -1;

        // Prefix sum for range sums
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        // dp[i][j][m] = min cost to merge stones i..j into m piles
        int[][][] dp = new int[n][n][k + 1];

        // Initialize dp with large values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int m = 1; m <= k; m++) {
                    dp[i][j][m] = Integer.MAX_VALUE / 2;
                }
            }
            dp[i][i][1] = 0; // one pile
        }

        // Length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                // Try to form m piles (2..k)
                for (int m = 2; m <= k; m++) {
                    // Cut at valid points (only at multiples of k-1)
                    for (int mid = i; mid < j; mid += (k - 1)) {
                        dp[i][j][m] = Math.min(dp[i][j][m],
                                dp[i][mid][1] + dp[mid + 1][j][m - 1]);
                    }
                }

                // If we can reduce k piles into 1 pile
                if (dp[i][j][k] < Integer.MAX_VALUE / 2) {
                    dp[i][j][1] = dp[i][j][k] + prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1][1];
    }
}
