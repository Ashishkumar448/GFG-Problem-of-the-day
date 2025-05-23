class Solution {
    static int noOfWays(int m, int n, int x) {
        // Create a 2D dp array
        int[][] dp = new int[n + 1][x + 1];

        // Base case: One way to get sum 0 with 0 dice
        dp[0][0] = 1;

        // Fill the dp table
        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= x; sum++) {
                dp[dice][sum] = 0;
                for (int face = 1; face <= m; face++) {
                    if (sum - face >= 0) {
                        dp[dice][sum] += dp[dice - 1][sum - face];
                    }
                }
            }
        }

        // Result is number of ways to get sum x with n dice
        return dp[n][x];
    }
};
